// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[n - i - 1];
    }
    vector<long long> dp(2);
    for (auto el : a) {
      auto newDp = dp;
      newDp[0] = max(newDp[0], dp[1] + el);
      newDp[1] = max(newDp[1], dp[0] - el);
      swap(newDp, dp);
    }
    cout << dp[0] << '\n';
  }
}