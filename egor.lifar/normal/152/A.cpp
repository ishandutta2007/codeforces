

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
   string s[100];
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++ ){
      cin >> s[i];
   }
   bool b[100];
   for(int i = 0; i<100; i++) {
      b[i] = false;
   }
   for(int i = 0; i<m; i++) {
       char c;
       c = '0';
       for(int j = 0; j<n; j++) {
          c = max(c, s[j][i]);
       }
       for(int j = 0; j<n; j++) {
          if(s[j][i] == c) {
            b[j] = true;
          }
       }
   }
   int k = 0;
   for(int i = 0; i<n; i++) {
      if(b[i]) {
         k++;
      }
   }
   printf("%d", k);

}