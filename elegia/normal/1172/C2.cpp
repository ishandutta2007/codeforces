#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200010, M = 3010, P = 998244353;

int pre[M * 2];

int mpow(int x, int k, int p = P) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % p;
    x = x * (ll)x % p;
    k >>= 1;
  }
  return ret;
}

struct NumberTheory {

  typedef pair<int, int> _P2_Field;

  mt19937 rng;

  NumberTheory() : rng(chrono::steady_clock::now().time_since_epoch().count()) {}

  void _exGcd(int a, int b, int& x, int& y) {
    if (!b) {
      x = 1;
      y = 0;
      return;
    }
    _exGcd(b, a % b, y, x);
    y -= a / b * x;
  }

  int inv(int a, int p = P) {
    int x, y;
    _exGcd(a, p, x, y);
    if (x < 0)
      x += p;
    return x;
  }

  template <class Integer>
  bool quadRes(Integer a, Integer b) {
    if (a <= 1)
      return true;
    while (a % 4 == 0)
      a /= 4;
    if (a % 2 == 0)
      return (b % 8 == 1 || b % 8 == 7) == quadRes(a / 2, b);
    return ((a - 1) % 4 == 0 || (b - 1) % 4 == 0) == quadRes(b % a, a);
  }

  // assume p in prime, x in quadratic residue
  int sqrt(int x, int p = P) {
    if (p == 2 || x <= 1)
      return x;
    int w, v, k = (p + 1) / 2;
    do {
      w = rng() % p;
    } while (quadRes(v = int((w * (ll)w - x + p) % p), p));
    _P2_Field res(1, 0), a(w, 1);
    while (k) {
      if (k & 1)
        res = _P2_Field((res.first * (ll)a.first + res.second * (ll)a.second % p * v) % p, (res.first * (ll)a.second + res.second * (ll)a.first) % p);
      if (k >>= 1)
        a = _P2_Field((a.first * (ll)a.first + a.second * (ll)a.second % p * v) % p, (a.first * (ll)a.second << 1) % p);
    }
    return min(res.first, p - res.first);
  }

} nt;

int n, m, x, y;
int a[N], w[N];
int f[M][M], g[M][M];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &w[i]);
  for (int i = 1; i <= n; ++i)
    if (a[i] == 0)
      y += w[i];
    else
      x += w[i];
  for (int i = 0; i <= m; ++i)
    f[i][m - i] = 1;
  for (int i = 0; i <= m * 2; ++i)
    pre[i] = nt.inv(x + y + i - m);
  for (int k = m - 1; k >= 0; --k) {
    for (int i = 0; i <= k; ++i) {
      int j = k - i;
      if (x + y + i - j > 0)
        f[i][j] = (f[i + 1][j] * (ll)(x + i) + f[i][j + 1] * (ll)(y - 1 - j)) % P * pre[m + i - j] % P;
    }
  }
  int e1 = 0;
  for (int i = 0; i <= m; ++i)
    for (int j = 0; i + j <= m; ++j) {
      if (i == 0 && j == 0) {
        g[i][j] = 1;
        continue;
      }
      if (j > y)
        continue;
      if (i)
        g[i][j] = (g[i][j] + g[i - 1][j] * (ll) (x + i - 1) % P * pre[m + i - 1 - j]) % P;
      if (j)
        g[i][j] = (g[i][j] + g[i][j - 1] * (ll) (y - (j - 1)) % P * pre[m + i - j + 1]) % P;
      if (i + j == m) {
        e1 = (e1 + g[i][j] * (ll) i) % P;
      }
    }
  e1 = (e1 * (ll)nt.inv(x) + 1) % P;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0)
      printf("%lld\n", w[i] * (ll)f[0][0] % P);
    else
      printf("%lld\n", w[i] * (ll)e1 % P);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}