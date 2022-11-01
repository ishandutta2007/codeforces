#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector <ll> a(n + 1), sum(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  vector <vector <ll>> dp(n + 1, vector <ll>(k + 1, -INF));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (i < m)
      continue;
    for (int j = 1; j <= k; j++)
      dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + sum[i] - sum[i - m]);
  }
  cout << dp[n][k];
  return 0;
}