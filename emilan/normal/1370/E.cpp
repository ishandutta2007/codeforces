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
  string s, t;
  cin >> n >> s >> t;
  string u;
  rep(i, n) {
    if (s[i] == t[i]) continue;
    u.pb(s[i]);
  }

  if (u.empty()) {
    cout << 0;
    return 0;
  }

  if (count(all(u), '0') != count(all(u), '1')) {
    cout << -1;
    return 0;
  }

  vi a;
  rep(i, sz(u)) {
    if (i && u[i - 1] == u[i]) a.back()++;
    else a.pb(1);
  }

  if (sz(a) & 1) {
    a[0] += a.back();
    a.erase(a.end() - 1);
  }

  int cur = a[0], mx = cur;
  n = sz(a);
  rep(i, n) {
    cur += a[(i * 2 + 2) % n] - a[(i * 2 + 1) % n];
    if (cur < a[(i * 2 + 2) % n]) cur = a[(i * 2 + 2) % n];
    mx = max(mx, cur);
  }

  cur = a[1];
  rep(i, n) {
    cur += a[(i * 2 + 3) % n] - a[(i * 2 + 2) % n];
    if (cur < a[(i * 2 + 3) % n]) cur = a[(i * 2 + 3) % n];
    mx = max(mx, cur);
  }

  cout << mx;

  return 0;
}