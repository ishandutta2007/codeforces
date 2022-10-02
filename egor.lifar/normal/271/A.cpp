

#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool kraciv(int i) {
   int x[5];
   x[1] = i / 1000;
   x[2] = (i / 100) % 10;
   x[3] = (i / 10) % 10;
   x[4] = i % 10;
   for(int j= 1; j<4; j++) {
      for(int g = j+1; g<5; g++) {
         if(x[j] == x[g]){
            return false;
            break;
         }
      }
   }
   return true;
}

int main() {
   int y;
   scanf("%d", &y);
   int i = y+1;
   while(kraciv(i) == false){
      i++;
   } 
   printf("%d", i);
}