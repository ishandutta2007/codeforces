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

template<class Z>
struct MaxFlow {
  vector<vector<tuple<int, int, Z>>> g;

  struct Ref {
    const MaxFlow *p;
    int u, id;

    Ref() {}

    Ref(const MaxFlow *p, int u, int id) : p(p), u(u), id(id) {}

    Z get() const { return std::get<2>((p->g)[u][id]); }
  };

  MaxFlow() {}

  MaxFlow(int n) : g(n) {}

  Ref addEdge(int u, int v, const Z &w) {
    if (u == v) return Ref();
    int ru = g[u].size(), rv = g[v].size();
    g[u].emplace_back(v, rv, w);
    g[v].emplace_back(u, ru, 0);
    return Ref(this, v, rv);
  }

  Z dinic(int s, int t) {
    int n = g.size();
    function<vector<int>()> getLevel = [&]() {
      vector<int> level(n, -1);
      queue<int> q;
      level[s] = 0;
      q.push(s);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &pr : g[u])
          if (get<2>(pr) && level[get<0>(pr)] == -1) {
            level[get<0>(pr)] = level[u] + 1;
            q.push(get<0>(pr));
          }
      }
      return level;
    };
    vector<int> r, level;
    function<Z(int, Z)> cap = [&](int u, Z limit) {
      if (u == t) return limit;
      Z ret = 0;
      while (r[u] && limit > ret) {
        int v = get<0>(g[u][r[u] - 1]), rev = get<1>(g[u][r[u] - 1]);
        Z &w = get<2>(g[u][r[u] - 1]);
        if (level[v] == level[u] + 1) {
          Z flow = cap(v, min(limit - ret, w));
          ret += flow;
          w -= flow;
          get<2>(g[v][rev]) += flow;
          if (limit == ret)
            return ret;
          --r[u];
        } else
          --r[u];
      }
      return ret;
    };
    Z ret = 0;
    while (level = getLevel(), level[t] != -1) {
      r = vector<int>(n);
      for (int i = 0; i < n; ++i)
        r[i] = g[i].size();
      ret += cap(s, numeric_limits<Z>::max());
    }
    return ret;
  }
};

const int _ = 50005;

int id[_], a[_];
vector<int> factor[_];

void pre(int N) {
  memset(id, -1, sizeof(id));
  for (int i = 1; i <= N; ++i)
    for (int j = i + i; j <= N; j += i) factor[j].push_back(i);
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pre(5e4);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    for (int i = 0; i != N; ++i) { cin >> a[i]; id[a[i]] = i; }
    MaxFlow<int> flow(N * 4 + 2);
    int s = N * 4, t = s + 1;
    for (int i = 0; i != N; ++i) {
      flow.addEdge(s, i * 4, 1);
      flow.addEdge(i * 4 + 1, i * 4 + 2, 1);
      flow.addEdge(i * 4 + 3, t, 1);
    }
    for (int i = 0; i != N; ++i)
      for (int d : factor[a[i]])
        if (id[d] != -1) {
          int j = id[d];
          flow.addEdge(i * 4, j * 4 + 1, 1e9);
          flow.addEdge(i * 4 + 2, j * 4 + 3, 1e9);
        }
    cout << flow.dinic(s, t) << '\n';
    for (int i = 0; i != N; ++i) id[a[i]] = -1;
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}