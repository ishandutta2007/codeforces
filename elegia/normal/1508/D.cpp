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

struct Vec {
  int x, y;

  Vec(int x = 0, int y = 0) : x(x), y(y) {}

  Vec operator-(const Vec& v) const { return Vec(x - v.x, y - v.y); }

  ll operator*(const Vec& rhs) const { return x * (ll)rhs.y - y * (ll)rhs.x; }

  int region() const {
    if (y > 0 || (y == 0 && x > 0)) return 0;
    return 1;
  }
};

bool cmp(const Vec& lhs, const Vec& rhs) {
  if (lhs.region() != rhs.region()) return lhs.region() < rhs.region();
  return (lhs * rhs) > 0;
}

const int N = 2010;

int x[N], y[N], a[N];
Vec p[N];
int f[N], id[N];

vector<pair<int, int>> ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> a[i];

  int o = 0;
  for (int i = 1; i <= n; ++i) if (a[i] != i) { o = i; break; }
  if (!o) return;

  int m = 0;
  for (int i = 1; i <= n; ++i) if (i != o) p[++m] = Vec(x[i] - x[o], y[i] - y[o]);
  sort(p + 1, p + n, cmp);
  for (int i = 2; i != n; ++i) if (p[i - 1] * p[i] < 0) {
    //cerr << O.x << ' ' << O.y << " -> " << p[i - 1].x << ' ' << p[i - 1].y << ", " << p[i].x << ' ' << p[i].y << '\n';
    rotate(p + 1, p + i, p + n);
    break;
  }
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= n; ++i) mp[make_pair(x[i] - x[o], y[i] - y[o])] = i;
  for (int i = 1; i != n; ++i) id[i] = mp[make_pair(p[i].x, p[i].y)];
  for (int i = 1; i <= n; ++i) {
    if (f[i]) continue;
    int j = i;
    while (!f[j]) {
      f[j] = i;
      j = a[j];
    }
  }
  auto PB = [&](int i, int j) {
    ans.emplace_back(i, j);
    swap(a[i], a[j]);
  };
  for (int r = 2; r != n; ++r) {
    int i = id[r - 1], j = id[r];
    int u = find(i), v = find(j);
    if (u != v) {
      f[u] = v;
      PB(i, j);
    }
  }
  while (a[o] != o) PB(o, a[o]);
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  cout << ans.size() << '\n';
  for (const auto& [i, j] : ans) cout << i << ' ' << j << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}