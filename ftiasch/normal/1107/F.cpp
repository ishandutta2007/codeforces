#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

using Offer = std::tuple<int, int, int>;

int main() {
  int n;
  scanf("%d", &n);
  std::vector<Offer> offers(n);
  for (int i = 0, a, b, k; i < n; ++i) {
    scanf("%d%d%d", &a, &b, &k);
    offers[i] = {b, a, k};
  }
  std::sort(offers.begin(), offers.end(), std::greater<Offer>());
  std::vector<Long> dp(n + 1);
  for (auto [b, a, k] : offers) {
    for (int i = n; i >= 0; --i) {
      Long new_dp = dp[i];
      if (i) {
        new_dp = std::max(new_dp, dp[i - 1] + a - (i - 1LL) * b);
      }
      new_dp = std::max(new_dp, dp[i] + a - 1LL * k * b);
      dp[i] = new_dp;
    }
  }
  printf("%lld\n", *std::max_element(dp.begin(), dp.end()));
}