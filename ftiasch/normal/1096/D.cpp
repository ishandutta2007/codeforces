#line 1 "sol.cpp"
#include <bits/stdc++.h>

const long long INF = 1e18;

void update(long long &x, long long a) { x = std::min(x, a); }

int main() {
  int n;
  scanf("%d", &n);
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  long long dp[4];
  dp[0] = 0;
  std::fill(dp + 1, dp + 4, INF);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    long long new_dp[4];
    std::fill(new_dp, new_dp + 4, INF);
    for (int st = 0; st < 4; ++st) {
      update(new_dp[st], dp[st] + a);
      if (s[i] == "hard"[st]) {
        if (st < 3) {
          update(new_dp[st + 1], dp[st]);
        }
      } else {
        update(new_dp[st], dp[st]);
      }
    }
    memcpy(dp, new_dp, sizeof(dp));
  }
  printf("%lld\n", *std::min_element(dp, dp + 4));
}