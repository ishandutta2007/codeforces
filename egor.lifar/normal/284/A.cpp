

#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int tchshka(int x, int p){
  int k = x;
  for(int i = 1; i<=p-2; i++) {
      if(k % p == 1) {
        return false;
      }
      k = (k * x) % p;
  }
  if(k % p != 1){
    return false;
  }
   return true;
}

int main() {                               
   int p;
   scanf("%d", &p);
   int k =0;
   for(int x = 1; x<p; x++) {
    if(tchshka(x, p)) {
      k++;
    }
   }
   printf("%d", k);
    return 0;
}