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

  dotc() {
    string s;
    cin >> s;

    vi a(sz(s));
    int cur = 0;
    rep(i, sz(s)) {
      if (s[i] == '+') cur++;
      else cur--;
      a[i] = cur;
    }

    ll res = 0;
    int mn = 0;
    rep(i, sz(s)) {
      if (a[i] < mn) {
        res += 1ll * (i + 1) * (mn - a[i]);
        mn = a[i];
      }
    }
    res += sz(s);

    cout << res << '\n';
  }

  return 0;
}