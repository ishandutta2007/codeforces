// June 11, 2020
// https://codeforces.com/contest/1366/problem/B

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
    int n, x, m;
    cin >> n >> x >> m;
    x--;
    int l = x, r = x;
    while (m--) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      if (b >= l && a <= r) {
        l = min(l, a);
        r = max(r, b);
      }
    }
    cout << r - l + 1 << '\n';
  }
  
  
  return 0;
}