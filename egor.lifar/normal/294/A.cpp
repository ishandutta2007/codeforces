#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// bool simmetrichna(int* a, int k) {
//     for(int i =0; i<k / 2 - 1; i++) {
//        if(a[i] != a[k-i - 1]) {
//          return false;
//        }
//     }
//     return true;

// }


int main() {
   // int n, k, a[100000];
   // scanf("%d", &n);
   // for(int i =0; i<n; i++) {
   //      scanf("%d", &a[i]);
   // }
   // for(int i=n; i<n*2-1; i++) {
   //      a[i] = a[i-n];     
   // }
   // k = n;
   // if(simmetrichna(a, n)) {
   //    printf("0\n");
   //    return 0;
   // }

    

   // n = n*2-1;  
   // int b[200000];
   // for(int  i = 0; i<n / 2+1; i++) {
   //    int t = 0;
   //    for(int j = 0; j<n / 2; j++) {
   //       if( t == n / 2 + n%2 + 1) {
   //           t++;
   //       }
   //       b[t] = a[t];
   //       t++;
   //    }
   //    t = 0;
   //    if(simmetrichna(b, n)) {
   //        n--;
   //        k--;
   //       for(int j = 0; j<n / 2; j++) {
   //         if( t == n / 2 + n%2 + 1) {
   //            t++;
   //         }
   //         a[t] = b[t];
   //         t++;
   //       }
   //    }
       
   // }


   // printf("%d\n", k);
   // for(int i =n /2 + n%2 + 1; i<n; i++ ) {
   //     printf("%d ", b[i]);
   // }
  int n, a[102], m, x[102], y[102];
  scanf("%d", &n);
  for(int  i = 1; i<=n; i++) {
    scanf("%d", &a[i]);
  }
  a[n+1] = 0;
  a[0] = 0;
  scanf("%d", &m);
  for(int  i = 1; i<=m; i++) {
     scanf("%d %d", &x[i], &y[i]);
     a[x[i] - 1] += y[i] - 1;
     a[x[i] +1] +=a[x[i]] - y[i];
      a[x[i]] = 0;
  }
  for(int i = 1; i<=n; i++){
    printf("%d\n", a[i]);
  }
}