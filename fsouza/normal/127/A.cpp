#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

typedef complex<double> point;

int main() {
  int n, k;

  scanf("%d %d", &n, &k);

  double ret = 0.0;

  point last;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    point p(x, y);
    if (i > 0)
      ret += abs(p - last);
    last = p;
  }

  ret /= 50.0;
  ret *= k;

  printf("%.9f\n", ret);

  return 0;
}