#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500;

int n, a[N], dp[N + 1];
std::vector<int> nxt[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  dp[n] = 0;
  for (int i = n; i--;) {
    nxt[i].push_back(i + 1);
    dp[i] = 1 + dp[i + 1];
    for (int d = 0;; ++d) {
      int x = a[i] + d;
      int j = nxt[i][d];
      if (j < n && a[j] <= x && x < a[j] + static_cast<int>(nxt[j].size())) {
        int nn = nxt[j][x - a[j]];
        nxt[i].push_back(nn);
        dp[i] = std::min(dp[i], 1 + dp[nn]);
      } else {
        break;
      }
    }
  }
  printf("%d\n", dp[0]);
}