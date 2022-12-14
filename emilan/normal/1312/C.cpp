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
using vi = vector<int>;

int main() {
  ioThings();

  dotc() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep (i, n) cin >> a[i];

    bool ok = true;
    ll cur = 1;
    while (cur <= 1e16) cur *= k;
    for (; cur; cur /= k) {
      int cnt = 0;
      for (auto& j : a) {
        if (j / cur == 1) j -= cur, cnt++;
        else if (j / cur > 1) ok = false;
      }
      if (cnt > 1) ok = false;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}