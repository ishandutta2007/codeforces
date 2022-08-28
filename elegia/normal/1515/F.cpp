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

const int N = 300010;

int n, m, x;
ll a[N];
int f[N];
bool vis[N];
vector<pair<int, int>> g[N];
priority_queue<tuple<ll, int, int>> q[N];

int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

void dfs(int u) {
  vis[u] = true;
  for (const auto& [v, id] : g[u]) if (!vis[v]) {
    dfs(v);
    q[u].emplace(a[v], v, id);
  }
  while (!q[u].empty() && get<0>(q[u].top()) + a[u] >= x) {
    ll w; int v, id;
    tie(w, v, id) = q[u].top(); q[u].pop();
    a[u] += a[v] - x;
    cout << id << '\n';
    if (q[u].size() < q[v].size()) swap(q[u], q[v]);
    while (!q[v].empty()) {
      auto tup = q[v].top(); q[v].pop();
      q[u].push(tup);
    }
  }
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> x;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  ll sum = accumulate(a + 1, a + n + 1, 0LL);
  if (sum < x * (n - 1LL)) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  iota(f + 1, f + n + 1, 1);
  for (int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    int a = find(u), b = find(v);
    if (a != b) {
      g[u].emplace_back(v, i);
      g[v].emplace_back(u, i);
      f[a] = b;
    }
  }
  dfs(1);

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}