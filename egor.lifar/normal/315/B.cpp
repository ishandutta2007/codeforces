

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
   int n, m, a[100001],  x;
   scanf("%d %d", &n, &m);
   x = 0;
   for(int i = 1; i<=n; i++){
      scanf("%d", &a[i]);
   }
   for(int i = 1; i<=m; i++) {
       int t;
       scanf("%d", &t);
       if(t == 3) {
         int b;
         scanf("%d", &b);
         printf("%d\n", a[b] + x);
        
       }    
       if(t == 1) {
         int b, c;
         scanf("%d %d", &b, &c);
         a[b] = (c - x);
         
       } 
       if(t == 2) {
          int b; 
          scanf("%d", &b);
          x+=b;
      
       }    
   }



 }