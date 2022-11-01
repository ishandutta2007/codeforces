// June 25, 2020
// https://codeforces.com/contest/1373/problem/D

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
    vector<int> a(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i % 2 == 0) {
        ans += a[i];
      }
    }
    long long even = ans;
    vector<int> b;
    for (int i = 0; 2 * i + 1 < n; i++) {
      int p = 2 * i;
      b.push_back(a[p + 1] - a[p]);
    }
    for (int it = 0; it < 2; it++) {
      long long best = 0, cur = 0;
      int m = (int) b.size();
      for (int i = 0; i < m; i++) {
        cur += b[i];
        if (cur < 0) {
          cur = 0;
        }
        best = max(best, cur);
      }
      ans = max(ans, even + best);
      b.clear();
      for (int i = 0; 2 * i + 2 < n; i++) {
        int p = 2 * i + 1;
        b.push_back(a[p] - a[p + 1]);
      }
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}