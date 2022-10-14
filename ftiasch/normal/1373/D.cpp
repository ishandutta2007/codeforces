#line 1 "sol.cpp"
#include <bits/stdc++.h>

void update(long long &x, long long a) { x = std::max(x, a); }

const int N = 200'000;

int n, a[N + 3];
long long dp[N + 3][4];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    a[n] = a[n + 1] = a[n + 2] = 0;
    memset(dp, 0, sizeof(long long) * (n + 3) * 4);
    dp[0][0] = a[0];
    dp[1][2] = a[1];
    for (int i = 0; i < n; ++i) {
      for (int mask = 0; mask < 4; ++mask) {
        update(dp[i + 2][mask], dp[i][mask] + a[i + 2]);
        if (~mask & 1) {
          update(dp[i + 1][mask | 1], dp[i][mask] + a[i + 1]);
        }
        if (~mask & 2) {
          update(dp[i + 3][mask | 2], dp[i][mask] + a[i + 3]);
        }
      }
    }
    int target = (n & 1) ? n + 1 : n;
    printf("%lld\n", std::max(dp[target][0], dp[target][3]));
  }
}