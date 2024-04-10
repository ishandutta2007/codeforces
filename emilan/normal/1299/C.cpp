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

using ll = long long;
//#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

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

ll mod(1000000007);
double pi(acos(-1.0));

int main() {
  ioThings();

  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];

  vector<pair<double, int>> ret{{a[n - 1], 1}};
  for (int i = n - 2; i >= 0; i--) {
    ret.eb(a[i], 1);
    while (sz(ret) > 1 && ret[sz(ret) - 2].fi <= ret.back().fi) {
      int cnt = ret[sz(ret) - 2].se + ret.back().se;
      double avg = 
        (ret[sz(ret) - 2].fi * ret[sz(ret) - 2].se + 
         ret.back().fi * ret.back().se) / 
        cnt;
      ret.pop_back();
      ret.back() = {avg, cnt};
    }
  }

  cout << setprecision(9) << fixed;

  while (!ret.empty()) {
    rep(i, ret.back().se) cout << ret.back().fi << '\n';
    ret.pop_back();
  }

  return 0;
}