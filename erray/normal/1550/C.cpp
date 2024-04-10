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
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    auto Dist = [&](auto x, auto y) {
      return abs(x[0] - y[0]) + abs(x[1] - y[1]);
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      vector<array<int, 2>> ps;
      for (int j = i; j < n; ++j) {
        auto cur = array{b[j], j - i};
        bool ok = true;
        for (auto e : ps) {
          for (auto ee : ps) {
            if (ee == e) {
              continue;
            } 
            array<int, 3> all = {Dist(e, ee), Dist(e, cur), Dist(ee, cur)};
            sort(all.begin(), all.end());
            ok &= (all[0] + all[1] != all[2]);
          }
        }
        if (!ok) {
          break;
        }
        ++ans;
        ps.push_back(cur);
      }
    }
    cout << ans << '\n';
  }
}