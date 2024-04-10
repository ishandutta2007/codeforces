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
  int x;
  scanf("%d", &x);
  int p = 1;
  while((p * (p + 1)) / 2 <= x){ 
    p++;  
  }
  p--;
  vector <int> b(p);
  for(int i = 1; i<=p; i++){
       b[i - 1] = (i * (i + 1)) / 2; 
  }
  for(int i = 0; i<p; i++){
    int x2 = x - b[i];
    int l = 0;
    int r = p - 1;
    while(l != r){          
      if(x2 > b[(l + r) / 2 + (l + r) % 2]){
        l = (l + r) / 2 + (r + l) % 2;
      } else {
        if(x2 < b[(l + r) / 2 + (l + r) % 2]){
          r = (l + r) / 2;
        } else {
          printf("YES\n");
          return 0;
        }
      }
    }
    if(b[l] == x2){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}