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
  int n;
  scanf("%d", &n);
  vector<int> many(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &many[i]);
  vector<lint> acc(n + 1);
  for (int i = 0; i < n; ++i)
    acc[i + 1] = acc[i] + many[i];

  vector<lint> dp(n + 1, 0LL);
  for (int i = 0; i < n; ++i) {
    const lint prev_result = dp[i];
    lint &result = dp[i + 1];
    const lint left_over = acc[i] - 3LL * prev_result;
    const int max_n2 = min(many[i] / 2LL, acc[i]);
    const int guess_n2 = min(left_over, (lint)max_n2);

    for (int n2 = max(guess_n2 - 50, 0); n2 <= min(guess_n2 + 50, max_n2); ++n2) {
      int n3 = (many[i] - 2 * n2) / 3;
      lint spare_here = many[i] - 2 * n2 - 3 * n3;

      lint res = prev_result + n3 + n2;

      lint need = n2;
      need = max(need - spare_here, 0LL);
      need = max(need - left_over, 0LL);
      res -= (need + 2) / 3;

      result = max(result, res);
    }
  }
  printf("%lld\n", dp[n]);

  return 0;
}