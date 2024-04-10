

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
   char s[100000];
   int a[100000], b[100000];
   int m;
   scanf("%s %d", &s, &m);
   int n = strlen(s);
   s[n] = 'a';
   for(int i= 0 ; i<n; i++){
      if(s[i] == s[i+1] ) {
        a[i] = 1;
      } else {
        a[i] = 0;
      }
   }
   b[0] = a[0];
   for(int i = 1 ; i<n; i++){
      b[i] = b[i-1] + a[i];
   }
   for(int i = 0; i<m; i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      l--;
      r--;
      int k = (b[r-1] - b[l-1]);
      
      printf("%d\n", k);
   }

 }