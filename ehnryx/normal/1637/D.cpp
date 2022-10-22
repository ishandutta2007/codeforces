#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll total = 0;
    ll sqr = 0;
    for(int i=0; i<n; i++) {
      cin >> a[i];
      sqr += a[i] * a[i];
      total += a[i];
    }
    for(int i=0; i<n; i++) {
      cin >> b[i];
      sqr += b[i] * b[i];
      total += b[i];
    }

    ll base = sqr * ((n-1) - 1);

    int m = n*100;
    vector dp(n+1, vector<bool>(m + 1));
    dp[0][0] = true;
    for(int i=1; i<=n; i++) {
      for(int j=0; j<=m; j++) {
        if(!dp[i-1][j]) continue;
        dp[i][j + a[i-1]] = true;
        dp[i][j + b[i-1]] = true;
      }
    }

    ll ans = numeric_limits<ll>::max();
    for(int v=0; v<=m; v++) {
      if(!dp[n][v]) continue;
      ans = min(ans, base + (ll)v * v + (total - v) * (total - v));
    }

    cout << ans << nl;
  }

  return 0;
}