#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int n, p[220], opt[220][220];
ll c[220][220], dp[220][220];

ll sum(int i, int l, int r) {
  return c[i][r] - c[i][l - 1];
}

ll sume(int i, int l, int r) {
  return c[i][n] - sum(i, l, r);
}

void solve(int i, int j, int cp) {
  if (i > j)
    return;
  p[opt[i][j]] = cp;
  solve(i, opt[i][j] - 1, opt[i][j]);
  solve(opt[i][j] + 1, j, opt[i][j]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> c[i][j], c[i][j] += c[i][j - 1];
  for (int i = 1; i <= n; i++)
    dp[i][i] = 0, opt[i][i] = i;
  for (int l = 1; l < n; l++)
    for (int i = 1; i + l <= n; i++) {
      int j = i + l;
      ll cs = 0;
      for (int k = i + 1; k <= j; k++)
        cs += sume(k, i + 1, j);
      dp[i][j] = cs + dp[i + 1][j];
      opt[i][j] = i;
      for (int k = i + 1; k <= j; k++) {
        cs += sume(k - 1, i, k - 1) - sum(k - 1, i, k - 2);
        cs -= sume(k, k, j) - sum(k, k + 1, j);
        if (cs + dp[i][k - 1] + dp[k + 1][j] < dp[i][j])
          dp[i][j] = cs + dp[i][k - 1] + dp[k + 1][j], opt[i][j] = k;
      }
    }
  solve(1, n, 0);
  // cout << dp[1][n] << "\n";
  for (int i = 1; i <= n; i++)
    cout << p[i] << (i < n ? " " : "\n");
}