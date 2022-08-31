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

vector<int> BM(const vector<int>& a) {
  vector<int> rec = {1}, crec = {1};
  int l = 0;
  for (int r = 1; r <= a.size(); ++r) {
    int v = 0;
    for (int i = 0; i < rec.size(); ++i) v = (v + rec[i] * (ll)a[r - 1 - i]) % P;
    crec.insert(crec.begin(), 0);
    if (v) {
      vector<int> t = rec;
      if (crec.size() > t.size()) t.resize(crec.size());
      for (int i = 0; i < crec.size(); ++i)
        t[i] = (t[i] + (P - v) * (ll)crec[i]) % P;
      if (l * 2 <= r - 1) {
        crec = rec;
        int nv = inv(v);
        for (int i = 0; i < crec.size(); ++i)
          crec[i] = crec[i] * (ll)nv % P;
        l = r - l;
      }
      swap(rec, t);
    }
  }
  return rec;
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
  vector<string> s(n);
  cin >> s;
  int h = max(n, m);

  /*{
    int L = 100;
    vector<int> f(L);
    for (int i = 1; i != L; ++i) {
      for (int j = 1; j <= i; ++j) {
        int ptot = 1;
        if (j != i) ptot = (i - j + 3) * (ull)inv(4) % P;
        f[i] = (f[i] + j / 2 * (ull)mpow(2, P - 1 - j) % P * ptot) % P;
      }
    }
    cout << BM(f) << '\n' << f << '\n';
  }*/
  int L = 3;
  vector<int> rec = {1, 499122175, 0, 499122177};
  vector<int> f = {0, 0, 748683265};

  f.resize(h + 1);
  for (int i = L; i <= h; ++i) for (int j = 1; j <= L; ++j)
    f[i] = (f[i] + (P - f[i - j]) * (ull)rec[j]) % P;

  int ans = 0, w = 0;
  for (int i = 0; i != n; ++i) {
    int len = 0;
    for (int j = 0; j != m; ++j) if (s[i][j] == 'o') { ++len; ++w; }
    else {
      add(ans, f[len]);
      len = 0;
    }
    add(ans, f[len]);
  }
  for (int j = 0; j != m; ++j) {
    int len = 0;
    for (int i = 0; i != n; ++i) if (s[i][j] == 'o') ++len;
      else {
        add(ans, f[len]);
        len = 0;
      }
    add(ans, f[len]);
  }
  ans = ans * (ull)mpow(2, w) % P;
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}