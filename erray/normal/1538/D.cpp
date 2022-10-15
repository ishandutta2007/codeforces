// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 1 && a == b) {
      cout << "NO\n";
      continue;
    }

    vector<vector<int>> rep(2);
    auto Rep = [&](int x) {
      vector<int> res;
      for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
          x /= i;
          res.push_back(x);
        }
      }
      if (x > 1) {
        res.push_back(x);
      }
      return res;
    };

    rep[0] = Rep(a);
    rep[1] = Rep(b);
    bool ok = k <= (int(rep[0].size()) + int(rep[1].size()));
    ok &= (a % b == 0 || b % a == 0 || k > 1);
    cout << (ok ? "YES" : "NO") << '\n';
  }
}