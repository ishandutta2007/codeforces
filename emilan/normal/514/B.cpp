#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n, x0, y0; cin >> n >> x0 >> y0;
  set<pair<int, int>> t;
  while (n--) {
    int x, y; cin >> x >> y;
    x -= x0, y -= y0;
    t.insert({x, y});
  }

  int cnt = 0;
  while (!t.empty()) {
    auto cur = *t.begin();
    int x = cur.fi, y = cur.se;
    int gcd = __gcd(x, y);
    x /= gcd, y /= gcd;
    set<pair<int, int>> del;
    for (auto& i : t) {
      if (x == 0) {
        if (i.fi == 0) del.insert({i.fi, i.se});
      } else if (i.fi % x == 0) {
        int m = i.fi / x;
        if (y == 0) {
          if (i.se == 0) del.insert({i.fi, i.se});
        } else if (i.se % y == 0 && i.se / y == m)
          del.insert({i.fi, i.se});
      }
    }

    for (auto& i : del)
      t.erase(i);
    cnt++;
  }

  cout << cnt;

  return 0;
}