// April 12, 2020
// https://codeforces.com/contest/1338/problem/A

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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = a[0];
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] < mx) {
        ans = max(ans, 32 - __builtin_clz(mx - a[i]));
      }
      mx = max(mx, a[i]);
    }
    cout << ans << '\n';
    // for (int x = 0; x < 100; x++) {
    //   for (int i = 1; i < n; i++) {
    //     if (a[i] < a[i - 1])
    //   }
    // }
    // long long add = 0;
    //
    // int x = 0;
    // for (int i = 1; i < n; i++) {
    //   if (i > 50) {
    //     if (a[i] < a[i - 1]) {
    //       x++;
    //     }
    //   } else {
    //     while (a[i] + add < a[i - 1]) {
    //       assert(x <= 60);
    //       add += (1LL << x);
    //       x++;
    //       // cerr << "add " << (1LL << x) << " to all k >= " << i << '\n';
    //     }
    //     a[i] += add;
    //   }
    // }
    // cout << x << '\n';
  }


  return 0;
}