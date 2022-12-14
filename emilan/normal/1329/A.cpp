#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
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
#define mp        make_pair
#define mt        make_tuple
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

ll mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;
  vi a(m);
  ll tot = 0;
  rep(i, m) {
    cin >> a[i];
    if (a[i] + i > n) {
      cout << -1;
      return 0;
    }
    tot += a[i];
  }
  
  if (tot < n) {
      cout << -1;
      return 0;
  }

  ll extra = tot - n;
  vi ret(m);
  int pos = 0;
  for (int i = m - 1; i >= 0; i--) {
    ll d;
    if (extra > 0) {
      d = min({a[i] - 1, pos, (int)min((ll)1e9, extra)});
      extra -= d;
    } else {
      d = 0;
    }
    ret[i] = pos - d;
    pos += a[i] - d;
  }

  for (int i : ret) cout << i + 1 << ' ';

  return 0;
}