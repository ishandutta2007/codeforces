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

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
// #define int ll
using vi = vector<int>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
  ioThings();

  dotc() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi v1, v2, a1(n + 1), a2(n + 1);
    int mx1 = 0, mx2 = 0;
    a1[0] = 1, a2[0] = 1;
    for (int i = 0; i < n - 1; i++) {
      if (a1[a[i]]) break;
      a1[a[i]]++;
      mx1 = max(mx1, a[i]);
      if (mx1 == i + 1) v1.pb(mx1);
    }
    
    for (int i = 0; i < n - 1; i++) {
      if (a2[a[n - i - 1]]) break;
      a2[a[n - i - 1]]++;
      mx2 = max(mx2, a[n - i - 1]);
      if (mx2 == i + 1) v2.pb(mx2);
    }

    vii pairs;
    int ai = 0, bi = sz(v2) - 1;
    while (ai < sz(v1) && bi >= 0) {
      if (v1[ai] + v2[bi] == n) {
        pairs.pb({v1[ai], v2[bi]});
        ai++, bi--;
      } else if (v1[ai] + v2[bi] > n) bi--;
      else ai++;
    }

    cout << sz(pairs) << '\n';
    for (ii z : pairs) cout << z.fi << ' ' << z.se << '\n';
  }

  return 0;
}