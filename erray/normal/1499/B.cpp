// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<bool> dp(2, true);
    for (int i = 1; i < n; ++i) {
      auto new_dp = dp;
      if (s[i] == '1') {
        new_dp[0] = (dp[0] && s[i - 1] != '1');
      }
      if (s[i] == '0') {
        new_dp[1] = (dp[1] && s[i - 1] != '0'); 
      }
      swap(dp, new_dp);
      dp[1] = dp[0] || dp[1];
    }
    cout << (dp[1] ? "YES" : "NO") << '\n';
  }
}