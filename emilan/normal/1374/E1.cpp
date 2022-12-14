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
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

int inf(0x3fffffff);
int mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n, k;
  cin >> n >> k;
  vi a, b, c;
  rep(i, n) {
    int t, x, y;
    cin >> t >> x >> y;
    if (x == 1 && y == 1) c.pb(t);
    else if (x == 1) a.pb(t);
    else if (y == 1) b.pb(t);
  }
  sort(all(a));
  sort(all(b));
  sort(all(c));

  // cout << sz(a) << ' ' << sz(b) << ' ' << sz(c) << endl;

  int x = 0, y = 0, t = 0;
  int ai = 0, bi = 0, ci = 0;
  while (x < k || y < k) {
    if (ci < sz(c)) {
      if (ai == sz(a) || bi == sz(b) || a[ai] + b[bi] >= c[ci]) t += c[ci], ci++;
      else t += a[ai] + b[bi], ai++, bi++;
      x++, y++;
    } else if (x < k) {
      if ((ci == sz(c) || a[ai] < c[ci]) && ai < sz(a)) t += a[ai], ai++, x++;
      else if (ci < sz(c)) t += c[ci], ci++, x++, y++;
      else break;
    } else if (y < k) {
      if ((ci == sz(c) || b[bi] < c[ci]) && bi < sz(b)) t += b[bi], bi++, y++;
      else if (ci < sz(c)) t += c[ci], ci++, x++, y++;
      else break;
    }
  }

  if (x < k || y < k) cout << -1;
  else cout << t;

  return 0;
}