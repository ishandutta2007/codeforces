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
  lint sumv, xorv;
  scanf("%lld %lld", &sumv, &xorv);
  const int maxb = 40;
  vector<int> sums;
  const int mask = (1<<maxb/2)-1;
  for (int al = 0; al < 1<<maxb/2; ++al) {
    int bl = al ^ (mask & xorv);
    sums.push_back(al + bl);
  }
  sort(sums.begin(), sums.end());
  lint result = 0;
  for (int ah = 0; ah < 1<<(maxb+1)/2; ++ah) {
    int bh = ah ^ (xorv>>maxb/2);
    lint need = sumv - ((lint)(ah + bh) << maxb/2);
    if (0 <= need && need < (1LL<<30)) {
      result += (upper_bound(sums.begin(), sums.end(), (int)need) -
		 lower_bound(sums.begin(), sums.end(), (int)need));
    }
  }

  if (sumv == xorv) result -= 2;
  if (sumv == 0 && xorv == 0) ++result;

  printf("%lld\n", result);

  return 0;
}