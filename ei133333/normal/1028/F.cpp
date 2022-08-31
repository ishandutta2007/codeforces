#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

using pi = pair< int, int >;

map< int, set< pi > > pts;
map< pi, int > dd;

int main() {
  int N;
  cin >> N;
  int ret = 0;
  for(int i = 0; i < N; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    int64 d = 1LL * x * x + 1LL * y * y;

    if(t == 1) {
      ++ret;
      for(auto &p : pts[d]) {
        int64 xx = p.first + x;
        int64 yy = p.second + y;
        int64 gg = __gcd(xx, yy);
        xx /= gg;
        yy /= gg;
        dd[{xx, yy}] -= 2;
      }
      {
        pts[d].emplace(x, y);
        auto p = __gcd(x, y);
        dd[{x / p, y / p}] -= 1;
      }

    } else if(t == 2) {
      --ret;

      {
        pts[d].erase({x, y});
        auto p = __gcd(x, y);
        ++dd[{x / p, y / p}];
      }

      for(auto &p : pts[d]) {
        int64 xx = p.first + x;
        int64 yy = p.second + y;
        int64 gg = __gcd(xx, yy);
        xx /= gg;
        yy /= gg;
        dd[{xx, yy}] += 2;
      }

    } else if(t == 3) {

      auto p = __gcd(x, y);
      int ans = ret;
      x /= p, y /= p;
      if(dd.count({x, y})) ans += dd[{x, y}];
      cout << ans << endl;
    }
  }


}