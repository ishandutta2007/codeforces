#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::array<int, 2> dp{0, -1'000'000'000};
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    int p = std::abs(a) & 1;
    std::array<int, 2> new_dp{dp[0], dp[1]};
    for (int c = 0; c < 2; ++c) {
      new_dp[(c + p) & 1] = std::max(new_dp[(c + p) & 1], dp[c] + a);
    }
    dp = new_dp;
  }
  printf("%d\n", dp[1]);
}