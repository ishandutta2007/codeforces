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
#define mod       998244353

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n, m; cin >> n >> m;
  ll ans = n - 2;
  ll e = n - 3, b = 2;
  while (e) {
    if (e & 1) ans = ans * b % mod;
    b = b * b % mod;
    e /= 2;
  }

  for (int i = m, d = 1; i > m - n + 1; i--, d++) {
    ll modinv = 1, e = mod - 2, b = d;
    while (e) {
      if (e & 1) modinv = modinv * b % mod;
      b = b * b % mod;
      e /= 2;
    }
    ans = ans * i % mod * modinv % mod;
  }

  cout << ans;

  return 0;
}