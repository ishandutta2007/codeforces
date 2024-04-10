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
#include <stack>
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

const int N = 200010;

int n;
vector<pair<int, int>> g[N];
ll dis[N], val[N];
int low[N], dfn[N], scc[N];
bool ins[N];

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void dfs(int u) {
  static int t, scn;
  static stack<int> stk;
  dfn[u] = low[u] = ++t;
  ins[u] = true;
  stk.push(u);
  for (const auto& [v, w] : g[u]) {
    if (!dfn[v]) {
      dis[v] = dis[u] + w;
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v]) low[u] = min(low[u], low[v]);
  }
  if (low[u] != dfn[u]) return;
  vector<int> cur;
  ll tot = 0;
  ++scn;
  while (true) {
    int v = stk.top(); stk.pop();
    cur.push_back(v);
    scc[v] = scn;
    ins[v] = false;
    low[v] = dfn[u];
    if (v == u) break;
  }
  for (int u : cur) for (const auto& [v, w] : g[u]) if (scc[u] == scc[v])
    tot = gcd(tot, dis[u] + w - dis[v]);
  for (int v : cur) val[v] = tot;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m; cin >> n >> m;
  while (m--) {
    int a, b, l; cin >> a >> b >> l;
    g[a].emplace_back(b, l);
  }
  for (int i = 1; i <= n; ++i) if (!dfn[i]) dfs(i);
  int q; cin >> q;
  while (q--) {
    int v, s, t; cin >> v >> s >> t;
    t = gcd(val[v], (ll)t);
    if (s % t == 0) cout << "YES\n";
    else cout << "NO\n";
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}