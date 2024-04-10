#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, q, ze = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
    ze += (x == 0);
  }
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      x--;
      ze -= (a[x] == 0);
      a[x] ^= 1;
      ze += (a[x] == 0);
    } else {
      x = n + 1 - x;
      if (x <= ze) cout << 0 << "\n";
      else cout << 1 << "\n";
    }
  }
}