#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> k(n), c(m);
    for (auto &x : k) {
      cin >> x;
      x--;
    }
    sort(k.rbegin(), k.rend());
    for (auto &x : c) {
      cin >> x;
    }
    int ret = 0, pos = 0;
    for (auto &x : k) {
      if (pos >= x) {
        ret += c[x];
      } else {
        ret += c[pos++];
      }
    }
    cout << ret << "\n";
  }
}