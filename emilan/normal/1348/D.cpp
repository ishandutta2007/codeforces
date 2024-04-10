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

  dotc() {
    int n;
    cin >> n;

    if (n == 2) {
      cout << "1\n0\n";
      continue;
    } else if (n == 3) {
      cout << "1\n1\n";
      continue;
    }
    
    int lvl = log2(n);
    vi ans;
    int b = 1, m = 1;
    rep(i, lvl - 2) {
      int db = 1 << i;
      ans.pb(db);
      b += db;
      m += b;
    }

    bool ok = false;
    int l = 0, r = 1 << lvl - 2;
    while (l <= r) {
      int mi = (l + r) / 2;
      int b1 = b, m1 = m;
      b1 += mi;
      m1 += b1;

      if (m1 + b1 > n) r = mi;
      else if (m1 + 2 * b1 < n) l = mi + 1;
      else {
        ans.pb(mi);
        ans.pb(n - b1 - m1);
        ok = true;
        break;
      }
    }

    if (ok) {
      cout << sz(ans) << '\n';
      int b = 1,m = 1;
      for (int i : ans) cout << i << ' ';
      cout << '\n';
    } else cout << "-1\n";
  }

  return 0;
}