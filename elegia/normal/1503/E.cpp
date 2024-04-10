/*
_/_/_/_/    _/_/_/_/_/  _/_/_/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/  _/  _/
_/      _/  _/  _/    _/    _/_/
_/_/_/_/      _/_/     _/_/_/_/_/

_/_/_/_/    _/    _/  _/      _/
_/      _/   _/  _/   _/_/  _/_/
_/      _/    _/_/    _/ _/_/ _/
_/      _/     _/     _/  _/  _/
_/      _/    _/_/    _/      _/
_/      _/   _/  _/   _/      _/
_/_/_/_/    _/    _/  _/      _/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
*/
#include <cassert>
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
#include <iomanip>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int P = 998244353;

int norm(int x) { return x >= P ? (x - P) : x; }

void add(int &x, int y) { if ((x += y) >= P) x -= P; }

void sub(int &x, int y) { if ((x -= y) < 0) x += P; }

void exGcd(int a, int b, int &x, int &y) {
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
      fac[x] = fac[x - 1] * (ll) x % P;
    inv[1] = 1;
    for (int x = 2; x <= n; ++x)
      inv[x] = -(P / x) * (ll) inv[P % x] % P + P;
    ifac[0] = 1;
    for (int x = 1; x <= n; ++x)
      ifac[x] = ifac[x - 1] * (ll) inv[x] % P;
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
    return gfac(n) * (ll) gifac(m) % P * gifac(n - m) % P;
  }
} simp;

const int N = 2050;

int corn(int x, int y) { return simp.binom(x + y, x); }

int calF(int n, int m) {
  int ret = 0;
  for (int i = 1; i != n; ++i) {
    int sum = 0;
    for (int j = 1; j != m; ++j) {
      ret = (ret + sum * (ull) corn(n - i - 1, j) % P * corn(n - i, m - j - 1)) %
            P;
      sum = (sum + corn(i, j - 1) * (ull) corn(i - 1, m - j)) % P;
    }
  }
  return ret;
}

int calG(int n, int m) {
  int ret = 0;
  for (int i = 1; i != n; ++i)
    for (int j = 1; j != m; ++j) {
      ret = (ret + corn(i, j - 1) * (ull) corn(i - 1, m - j) % P * corn(n - i - 1, j) % P * corn(n - i, m - j - 1)) % P;
    }
  return ret;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int ans = 0;
  add(ans, calF(n, m));
  add(ans, calF(m, n));
  add(ans, calG(n, m));
  add(ans, ans);
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}