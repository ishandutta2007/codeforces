

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
   // int n, m, a[100001], v[100001], x[100001], y[100001], t[100001], q[100001], vv = 0, xx = 0, yy=0, qq = 0;
   // scanf("%d %d", &n, &m);
   // for(int i = 1; i<=n; i++){
   //    scanf("%d", &a[i]);
   // }
   // for(int i = 1; i<=m; i++) {
   //     scanf("%d", &t[i]);
   //     if(t[i] == 1) {
   //        scanf("%d %d", &v[vv], &x[xx]);
   //        a[v[vv]] = x[xx];
   //        vv++;
   //        xx++;
   //     } 
   //     if(t[i] == 2) {
   //        scanf("%d", &y[yy]);
   //        for(int i = 1; i<=n; i++) {
   //          a[i]+=y[yy];
   //        }
   //        yy++;
   //     } 
   //     if(t[i] == 3) {
   //       scanf("%d", &q[qq]);
   //       printf("%d\n", a[q[qq]]);
   //       qq++;
   //     }       
   // }
   int n, a[100], b[100], aa[100];
   scanf("%d", &n);
   for(int i = 0; i<n; i++) {
      aa[i] = 0;
      scanf("%d %d", &a[i], &b[i]);
   }
   for(int i = 0; i<n; i++) {
       for(int j =0; j<n; j++) {
          if(j != i && b[i] == a[j]) {
            aa[j] = 1;
          }
       }
   }
   int s = 0;
   for(int i = 0; i<n; i++){
    if(aa[i] == 0) {
      s++;
    }
   }
   printf("%d\n", s);

 }