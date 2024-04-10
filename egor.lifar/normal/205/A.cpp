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
  int n;
  int a[100000];
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    scanf("%d", &a[i]);
  }
  int k = 1000000001;
  for(int i =0; i<n; i++) {
    k =  min(k, a[i]);
  }
  int l = 0;
  for(int i =0; i<n; i++){
     if(a[i] == k) {
      l++;
     }
  }
  if(l>1) {
    printf("Still Rozdil");
    return 0;
  }
   for(int i =0; i<n; i++){
     if(a[i] == k) {
       printf("%d\n", i+1);
       break;
     }
  }
  return 0;
}