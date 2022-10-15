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

    sort(a.begin(), a.end());

    const int N = (int) 2e5 + 1;
    vector<int> dp(N);
    vector<int> ct(N);
    for (auto e : a) {
      ++ct[e]; 
    }

    vector<int> cur(N);
    int ans = 0;
    for (auto e : a) {
      ++cur[e];
      ++dp[e];
      if (cur[e] != ct[e]) {
        continue;  
      }

      for (int i = e * 2; i < N; i += e) {
        dp[i] = max(dp[i], dp[e]); 
      }

      ans = max(ans, dp[e]);
    }
    
    cout << n - ans << '\n';
  }
}