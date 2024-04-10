// July 21, 2020
// https://codeforces.com/contest/1381/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a;
    int mx = -1;
    for (int i = 0; i < 2 * n; i++) {
      int x;
      cin >> x;
      if (x > mx) {
        mx = x;
        a.push_back(i);
      }
    }
    a.push_back(2 * n);
    vector<int> b;
    for (int i = 0; i < (int) a.size() - 1; i++) {
      b.push_back(a[i + 1] - a[i]);
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int x : b) {
      for (int i = n; i >= x; i--) {
        dp[i] |= dp[i - x];
      }
    }
    cout << (dp[n] == 1 ? "YES" : "NO") << '\n';
  }
  
  
  return 0;
}