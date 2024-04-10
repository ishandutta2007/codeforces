#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

template <typename T> void update(T &x, T a) { x = ~x ? std::min(x, a) : a; }

char s[N + 1];
long long dp[N + 1][2];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, a, b;
    scanf("%d%d%d%s", &n, &a, &b, s);
    memset(dp, -1, sizeof(long long) * 2 * (n + 1));
    dp[0][0] = b;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        if (~dp[i][1]) {
          update(dp[i + 1][1], dp[i][1] + a + 2 * b);
        }
      } else {
        if (~dp[i][0]) {
          update(dp[i + 1][0], dp[i][0] + a + b);
          update(dp[i + 1][1], dp[i][0] + 2 * a + b);
        }
        if (~dp[i][1]) {
          update(dp[i + 1][0], dp[i][1] + 2 * a + 2 * b);
          update(dp[i + 1][1], dp[i][1] + a + 2 * b);
        }
      }
    //   printf("%lld %lld\n", dp[i + 1][0], dp[i + 1][1]);
    }
    printf("%lld\n", dp[n][0]);
  }
}