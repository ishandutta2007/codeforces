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
typedef long double ldouble;

int main() {
  ldouble a, b, c, d;
  cin >> a >> b >> c >> d;

  ldouble l = 0, r = 1e9+1;
  for (int rep = 0; rep < 1000; ++rep) {
    double m = (l+r)/2;

    double la = a-m, ra = a+m;
    double lb = b-m, rb = b+m;
    double lc = c-m, rc = c+m;
    double ld = d-m, rd = d+m;

    double minad = min({la*ld, la*rd, ra*ld, ra*rd});
    double maxad = max({la*ld, la*rd, ra*ld, ra*rd});
    double minbc = min({lb*lc, lb*rc, rb*lc, rb*rc});
    double maxbc = max({lb*lc, lb*rc, rb*lc, rb*rc});
    if (maxad < minbc || minad > maxbc) l = m;
    else r = m;
  }

  printf("%.12f\n", (double)l);

  return 0;
}