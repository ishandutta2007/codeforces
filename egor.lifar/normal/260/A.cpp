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
  int b, n;
  string a;
  cin  >> a;
  int p = a.size();
  scanf("%d %d", &b, &n);
  int k = 0;
  int l = 0;
  int t = 1;
  for(int i = p-1; i>= 0; i--){
    l += (a[i] - '0') * t;
    t *= 10;
  }
  l = l % b;
  while(k < n){
    bool j = true;;
    for(int i =0; i<10; i++){
      if((l * 10 + i) % b == 0){
        l = (l * 10 + i) % b;
        p++;
        j = false;
        a.push_back(i  + '0');
        k++;
        break;
      }
    }
    if(j){
      break;
    }  
  }
  if(k < n){
    printf("-1\n");
  } else {
    for(int i =0; i<p; i++){
      printf("%c", a[i]);
    }
  }
  return 0;
}