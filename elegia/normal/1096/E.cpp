#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 110, X = 5010, P = 998244353;

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
  return x < 0 ? x + P : x;
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

struct Simple {
  int n;
  vector<int> fac, ifac, inv;

  void build(int n) {
    this->n = n;
    fac.resize(n + 1);
    ifac.resize(n + 1);
    inv.resize(n + 1);
    fac[0] = 1;
    for (int x = 1; x <= n; ++x)
      fac[x] = fac[x - 1] * (ll)x % P;
    inv[1] = 1;
    for (int x = 2; x <= n; ++x)
      inv[x] = -(P / x) * (ll)inv[P % x] % P + P;
    ifac[0] = 1;
    for (int x = 1; x <= n; ++x)
      ifac[x] = ifac[x - 1] * (ll)inv[x] % P;
  }

  Simple() {
    build(1);
  }

  void check(int k) {
    int nn = n;
    if (k > nn) {
      while (k > nn)
        nn <<= 1;
      build(nn);
    }
  }

  int gfac(int k) {
    check(k);
    return fac[k];
  }

  int gifac(int k) {
    check(k);
    return ifac[k];
  }

  int ginv(int k) {
    check(k);
    return inv[k];
  }

  int binom(int n, int m) {
    if (m < 0 || m > n)
      return 0;
    return gfac(n) * (ll)gifac(m) % P * gifac(n - m) % P;
  }
} simp;

int n, x, r;

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d", &n, &x, &r);
  if (x == 0 || n == 1) {
    printf("%d\n", inv(n));
    return 0;
  }
  int ans = 0, cnt = simp.binom(x - r + n - 1, n - 1);
  r = max(1, r);
  for (int b = r; b <= x; ++b) {
    for (int m = 1; m < n; ++m) {
      if (b * m > x)
        break;
      int k = x - b * m;
      int res = 0;
      // [z^k]((1-z^b)/(1-z))^(n-m)
      for (int i = 0; i * b <= k; ++i)
        res = (res + ((i & 1) ? (P - 1) : 1) * (ll)simp.binom(n - m, i) % P * simp.binom(n - m + (k - i * b) - 1, n - m - 1) % P) % P;
      ans = (ans + res * (ll)simp.ginv(m) % P * simp.binom(n - 1, m - 1)) % P;
    }
    if (b * n == x)
      ans = (ans + simp.ginv(n)) % P;
  }
  printf("%d\n", int(ans * (ll)inv(cnt) % P));

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}