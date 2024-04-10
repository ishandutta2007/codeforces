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
  int a, b;
  scanf("%d %d", &a, &b);
  int k = a;
  bool g = false;
  while(g == false){
    k++;
    int t = 0;
    for(int i = 2; i<= sqrt(k); i++){
      if(k % i == 0){
        t++;
      }
    }
    if(t == 0){
      g = true;
    }
  }
  if(k == b){
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}