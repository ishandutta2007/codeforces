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

  dotc() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi op;
    for (;;) {
      bool ok = true;
      vector<bool> b(n + 1);
      int mex = 0;
      rep(i, n) {
        if (i && a[i - 1] > a[i]) ok = false;
        b[a[i]] = true;
        while (b[mex]) mex++;
      }
      // for (int i : a) cout << i << ' ';
      // cout << endl;
      if (ok) break;

      op.pb(min(n, mex + 1));
      if (mex == n) a.erase(a.end() - 1), n--;
      else a[mex] = mex;
    }

    cout << sz(op) << '\n';
    rep(i, sz(op)) cout << op[i] << ' ';
    cout << '\n';
  }

  return 0;
}