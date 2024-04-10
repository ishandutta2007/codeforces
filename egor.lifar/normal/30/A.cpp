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
  int a, b, n;
   scanf("%d %d %d", &a, &b, &n);
   int x = 0;
   int k = 0;
   int a2 = abs(a);
  int b2 = abs(b);
  if(a == 0  && b != 0){
    printf("No solution");
    return 0;
  }
  while(a2 * k < b2){
    x++;
    k = 1;
    for(int i =0; i<n; i++){
      k = k * x;
    }
  }
  if(a2 * k != b2) {
    printf("No solution");
    return 0;
  } else {
    if((a < 0 && b > 0) || (a > 0 && b < 0)) {
      printf("-");
    }
    printf("%d", x);
  }
  return 0;
}