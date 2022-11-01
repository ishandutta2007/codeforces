#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

vector <vector <int>> a, dp;

int f(int l, int r) {
  return (a[r][r] - a[l][r] - a[r][l] + a[l][l]) / 2;
}

void solve(int k, int l, int r, int optl, int optr) {
  if (l > r)
    return;
  int m = (l + r) / 2, optm = optl;
  dp[m][k] = dp[optm][k - 1] + f(optm, m);
  for (int i = optl + 1; i <= optr && i < m; i++) {
    if (dp[i][k - 1] + f(i, m) <= dp[m][k]) {
      dp[m][k] = dp[i][k - 1] + f(i, m);
      optm = i;
    }
  }
  solve(k, l, m - 1, optl, optm);
  solve(k, m + 1, r, optm, optr);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  a = vector <vector <int>>(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      int x = c - '0';
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + x;
    }
  dp = vector <vector <int>>(n + 1, vector<int>(k + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++)
    solve(i, 1, n, 0, n);
  cout << dp[n][k];
  return 0;
}