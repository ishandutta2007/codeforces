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

vector<vector<ll>> dp(61, vector<ll>(31, -1));

ll C(int n, int r) {
  if (r > n / 2) r = n - r;
  if (r == 0) return 1;
  if (r < 0) return 0;
  if (dp[n][r] != -1) return dp[n][r];
  return dp[n][r] = C(n - 1, r - 1) + C(n - 1, r);
}

int main() {
  ioThings();

  int n, m, t; cin >> n >> m >> t;
  ll ans = C(n + m, t);
  for (int i = 0; i <= t; i++) {
    if (i > 3 && i < t)
      continue;
    ans -= C(n, i) * C(m, t - i);
  }

  cout << ans;

  return 0;
}