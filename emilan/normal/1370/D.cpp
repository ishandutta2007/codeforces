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
  vi a(n);
  rep(i, n) cin >> a[i];

  int l = 1, r = 1000000000;
  while (l < r) {
    int mi = (l + r) / 2;
    vi b1, b2;
    rep(i, n) {
      if (a[i] > mi) continue;

      if (b1.empty() || b1.back() != i - 1) b1.pb(i);
      if (i && (b2.empty() || b2.back() != i - 1)) b2.pb(i);
    }

    bool ok = false;
    if (k & 1) {
      if (sz(b1) >= k / 2 + 1) ok = true;
      if (!b2.empty()) {
        if (sz(b2) - (b2.back() == n - 1) >= k / 2) ok = true;
      }
    } else {
      if (!b1.empty()) {
        if (sz(b1) - (b1[0] == 0 && b1.back() == n - 1) >= k / 2) ok = true;
      }
      if (sz(b2) >= k / 2) ok = true;
    }

    if (ok) r = mi;
    else l = mi + 1;
  }

  cout << l;

  return 0;
}