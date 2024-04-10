#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;
constexpr int N = 6e5 + 5;


long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1) {
    if (p & 1)
      r = r * b % mod;
    b = b * b % mod;
  }
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

long long f[N], g[N];

void solve() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int x = 0; 4 * x <= n; ++x) {
    long long cur = C(n-2*x, 2*x) * g[2*x] % mod;
    cur = cur * f[n-4*x] % mod;
    ans = (ans + cur) % mod;
  }
  cout << ans << "\n";
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  f[0] = 1;
  f[1] = 1;
  g[0] = 1;
  for (int i = 2; i < N; ++i) {
    f[i] = (f[i-1] + (i-1) * f[i-2]) % mod;
    g[i] = (g[i-2] * 2LL * (i-1)) % mod;
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}