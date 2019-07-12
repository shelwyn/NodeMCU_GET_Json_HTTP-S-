#include <SoftwareSerial.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti WiFiMulti;
String URL, EmpID;

void setup() {
      Serial.begin(115200);
}

void loop() {
	WiFi.mode(WIFI_STA);
    WiFiMulti.addAP("WIFI_NAME", "WIFI_PASSWORD"); // Enter your WiFi name and Password here
    
    if ((WiFiMulti.run() == WL_CONNECTED)) {
        
            WiFiClient client;
            HTTPClient http;
            Serial.print("[HTTP] begin...\n");
            EmpID = "2";
            URL="https://www.apipie.co/employees/?id=" + EmpID;
            http.begin(client, URL);
            Serial.print("[HTTP] GET...\n");
            int httpCode = http.GET();
            if (httpCode > 0) {
              Serial.printf("[HTTP] GET... code: %d\n", httpCode);
              if (httpCode == HTTP_CODE_OK) {
              String payload = http.getString();
              Serial.println(payload);
            
              }
            }
            else {
              Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
            
            }
             http.end();
    }
 

}
