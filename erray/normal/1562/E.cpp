// author: erray
#pragma GCC optimize ("O3,unroll-loops,no-stack-protector")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (s[i] == s[j]) {
          lcp[i][j] = 1 + lcp[i + 1][j + 1];
        }
      }
    }

    s += '*';
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      dp[i] = n - i;
      for (int j = 0; j < i; ++j) {
        int c = lcp[i][j];
        if (s[i + c] > s[j + c]) {
          dp[i] = max(dp[i], dp[j] + n - i - c);
        } 
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}