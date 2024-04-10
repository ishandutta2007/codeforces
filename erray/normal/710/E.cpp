// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  int d = x + y;
  const int N = 2 * n + 2;
  vector<long long> dp(N);
  for (int i = 0; i <= n; ++i) {
    dp[i] = 1LL * i * x;
  }

  for (int i = 1; i <= n; ++i) {
    dp[i * 2] = min(dp[i] + y, dp[i * 2]);
    dp[i * 2 + 1] = min(dp[i] + d, dp[i * 2 + 1]);
    dp[i * 2 - 1] = min(dp[i] + d, dp[i * 2 - 1]);  
  }

  cout << dp[n] << '\n';
}