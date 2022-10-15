// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, (int) n + 1));
    dp[n - 1][n - 1] = 0;
    vector<int> e(n);

    for (int i = n - 1; i >= 0; --i) {
      int next = i + a[i];
      for (int j = i + 1; j <= next; ++j) {
        dp[i][j - 1] =  dp[j][next] + e[j];
        ++e[j];       
      }
      for (int j = n - 2; j >= 0; --j) {
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
      }
    }

    cout << dp[0][0] << '\n';
  }
}