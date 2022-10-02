#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;



    int n, m, d, a[10000];
 int cr( int x) {
 int t = 0;
    for(int i =0; i<n*m; i++) {
        t+= abs(a[i] - x) / d;
    }
    return t;
}
  int main(){
    scanf("%d %d %d", &n, &m, &d);
    for(int i =0; i<n*m; i++) {
        scanf("%d", &a[i]);
    }
    int x = 0;
      for(int i =0; i<n*m; i++) {
        if(a[i] % d != a[0] % d) {
          printf("-1\n");
          return 0;
        }
      }
      sort(a, a+n*m);
      if(n*m % 2 == 1) {
         x = a[n*m / 2];
      } else {
           x = (a[n*m / 2 - 1] + a[n*m / 2 ]) /2;
      }
 

    int k =  ((a[0] - x) % d + d) % d;

    printf("%d\n", min(cr(x+k), cr(x-d + k)));
    return 0;            
 }