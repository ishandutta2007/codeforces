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
    vi t(n);
    rep(i, n) cin >> t[i];

    int mx1 = 1, mx2 = 1;
    vi c1(n), c2(n);
    c1[0] = 1, c2[0] = 1;
    for (int i = 1; i < n; i++) {
      if (t[i] == t[i - 1]) c1[i] = 1;
      else c1[i] = c1[i - 1] ^ 3;
      mx1 = max(mx1, c1[i]);
    }

    if (t[n - 1] != t[0] && c1[n - 1] == c1[0]) {
      if (t[n - 2] == t[n - 1]) c1[n - 1] = 2;
      else if (t[0] == t[1]) c1[0] = 2;
      else c1[0] = 3, mx1 = 3;
    }

    for (int i = 1; i < n; i++) {
      if (t[i] == t[i - 1]) c2[i] = 2, mx2 = 2;
      else c2[i] = c2[i - 1] ^ 3;
      mx2 = max(mx2, c2[i]);
    }

    if (t[n - 1] != t[0] && c2[n - 1] == c2[0]) {
      if (t[n - 2] == t[n - 1]) c2[n - 1] = 2;
      else if (t[0] == t[1]) c2[0] = 2;
      else c2[0] = 3, mx2 = 3;
    }

    if (mx1 < mx2) {
      cout << mx1 << '\n';
      rep(i, n) cout << c1[i] << " \n"[i == n - 1];
    } else {
      cout << mx2 << '\n';
      rep(i, n) cout << c2[i] << " \n"[i == n - 1];
    }
  }

  return 0;
}