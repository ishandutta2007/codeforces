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

  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n);
  rep(i, n)
    cin >> a[i];

  vector<pair<pair<int, int>, int>> op(m);
  rep(i, m)
    cin >> op[i].fi.fi >> op[i].fi.se >> op[i].se;

  vector<ll> b(n);
  vector<int> c(m);
  adjacent_difference(all(a), b.begin());
  rep(i, k) {
    int x, y; cin >> x >> y;

    c[x - 1]++;
    if (y < m)
      c[y]--;
  }

  int cur = 0;
  for (int i = 0; i < m; i++) {
    cur += c[i];
    b[op[i].fi.fi - 1] += (ll)op[i].se * cur;
    if (op[i].fi.se < n)
      b[op[i].fi.se] -= (ll)op[i].se * cur;
  }
  
  vector<ll> ans(n);
  partial_sum(all(b), ans.begin());
  for (auto& i : ans)
    cout << i << ' ';

  return 0;
}