#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = min(a[i], n);
  }
  vector <vector <int>> dp(n + 1, vector <int>(n + 1, n + 10));
  for (int i = 0; i <= n; i++)
    dp[0][i] = i;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      if (i + 1 <= n)
        dp[i + 1][min(a[i], j)] = min(dp[i + 1][min(a[i], j)], dp[i][j] + (j < a[i]));
      if (j + 1 <= n)
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
    }
  cout << *min_element(dp[n].begin(), dp[n].end());
  return 0;
}