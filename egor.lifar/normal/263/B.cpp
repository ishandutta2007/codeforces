

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
    int n, k, a[100];
    scanf("%d %d", &n, &k);
    for(int i = 0; i<n; i++) {
      scanf("%d", &a[i]);
    }
    if(k>n) {
      printf("-1\n");
      return 0;
    }
    sort(a, a+n);
    printf("%d %d", a[n - k], a[n - k]);
    return 0;
}