#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;

void solve() {
  int n; cin >> n;
  map<pair<int, int>, int> mp;
  while (n--) {
    int x, y, u, v; cin >> x >> y >> u >> v;
    int dx = u - x, dy = v - y, g = gcd(abs(dx), abs(dy));
    dx /= g; dy /= g;
    ++mp[{dx, dy}];
  }
  ll ans = 0;
  for (auto [d, v] : mp) {
    auto [dx, dy] = d;
    if (mp.count({-dx, -dy}) == 1) ans += 1LL * v * mp[{-dx, -dy}];
  }
  cout << ans / 2 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}