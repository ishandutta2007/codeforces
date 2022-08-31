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

const int P = 31607;

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

const int I = inv(10000);

const int N = 21;

int n;
int a[N][N], r[N][N];
int prod[N], cnt[N][N];
int ans;

void dfs(int i, int sgn) {
  if (i == n + 2) {
    for (int j = 0; j != n; ++j) sgn = sgn * (P + 1 - prod[j]) % P;
    add(ans, sgn);
    return;
  }
  if (i < n) {
    dfs(i + 1, sgn);
    for (int j = 0; j != n; ++j) {
      prod[j] = prod[j] * r[i][j] % P;
      ++cnt[i][j];
      sgn = sgn * a[i][j] % P;
    }
    dfs(i + 1, P - sgn);
    for (int j = 0; j != n; ++j) {
      prod[j] = prod[j] * a[i][j] % P;
      --cnt[i][j];
    }
    return;
  }
  if (i == n) {
    dfs(i + 1, sgn);
    for (int j = 0; j != n; ++j)
      if (cnt[j][j]++ == 0) {
        prod[j] = prod[j] * r[j][j] % P;
        sgn = sgn * a[j][j] % P;
      }
    dfs(i + 1, P - sgn);
    for (int j = 0; j != n; ++j)
      if (--cnt[j][j] == 0) {
        prod[j] = prod[j] * a[j][j] % P;
      }
    return;
  }
  dfs(i + 1, sgn);
  for (int j = 0; j != n; ++j)
    if (cnt[n - 1 - j][j]++ == 0) {
      prod[j] = prod[j] * r[n - 1 - j][j] % P;
      sgn = sgn * a[n - 1 - j][j] % P;
    }
  dfs(i + 1, P - sgn);
  for (int j = 0; j != n; ++j)
    if (--cnt[n - 1 - j][j] == 0) {
      prod[j] = prod[j] * a[n - 1 - j][j] % P;
    }
  return;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  fill(prod, prod + n, 1);
  for (int i = 0; i != n; ++i)
    for (int j = 0; j != n; ++j) {
      cin >> a[i][j];
      a[i][j] = a[i][j] * I % P;
      prod[j] = prod[j] * a[i][j] % P;
      r[i][j] = inv(a[i][j]);
    }
  dfs(0, 1);
  ans = (P + 1 - ans) % P;
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}