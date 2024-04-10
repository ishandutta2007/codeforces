#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define fastio    ios::sync_with_stdio(0); cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

int inf(0x3fffffff);
int mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  fastio;
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];

  vector<si> iv(n);
  rep(i, n) {
    rep(j, i) {
      if (a[j] > a[i]) iv[i].insert(j);
    }
  }

  vii b(n);
  rep(j, n) {
    b[j] = {a[j], j};
  }
  sort(all(b));

  vii ret;
  for (int i = n - 1; i >= 0; i--) {
    vi c;
    rep(j, n) {
      if (iv[i].count(b[j].se)) c.pb(b[j].se);
    }

    for (int j : c) {
      swap(a[j], a[i]);
      ret.eb(j, i);
    }
  }

  cout << sz(ret) << '\n';
  for (auto& i : ret) cout << i.fi + 1 << ' ' << i.se + 1 << '\n';

  return 0;
}