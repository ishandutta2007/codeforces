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

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

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

void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int quo2(int x) { return ((x & 1) ? (x + P) : x) >> 1; }

const int _ = 1000006;
int fac[_], ifac[_], phi[_];
int a[_];

int Gcd(int x, int y) { return y ? Gcd(y, x % y) : x; }

void pre(int N) {
  fac[0] = 1; for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * (ull)i % P;
  ifac[N] = inv(fac[N]); for (int i = N; i; --i) ifac[i - 1] = ifac[i] * (ull)i % P;
  for (int i = 1; i <= N; ++i) phi[i] = i;
  for (int i = 1; i <= N; ++i) for (int j = i + i; j <= N; j += i) phi[j] -= phi[i];
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pre(1e6);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    fill(a + 1, a + N + 1, 0);
    for (int rep = 0; rep != N; ++rep) {
      int ai; cin >> ai; ++a[ai];
    }
    vector<int> vec;
    int G = 0;
    for (int i = 1; i <= N; ++i)
      if (a[i]) {
        vec.push_back(a[i]);
        G = Gcd(G, a[i]);
      }
    if (vec.size() == 1) {
      cout << "1\n";
      continue;
    }
    int sum = 0, cnt = 0;
    for (int d = 1; d <= G; ++d)
      if (G % d == 0) {
        int wayc = fac[N / d], ways = 0;
        for (int x : vec) wayc = wayc * (ull)ifac[x / d] % P;
        ways = 1;
        for (int x : vec) if (x / d > 1) ways = (ways + (P - fac[x / d]) * (ull)ifac[x / d - 2] % P * ifac[N / d] % P * fac[N / d - 2]) % P;
        ways = ways * (ull)wayc % P * N % P;
        fam(cnt, phi[d], wayc);
        fam(sum, phi[d], ways);
      }
    cout << (sum * (ull)inv(cnt) % P) << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}