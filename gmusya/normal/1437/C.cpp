#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    vector <vector <int>> dp(n + 1, vector <int>(2 * n + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      int x = a[i - 1];
      for (int j = 1; j < 2 * n + 1; j++)
        for (int oldj = 0; oldj < j; oldj++)
          dp[i][j] = min(dp[i][j], dp[i - 1][oldj] + abs(x - j));
    }
    int ans = INF;
    for (int i = 0; i < 2 * n + 1; i++)
      ans = min(ans, dp[n][i]);
    cout << ans << '\n';
  }
  return 0;
}