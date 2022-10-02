

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
    scanf("%d", &n);
    int a[1000];
    for(int i =0; i<n; i++) {
      int d, b, c;
      scanf("%d %d %d", &d, &b, &c);
      a[i] = d + b + c;
    }
    int k =0;
    for(int i = 0; i<n; i++) {
      if(a[i] > 1) {
        k++;
      }
    }
    printf("%d", k);
    return 0;
}