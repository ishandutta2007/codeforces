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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

const int P = 998244353;

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a, int mod) {
  int x, y;
  exGcd(a, mod, x, y);
  return (x < 0 ? (x + mod) : x) % mod;
}


int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; ll k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m); cin >> a >> b;
  int gc = gcd(n, m);
  vector<int> pos(2 * max(n, m), -1);
  for (int i = 0; i != n; ++i) pos[--a[i]] = i;
  ll period = n / gc * (ll)m;
  vector<ll> meet(m, -1);

  ll n1 = n / gc, m1 = m / gc, tm = n1 * m1, rn = inv(n1, m1) * n1, rm = inv(m1, n1) * m1;
  for (int i = 0; i != m; ++i) {
    int j = pos[--b[i]];
    if (j == -1) continue;
    if (i % gc != j % gc) continue;
    int i1 = i / gc, j1 = j / gc;
    // M % m1 = i1, M % n1 = j1
    meet[i] = (i1 * rn + j1 * rm) % tm * gc + (i % gc);
  }

  auto calc = [&](ll t) {
    ll sum = 0;
    for (int i = 0; i != m; ++i)
      if (meet[i] != -1) {
        if (t > meet[i]) sum += (t - meet[i] - 1) / period + 1;
      }
    return sum;
  };

  ll low = 0, high = 1LL << 60;
  while (low < high) {
    ll mid = (low + high) / 2;
    if (mid - calc(mid) < k) low = mid + 1;
    else high = mid;
  }
  cout << low << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}