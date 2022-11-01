// May 31, 2020
// https://codeforces.com/contest/1363/problem/B

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
    string s;
    cin >> s;
    int n = (int) s.size();
    int ans = n;
    for (int p = 0; p < 2; p++) {
      vector<int> f(n + 1, 0);
      for (int i = 0; i < n; i++) {
        f[i + 1] = f[i] + ((s[i] - '0') ^ p);
      }
      for (int i = 0; i <= n; i++) {
        ans = min(ans, f[i] + (n - i - (f[n] - f[i])));
      }
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}