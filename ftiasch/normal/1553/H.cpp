#include <bits/stdc++.h>

namespace {

static const int M = 19;

struct DP {
  int minv, maxv, mind;
} dp[1 << M];

} // namespace

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int mask = 0; mask < 1 << m; ++mask) {
    dp[mask] = DP{3 << m, -(2 << m), 1 << m};
  }
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    dp[a] = DP{0, 0, 1 << m};
  }
  for (int k = 0; k < m; ++k) {
    for (int mask0 = 0; mask0 < 1 << m; ++mask0) {
      if (~mask0 >> k & 1) {
        int delta = 1 << k;
        int mask1 = mask0 | delta;
        DP dp0 = dp[mask0];
        DP dp1 = dp[mask1];
        dp[mask0] =
            DP{std::min(dp0.minv, dp1.minv + delta),
               std::max(dp0.maxv, dp1.maxv + delta),
               std::min({dp0.mind, dp1.mind, (dp1.minv + delta) - dp0.maxv})};
        dp[mask1] =
            DP{std::min(dp0.minv + delta, dp1.minv),
               std::max(dp0.maxv + delta, dp1.maxv),
               std::min({dp0.mind, dp1.mind, (dp0.minv + delta) - dp1.maxv})};
      }
    }
  }
  for (int mask = 0; mask < 1 << m; ++mask) {
    printf("%d%c", dp[mask].mind, " \n"[mask + 1 == (1 << m)]);
  }
}