// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int r, n;
  cin >> r >> n;
  vector<int> t(n), x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> x[i] >> y[i];
    --y[i], --x[i];
  }

  vector<int> dp(n, -n);
  int p = 0;
  int best = -n;
  for (int i = 0; i < n; ++i) {
    if (x[i] + y[i] <= t[i]) {
      dp[i] = 1;
    }
    while (p < i && t[i] - t[p] >= (r - 1) * 2) {
      best = max(best, dp[p]);
      ++p;
    }

    for (int j = p; j < i; ++j) {
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }                            
    }
    dp[i] = max(dp[i], best + 1);  
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}