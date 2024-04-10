#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
 
using namespace std;

bool bilet(int* a, int n){
  if(a[0] == a[n]){
    return false;
  }
   for(int i =1; i<n; i++){
     if((a[i] < a[i+n] && a[i-1] < a[i - 1 + n]) || (a[i] > a[i+n] && a[i-1] > a[i - 1 + n])){   
     } else {
      return false;
     }
   }
   return true;
}
 
int main() {                          
  int n;
  int a[100000];
  scanf("%d", &n);
  string s;
  cin >> s;
  for(int i =0; i<2 * n; i++){
     a[i] = s[i] - '0';
  }
  sort(a, a+n);
  sort(a+n, a + 2 * n);
  if(bilet(a, n)){
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}