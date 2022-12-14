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
#define mp(x, y)  make_pair(x, y);
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
  ioThings();

  dotc() {
    int n;
    cin >> n;

    int ll = -1e5, rr = 1e5, uu = 1e5, dd = -1e5;

    bool ok = true;
    while (n--) {
      int x, y, l, u, r, d;
      cin >> x >> y >> l >> u >> r >> d;
      if (!l) ll = max(ll, x);
      if (!r) rr = min(rr, x);
      if (!u) uu = min(uu, y);
      if (!d) dd = max(dd, y);
    }

    if (ll <= rr && dd <= uu) {
      cout << 1 << ' ' << ll << ' ' << dd << '\n';
    }else cout << "0\n";
  }

  return 0;
}