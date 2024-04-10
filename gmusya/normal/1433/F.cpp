#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector <vector <int>> a(n, vector <int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  vector <vector <int>> dp(n, vector <int>(k, -INF));
  for (int i = 0; i < n; i++) {
    vector <vector <vector <int>>> tmp(m + 1, vector <vector <int>>(m, vector <int>(k, -INF)));
    tmp[0][0][0] = 0;
    for (int j = 0; j < m; j++) {
      tmp[j + 1] = tmp[j];
      for (int cnt = 0; cnt + 1 < m; cnt++)
        for (int z = 0; z < k; z++)
          tmp[j + 1][cnt + 1][(a[i][j] + z) % k] = max(tmp[j + 1][cnt + 1][(a[i][j] + z) % k], tmp[j][cnt][z] + a[i][j]);
    }
    for (int pos = 0; pos < k; pos++)
      for (int x = 0; x <= m / 2; x++)
        dp[i][pos] = max(dp[i][pos], tmp[m][x][pos]);
  }
  vector <vector <int>> ans(n + 1, vector <int>(k, -INF));
  ans[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (dp[i][j] < 0)
        continue;
      for (int z = 0; z < k; z++)
        ans[i + 1][(dp[i][j] + z) % k] = max(ans[i + 1][(dp[i][j] + z) % k], ans[i][z] + dp[i][j]);
    }
  }
  cout << ans[n][0];
  return 0;
}