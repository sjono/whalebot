/*
Date: 09/27/15
Author: Jono
Goal: control whale robot using a nintendo controller
*/

#include "NESpad.h" //Found at https://code.google.com/p/nespad/

int clock = 4; // set the clock pin D4
int latch = 3; // set the latch pin D3
int datin = 2;// set the data in pin D2
int Rd = 6; // Right direction is D7
int Re = 7; // Right enable is D8
int Le = 8; // Left enable is D9
int Ld = 9; // Left direction is D10

NESpad nintendo = NESpad(3,4,2); // Set pin numbers strobe (3), clock(4), data (2)
byte controller_data = 0;

void setup() {
  Serial.begin(9600);

  pinMode(Rd,OUTPUT);
  pinMode(Re,OUTPUT);
  pinMode(Ld,OUTPUT);
  pinMode(Le,OUTPUT);

  pause();
}

void loop() {
  controller_data = nintendo.buttons();
  check();
  pause();
}

void pause(void) {
    digitalWrite(Re,LOW);
    digitalWrite(Le,LOW);
    digitalWrite(Rd,LOW);
    digitalWrite(Ld,LOW);
}
 

void check(void) {
  if (controller_data & NES_UP){
    digitalWrite(Re,HIGH);
    digitalWrite(Le,HIGH);
    digitalWrite(Rd,LOW);
    digitalWrite(Ld,HIGH);
    Serial.println("NES UP!");
    }
  if (controller_data & NES_DOWN){
    digitalWrite(Re,HIGH);
    digitalWrite(Le,HIGH);
    digitalWrite(Rd,HIGH);
    digitalWrite(Ld,LOW);
    Serial.println("NES DOWN!");
    }
  if (controller_data & NES_LEFT){
    digitalWrite(Re,HIGH);
    digitalWrite(Le,HIGH);
    digitalWrite(Rd,LOW);
    digitalWrite(Ld,LOW);
    Serial.println("NES LEFT!");
   }
  if (controller_data & NES_RIGHT){
    digitalWrite(Re,HIGH);
    digitalWrite(Le,HIGH);
    digitalWrite(Rd,HIGH);
    digitalWrite(Ld,HIGH);
    Serial.println("NES RIGHT!");
  }
  delay(100);
}

