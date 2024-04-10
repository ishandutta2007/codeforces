// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    array<int, 2> ct = {};
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] %= 2;
      mx = max(mx, ++ct[a[i]]);
    }

    if (mx != (n + 1) / 2) {
      cout << -1 << '\n';
      continue;
    }
    
    long long ans = LLONG_MAX;
    for (int f = 0; f < 2; ++f) {
      long long res = 0;
      int st = 0;
      int t = 0;
      for (int i = 0; i < n; ++i) {
        if (st > 0) {
          if (a[i] != t) {
            res += st;
            --st;
          } else {
            ++st;
          }
        } else if (a[i] != ((i & 1) ^ f)) {
          st = 1;
          t = a[i];
        }
      }
      if (st == 0) {
        ans = min(ans, res);
      }
    }
    cout << ans << '\n';
  }
}