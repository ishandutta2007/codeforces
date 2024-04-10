#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 8;
const int L = 840;

long long cnt[N + 1], dp[N * L + 1];

int main() {
  long long m;
  scanf("%lld", &m);
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int w = 1; w <= N; ++w) {
    scanf("%lld", cnt + w);
    int g = L / w;
    for (int j = N * L; j >= 0; --j) {
      long long new_dp = -1;
      for (int r = 0; r < g && r <= cnt[w] && w * r <= j; ++r) {
        if (~dp[j - w * r]) {
          new_dp = std::max(new_dp, dp[j - w * r] + (cnt[w] - r) / g);
        }
      }
      dp[j] = new_dp;
    }
  }
  long long result = 0;
  for (int j = 0; j <= N * L && j <= m; ++j) {
    if (~dp[j]) {
      result = std::max(result, std::min((m - j) / L, dp[j]) * L + j);
    }
  }
  printf("%lld\n", result);
}