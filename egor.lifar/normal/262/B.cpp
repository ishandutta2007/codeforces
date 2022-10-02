

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
    int n, k, a[100000];
    scanf("%d %d", &n, &k);
    for(int i = 0; i<n; i++) {
      scanf("%d", &a[i]);
    }
    int i =0;
    while(k > 0 && i<n && a[i] < 0) {
         k--;
         a[i] = a[i] * (-1);
         i++;
    }
    k = k%2;
    if(k == 1) {
      int m = 100000;
      for(int i =0; i<n; i++) {
        m = min(m, abs(a[i]));
      }
      for(int i =0; i<n; i++) {
        if(a[i] == m) {
          a[i] = a[i] * (-1);
          break;
        }
      } 
    }
    int s = 0;
    for(int i =0; i<n; i++) {
      s+=a[i];
    }
    printf("%d", s);
 
}