#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> c(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
    }
  }
  using lint = long long;
  vector<vector<lint>> sum(n, vector<lint>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (j > i) {
        sum[i][j] = sum[i][j - 1];
      }
      for (int k = 0; k < i; k++) {
        sum[i][j] += c[j][k];
      }
      for (int k = j + 1; k < n; k++) {
        sum[i][j] += c[j][k];
      }
      for (int k = i; k < j; k++) {
        sum[i][j] -= c[k][j];
      }
    }
  }
  vector<vector<lint>> dp(n, vector<lint>(n));
  vector<vector<int>> opt(n, vector<int>(n, -1));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      dp[i][j] = 1e18;
      for (int k = i; k <= j; k++) {
        lint cost = 0;
        if (k > i) {
          cost += dp[i][k - 1];
          cost += sum[i][k - 1];
        }
        if (k < j) {
          cost += dp[k + 1][j];
          cost += sum[k + 1][j];
        }
        if (cost < dp[i][j]) {
          opt[i][j] = k;
          dp[i][j] = cost;
        }
      }
    }
  }
  vector<int> ans(n, -1);
  const auto Dfs = [&](const auto &self, int l, int r, int p) {
    if (l > r) return;
    int u = opt[l][r];
    ans[u] = p;
    self(self, l, u - 1, u);
    self(self, u + 1, r, u);
  };
  Dfs(Dfs, 0, n - 1, -1);
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " \n"[i + 1 == n];
  }
  return 0;
}