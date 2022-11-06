#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  if (a < b) printf("-1\n");
  else {
    int k0;
    double x0;
    if (a == b) {
      k0 = 0;
      x0 = a;
    } else {
      k0 = (a-b)/(2*b);
      if (k0 == 0) x0 = 1e14;
      else x0 = (a-b)/(2.*k0);
    }
    int k1 = (a+b)/(2*b) - 1;
    double x1 = (a+b)/(2.*(k1+1));
    printf("%.9lf\n", min(x0, x1));
  }

  return 0;
}