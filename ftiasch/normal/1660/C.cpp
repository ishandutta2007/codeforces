#include <bits/stdc++.h>

const int N = 200'000;
const int C = 26;

using DP = std::array<int, C + 1>;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    DP dp{};
    std::ranges::fill(dp, n);
    dp[C] = 0;
    for (int i = 0; i < n; ++i) {
      DP new_dp{};
      for (int c = 0; c <= C; ++c) {
        new_dp[c] = dp[c] + 1;
      }
      int d = s[i] - 'a';
      new_dp[C] = std::min(new_dp[C], dp[d]);
      new_dp[d] = std::min(new_dp[d], dp[C]);
      dp.swap(new_dp);
    }
    printf("%d\n", dp[C]);
  }
}