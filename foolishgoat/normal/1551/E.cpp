#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

int dp[N][N], a[N];

void upd(int & var, int x) {
  if (var < x)
    var = x;
}

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      dp[i][j] = 0;
  for (int i = 0; i < n; ++i) {
    int v = a[i];
    for (int j = 0; j <= i; ++j) {
      upd(dp[i+1][j+1], dp[i][j] + ((j+1) == v));
      upd(dp[i+1][j], dp[i][j]);
    }
  }
  int ans = -1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (dp[i][j] >= k) {
        ans = max(ans, j + (n - i));
      }
    }
  }
  if (ans >= 0)
    ans = n - ans;
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}