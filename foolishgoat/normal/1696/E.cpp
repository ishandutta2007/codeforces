#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

const int N = 5e5 + 5;

long long fac[N], inv[N];

long long C(int n, int k) {
  return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
  }
  inv[N-1] = powmod(fac[N-1], mod-2);
  for (int i = N-2; i > 0; --i) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }
  int n;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> a(n+1);
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
  }
  while (!a.empty() && a.back() == 0) a.pop_back(); 
  n = a.size();
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = (ans + C(i+a[i], i+1)) % mod;
  }
  cout << ans << "\n";
  return 0;
}