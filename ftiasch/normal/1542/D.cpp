#include <bits/stdc++.h>

namespace {

const int N = 500;
const int MOD = 998244353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, dp[2][N + 1];
std::pair<int, int> a[N];

} // namespace

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char op[2];
    scanf("%s", op);
    if (*op == '-') {
      a[i].second = -1;
    } else {
      scanf("%d", &a[i].first);
      a[i].second = i;
    }
  }
  int result = 0;
  for (int k = 0; k < n; ++k) {
    if (~a[k].second) {
      memset(dp[0], 0, sizeof(dp[0]));
      dp[0][0] = 1;
      int count = 0;
      for (int i = 0; i < n; ++i) {
        memset(dp[i + 1 & 1], 0, sizeof(dp[i + 1 & 1]));
        if (~a[i].second) {
          for (int j = 0; j <= count; ++j) {
            if (i == k) {
              add(dp[i + 1 & 1][j + 1], dp[i & 1][j]);
            } else if (a[i] < a[k]) {
              add(dp[i + 1 & 1][j], dp[i & 1][j]);
              add(dp[i + 1 & 1][j + 1], dp[i & 1][j]);
            } else {
              add(dp[i + 1 & 1][j], dp[i & 1][j]);
              add(dp[i + 1 & 1][j], dp[i & 1][j]);
            }
          }
          count += a[i] <= a[k];
        } else {
          for (int j = 0; j <= count; ++j) {
            add(dp[i + 1 & 1][j], dp[i & 1][j]);
            if (i < k) {
              add(dp[i + 1 & 1][std::max(j - 1, 0)], dp[i & 1][j]);
            } else if (j > 1) {
              add(dp[i + 1 & 1][j - 1], dp[i & 1][j]);
            }
          }
        }
      }
      for (int j = 1; j <= count; ++j) {
        add(result, 1LL * a[k].first * dp[n & 1][j] % MOD);
      }
    }
  }
  printf("%d\n", result);
}