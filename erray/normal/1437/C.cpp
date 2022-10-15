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
      --a[i];
    }
    sort(a.begin(), a.end());
    const int n2 = n * 2;
    vector<int> dp(n2 + 1);
    for (int i = n - 1; i >= 0; --i) {
      vector<int> new_dp(n2 + 1, (int) 1e9);

      for (int j = n2 - (n - i); j >= 0; --j) {
        new_dp[j] = dp[j + 1] + abs(a[i] - j); 
        new_dp[j] = min(new_dp[j], new_dp[j + 1]);
      }
      swap(dp, new_dp);
    }
    cout << dp[0] << '\n';
  }
}