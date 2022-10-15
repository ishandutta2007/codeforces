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
    vector<vector<long long>> dp(n, vector<long long>(2, (int) 1e6));
    dp.push_back({0, 0});
    for (int i = n - 1; i >= 0; --i) {
      if (i < n - 1) {
        dp[i][0] = dp[i + 2][1] + a[i] + a[i + 1];
        dp[i][1] = dp[i + 2][0];
      } 
      dp[i][0] = min(dp[i][0], dp[i + 1][1] + a[i]);
      dp[i][1] = min(dp[i][1], dp[i + 1][0]);
    }
    cout << dp[0][0] << '\n';
  }
}