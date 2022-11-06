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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int mod = 1e9+7;

int modpow(int x, int y, int mod) {
  int ret = 1 % mod, x2p = x;
  while (y > 0) {
    if (y%2) ret = (lint)ret * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return ret;
}

int inv(int a, int p) { return modpow(a, p-2, p); }

int main() {
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);

  vector<pair<int, int>> points;
  for (int i = 0; i < n; ++i) {
    int y, x;
    scanf("%d %d", &y, &x), --y, --x;
    points.push_back(make_pair(y, x));
  }
  sort(points.begin(), points.end());

  int result = 0;

  if (find(points.begin(), points.end(), make_pair(h-1, w-1)) != points.end()) result = 0;
  else {
    ++n;
    points.push_back(make_pair(h-1, w-1));

    const int maxval = h-1+w-1;
    vector<int> fact(maxval+1), invfact(maxval+1);

    fact[0] = 1;
    for (int i = 1; i <= maxval; ++i) fact[i] = (lint)i * fact[i-1] % mod;
    invfact[maxval] = inv(fact[maxval], mod);
    for (int i = maxval-1; i >= 0; --i) invfact[i] = (lint)(i+1) * invfact[i+1] % mod;

    auto binom = [&fact, &invfact](int a, int b) -> lint {
      if (b < 0 || b > a) return 0;
      return (lint)fact[a] * invfact[b] % mod * invfact[a-b] % mod;
    };

    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      int y, x;
      tie(y, x) = points[i];

      dp[i] = binom(y+x, y);
      for (int j = 0; j < i; ++j) {
	int y2, x2;
	tie(y2, x2) = points[j];
	if (y2 <= y && x2 <= x)
	  dp[i] = (dp[i] - (lint)dp[j] * binom(y-y2 + x-x2, y-y2) % mod + mod) % mod;
      }

    }

    result = dp[n-1];
  }

  printf("%d\n", result);

  return 0;
}