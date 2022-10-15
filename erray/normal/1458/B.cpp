// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  int Max = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0] >> a[i][1];
    Max += a[i][0];
  }

  vector<vector<int>> dp(n + 1, vector<int>(Max, (int) -1e9));
  dp[0][0] = 0;

  for (auto[cap, tot] : a) {
    for (int i = n; i >= 0; --i) {
      for (int j = Max - 1; j >= 0; --j) {
        dp[i][j] = max(dp[i][j] + tot, (i > 0 && j >= cap ? dp[i - 1][j - cap] + tot * 2 : -(int) 1e9));
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int j = 0; j < Max; ++j) {
      if (dp[i][j] == -1) {
        continue;
      }
      ans = max(ans, min(dp[i][j], j * 2));
    }
    cout << ans * 0.5 << ' ';
  }
}