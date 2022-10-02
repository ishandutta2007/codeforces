#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
 
using namespace std;


 
int main() {                          
  int h, d;
  scanf("%d:%d", &d, &h);
  int x[24], y[24];
  x[0] = 01; y[0] = 10;
  x[1] = 02; y[1] = 20;
  x[2] = 03; y[2] = 30;
  x[3] = 04; y[3] = 40;
  x[4] = 05; y[4] = 50;
  x[5] = 10; y[5] = 01;
  x[6] = 11; y[6] = 11;
  x[7] = 12; y[7] = 21;
  x[8] = 13; y[8] = 31;
  x[9] = 14; y[9] = 41;
  x[10] = 15; y[10] = 51;
  x[11] = 20; y[11] = 02;
  x[12] = 21; y[12] = 12;
  x[13] = 22; y[13] = 22;
  x[14] = 23; y[14] = 32;
  x[15] = 00; y[15] = 00;
  for(int i = 0; i<15; i++){
    if((x[i] == d  && y[i] > h) || (x[i] > d)) {
      if(i == 11 || i == 5){
       printf("%d:0%d", x[i],  y[i]);
      }else {
        if(i < 5){
          printf("0%d:%d", x[i],  y[i]);
        } else {
          printf("%d:%d", x[i],  y[i]);
        }
      }
      return 0;
    }
  }
  printf("0%d:0%d", x[15], y[15]);
  return 0;
}