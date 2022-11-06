#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, a, b, c, d;
  scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

  lint result = 0;

  for (int x0 = 1; x0 <= n; ++x0) {
    int x1 = x0+b-c;
    int x2 = x1+a-d;
    int x3 = x2+c-b;
    if (min({x0, x1, x2, x3}) >= 1 && max({x0, x1, x2, x3}) <= n)
      result += n;
  }

  printf("%lld\n", result);

  return 0;
}