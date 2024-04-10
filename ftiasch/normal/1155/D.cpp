#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

using Dp = std::array<Long, 3>;

int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  Dp dp{};
  Long result = 0;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    Dp new_dp{};
    for (int j = 0; j < 3; ++j) {
      for (int k = std::max(j - 1, 0); k <= j; ++k) {
        Long val = j == 1 ? 1LL * a * x : a;
        new_dp[j] = std::max(new_dp[j], std::max(dp[k] + val, 0LL));
      }
      result = std::max(result, new_dp[j]);
    }
    dp = new_dp;
  }
  printf("%lld\n", result);
}