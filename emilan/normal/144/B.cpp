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

using General = pair<pair<int, int>, bool>;

int main() {
  ioThings();

  int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
  if (xa > xb) swap(xa, xb);
  if (ya > yb) swap(ya, yb);
  map<pair<int, int>, bool> g;
  for (int i = xa; i <= xb; i++) {
    for (int j = ya; j <= yb; j++) {
      if (i != xa && i != xb && j != ya && j != yb) j = yb - 1;
      else g[{i, j}] = false;
    }
  }

  int n; cin >> n;
  while (n--) {
    int x, y, r; cin >> x >> y >> r;
    for (auto& i : g) {
      int xx = i.fi.fi - x, yy = i.fi.se - y;
      if (xx * xx + yy * yy <= r * r)
        i.se = true;
    }
  }

  cout << count_if(all(g), [](General x) { return !x.se; });

  return 0;
}