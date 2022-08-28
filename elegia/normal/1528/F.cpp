#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int P = 998244353;

int norm(int x) { return x >= P ? (x - P) : x; }

void add(int& x, int y) { if ((x += y) >= P) x -= P; }

void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  return norm(x + P);
}

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % P;
    x = x * (ll)x % P;
    k >>= 1;
  }
  return ret;
}

const int K = 100010;

int fac[K], ifac[K], nv[K];
int pw[K];

void prepare(int k, int p) {
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) fac[i] = fac[i - 1] * (ull)i % P;
  ifac[k] = inv(fac[k]);
  for (int i = k; i; --i) ifac[i - 1] = ifac[i] * (ull)i % P;
  for (int i = 1; i <= k; ++i) nv[i] = ifac[i] * (ull)fac[i - 1] % P;
  pw[1] = 1;
  static int pr[K];
  int pc = 0;
  for (int i = 2; i <= k; ++i) {
    if (!pw[i]) {
      pr[++pc] = i;
      pw[i] = mpow(i, p);
    }
    for (int j = 1; i * pr[j] <= k; ++j) {
      pw[i * pr[j]] = pw[i] * (ull)pw[pr[j]] % P;
      if (i % pr[j] == 0) break;
    }
  }
}

int binom(int n, int m) { return fac[n] * (ull)ifac[m] % P * ifac[n - m] % P; }

namespace INVS {

int t;
int a[K], b[K], p[K];

void solve() {
  if (!t) return;
  p[0] = 1;
  for (int i = 1; i <= t; ++i) p[i] = p[i - 1] * (ull)a[i] % P;
  int pr = inv(p[t]);
  for (int i = t; i; --i) {
    b[i] = pr * (ull)p[i - 1] % P;
    pr = pr * (ull)a[i] % P;
  }
}

void pb(int x) { a[++t] = x; }

}

int f[K], g[K], d[K];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k; cin >> n >> k;
  if (n == P) {
    cout << "0\n";
    return 0;
  }
  prepare(k + 5, k);
  int p = n * (ull)inv(n + 1) % P;

  int f1 = norm(p + 1), f2 = p,
      g0 = norm(P - p);
  f[0] = mpow(n + 1, n);
  for (int i = 1; i <= k + 2; ++i) {
    int res = g0 * (ull)f[i - 1] % P;
    res = (res + (P - f1) * (ull)(i - 1) % P * f[i - 1]) % P;
    if (i >= 2) res = (res + (P - f2) * (ull)(i - 2) % P * f[i - 2]) % P;
    if (i <= k) f[i] = res * (ull)nv[i] % P;
    else for (int j = 0; j <= i - 1; ++j) {
      int c = res * (ull)binom(i - 1, j) % P;
      if ((i - j - 1) & 1) c = norm(P - c);
      add(d[j], c);
    }
  }

  int q = norm(P + 1 - p);

  for (int i = 0; i <= k; ++i) {
    int v = (i * (ull)q + P - g0) % P;
    if (v) INVS::pb(v);
  }
  INVS::solve();

  int cnt = 0;
  for (int i = 0; i <= k; ++i) {
    if (i * (ull)q % P == g0) {
      cerr << "CRITICAL " << i << '\n';
      for (int j = i; j <= k; ++j) {
        int c = f[j] * (ull)binom(j, i) % P;
        if ((j - i) & 1) c = norm(P - c);
        add(g[i], c);
      }
      continue;
    }
    int res = norm(P - d[i]);
    if (i >= 1) {
      res = (res + (P - p) * (ull)(i - 1) % P * g[i - 1]) % P;
    }
    g[i] = res * (ull)INVS::b[++cnt] % P;
  }
  int ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans = (ans + pw[i] * (ull)g[i]) % P;
  }
  if (k & 1) ans = norm(P - ans);
  cout << ans << '\n';

  return 0;
}