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
  int n, a[1000];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  int k = 0;
  for(int i = 1; i < n; i++){
       bool c = true;
       for(int j = 0 ;  j < i; j++){
         if((a[i] > a[0] && a[i] > a[j]) || (a[i] < a[0] && a[i] < a[j])){
         } else {
            c = false;
         }
       } 
       if(c){
        k++;
       }
  }
  printf("%d", k);
  return 0;
}