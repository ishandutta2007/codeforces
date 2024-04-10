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
typedef unsigned ui;

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

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  ui xsum = 0;
  vector<set<int>> g(n);
  vector<tuple<int, int, int>> ed(m);
  for (int i = 0; i != m; ++i) {
    int u, v; ui w;
    cin >> u >> v >> w;
    --u; --v;
    g[u].insert(v);
    g[v].insert(u);
    ed[i] = make_tuple(w, u, v);
    xsum ^= w;
  }
  sort(ed.begin(), ed.end());
  auto solve0 = [&]() {
    vector<int> f(n);
    function<int(int)> find = [&](int x) { return x == f[x] ? x : f[x] = find(f[x]); };
    set<int> vis;
    for (int i = 0; i != n; ++i) vis.insert(i);
    queue<int> q;
    for (int i = 0; i != n; ++i) {
      if (!vis.count(i)) continue;
      vis.erase(i); q.push(i);
      while (!q.empty()) {
        int u = q.front(); q.pop();
        f[u] = i;
        for (auto it = vis.begin(); it != vis.end();) {
          if (g[u].count(*it)) ++it;
          else {
            q.push(*it); vis.erase(it++);
          }
        }
      }
    }
    ll ans = 0;
    for (const auto& [w, u, v] : ed) {
      int x = find(u), y = find(v);
      if (x != y) {
        f[x] = y;
        ans += w;
      }
    }
    cout << ans << '\n';
  };
  auto solve1 = [&]() {
    ll ans = numeric_limits<ll>::max();
    vector<vector<int>> vis(n, vector<int>(n));
    for (const auto& [z, x, y] : ed) vis[x][y] = vis[y][x] = 1;
    {
      vector<int> f(n); iota(f.begin(), f.end(), 0);
      function<int(int)> find = [&](int x) { return x == f[x] ? x : f[x] = find(f[x]); };
      vector<tuple<int, int, int>> ne;
      for (const auto& [w, u, v] : ed) {
        int x = find(u), y = find(v);
        if (x != y) {
          f[x] = y;
          ne.emplace_back(w, u, v);
        }
      }
      swap(ed, ne);
    }
    auto calc = [&]() {
      vector<int> f(n); iota(f.begin(), f.end(), 0);
      function<int(int)> find = [&](int x) { return x == f[x] ? x : f[x] = find(f[x]); };
      vector<tuple<int, int, int>> ne = ed;
      sort(ne.begin(), ne.end());
      ll ret = 0;
      for (const auto& [w, u, v] : ne) {
        int x = find(u), y = find(v);
        if (x != y) {
          f[x] = y;
          ret += w;
        }
      }
      return ret;
    };
    for (int i = 0; i != n; ++i)
      for (int j = 0; j != i; ++j)
        if (!vis[i][j])
          ed.emplace_back(0, i, j);
    for (int i = 0; i != ed.size(); ++i)
      if (!get<0>(ed[i])) {
        get<0>(ed[i]) = xsum;
        ans = min(ans, calc());
        get<0>(ed[i]) = 0;
      }
    cout << ans << '\n';
  };
  if (n * (n - 1LL) / 2 - m >= n) solve0();
  else solve1();

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}