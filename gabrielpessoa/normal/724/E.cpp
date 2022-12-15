#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;

main() {
  int n, c;
  cin >> n >> c;
  vector<int> p(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> dp(n+1, inf), tdp(n+1, inf);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    dp.swap(tdp);
    for (int j = 0; j <= n; j++) {
      dp[j] = inf;
      dp[j] = min(dp[j], min(tdp[j] + c * j + p[i], inf));
      if (j > 0) dp[j] = min(dp[j], tdp[j - 1] + s[i]);
    }
  }
  int ans = inf;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans << endl;
}