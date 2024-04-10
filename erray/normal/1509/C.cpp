// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> dp(n);
  for (int len = 1; len < n; ++len) {
    vector<long long> new_dp(n - len);
    for (int i = 0; i < n - len; ++i) {
      new_dp[i] = a[i + len] - a[i] + min(dp[i], dp[i + 1]); 
    }
    swap(new_dp, dp);
  }
  cout << dp[0] << '\n';
}