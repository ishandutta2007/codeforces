// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> ct(m + 1);
    for (auto e : a) {
      ++ct[e % m];
    }
    int ans = 0;
    for (int i = 0; i <= m / 2; ++i) {
      int me = ct[i], ot = ct[(m - i) % m];
      if (me > ot) {
        swap(me, ot);
      }
      if (ot == 0) {
        continue;
      }
      ans += max(1, ot - me);
    }
    cout << ans << '\n';
  }
}