#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0;
  vector <vector <int>> dp(n + 1, vector <int> (m + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!i && !j)
        continue;
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 2;
      else
        dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]) - 1, dp[i][j]);
      ans = max(ans, dp[i][j]);
    }
  cout << ans;
  return 0;
}