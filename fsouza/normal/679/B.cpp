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

template<typename T>
inline T pow3(T v) { return v * v * v; }

int main() {
  const int maxl = 28951026;
  vector<pair<int, int>> dp(maxl+1);

  dp[0] = make_pair(0, 0);

  int a1 = 1;
  for (int l = 1; l <= maxl; ++l) {
    dp[l] = dp[l-1];
    while (pow3(a1+1) <= l) ++a1;
    int l2 = min(pow3(a1+1) - 1, l) - pow3(a1);
    dp[l] = max(dp[l], make_pair(1 + dp[l2].first, pow3(a1) + dp[l2].second));
  }

  lint limit;
  scanf("%lld", &limit);

  pair<lint, lint> result = make_pair(-1LL, -1LL);

  for (lint a1 = 1; pow3(a1) <= limit; ++a1) {
    result = max(result, make_pair(1LL, pow3(a1)));

    lint limit2 = min(pow3(a1+1) - 1, limit) - pow3(a1);

    if (limit2 >= 1) {
      lint left = 1, right = floor(pow((long double)limit2, (long double)1.0/3));
      while (left < right) {
	lint m0 = left + (right-left)/3;
	lint m1 = right - (right-left)/3;
	lint value0 = min(pow3(m0+1) - 1, limit2) - pow3(m0);
	lint value1 = min(pow3(m1+1) - 1, limit2) - pow3(m1);
	if (value0 > value1) right = m1-1;
	else left = m0+1;
      }
      const lint pow3a1 = pow3(a1);
      for (lint a2 = left;; ++a2) {
	lint pow3a2 = pow3(a2);
	lint limit3 = min(pow3(a2+1) - 1, limit2) - pow3a2;
	if (limit3 < 0) break;
	pair<lint, lint> cand = make_pair(2LL + dp[limit3].first, pow3a1 + pow3a2 + dp[limit3].second);
	result = max(result, cand);
      }
    }
  }

  printf("%d %lld\n", (int)result.first, result.second);

  return 0;
}