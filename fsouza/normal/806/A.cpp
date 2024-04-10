#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    lint x, y, p, q;
    scanf("%lld %lld %lld %lld", &x, &y, &p, &q);

    lint l = 1, r = 1e9 + 1;
    while (l < r) {
      lint m = l + (r-l)/2;

      lint a = p * m, b = q * m;
      lint extra = b - y;

      if (y <= b && x <= a && x >= a - extra) r = m;
      else l = m + 1;
    }

    if (r == (lint)1e9 + 1) printf("-1\n");
    else printf("%lld\n", l * q - y);
  }

  return 0;
}