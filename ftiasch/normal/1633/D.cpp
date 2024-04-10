#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1000;
const int S = 12;

int min_step[N + 1];

int main() {
  std::fill(min_step, min_step + (N + 1), INT_MAX);
  min_step[1] = 0;
  for (int a = 1; a < N; ++a) {
    for (int x = 1; x <= a; ++x) {
      int target = a + a / x;
      if (target <= N) {
        min_step[target] = std::min(min_step[target], min_step[a] + 1);
      }
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, limit;
    scanf("%d%d", &n, &limit);
    std::vector<int> b(n), c(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &c[i]);
    }
    std::vector<int> dp(n * S + 1, 0);
    for (int i = 0; i < n; ++i) {
      int s = min_step[b[i]];
      for (int j = n * S; j >= s; --j) {
        dp[j] = std::max(dp[j], dp[j - s] + c[i]);
      }
    }
    printf("%d\n", dp[std::min(n * S, limit)]);
  }
}