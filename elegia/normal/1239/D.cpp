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
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) // fprintf(stderr, FMT)

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

const int N = 1000010;

int n, m;
vector<int> g[N];
int dfn[N], low[N], scc[N], cnt[N], cn[N];
bool gg;
bool ins[N];

int t;
stack<int> stk;

void dfs(int u) {
  LOG("DFS %d %lu\n", u, g[u].size());
  dfn[u] = low[u] = ++t;
  ins[u] = true;
  stk.push(u);
  for (int v : g[u]) {
    LOG("%d->%d\n", u, v);
    if (!dfn[v])
      dfs(v);
    if (ins[v])
      low[u] = min(low[u], low[v]);
  }
  if (low[u] == dfn[u]) {
    int v;
    do {
      v = stk.top();
      stk.pop();
      ins[v] = false;
      scc[v] = u;
      ++cnt[u];
    } while (v != u);
    if (cnt[u] == n)
      gg = true;
    else
      LOG("%d: %d (%d)\n", u, cnt[u], n);
  }
}


void solve() {
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    LOG("INPUT %d %d\n", u, v);
    if (u != v)
      g[u].push_back(v);
    LOG("SZ %d\n", (int)g[u].size());
  }

  for (int i = 1; i <= n; ++i) {
    LOG("VERTEX %d: %lu\n", i, g[i].size());
  }

  t = 0;
  stk = stack<int>();
  gg = false;
  for (int i = 1; i <= n; ++i)
    if (!dfn[i])
      dfs(i);

  if (gg) {
    cout << ("NO\n");
    for (int i = 1; i <= n; ++i)
      g[i].clear();
    fill(dfn + 1, dfn + n + 1, 0);
    fill(low + 1, low + n + 1, 0);
    fill(cnt + 1, cnt + n + 1, 0);
    fill(cn + 1, cn + n + 1, 0);
    fill(ins + 1, ins + n + 1, false);
    fill(scc + 1, scc + n + 1, 0);
    return;
  }
  cout << ("YES\n");
  for (int i = 1; i <= n; ++i)
    for (int j : g[i])
      if (scc[i] != scc[j])
        ++cn[scc[j]];
  for (int i = 1; i <= n; ++i)
    if (scc[i] == i && cn[i] == 0) {
      cout << n - cnt[i] << ' ' << cnt[i] << '\n';
      for (int j = 1; j <= n; ++j)
        if (scc[j] != i)
          cout << j << ' ';
      cout << '\n';
      for (int j = 1; j <= n; ++j)
        if (scc[j] == i)
          cout << j << ' ';
      cout << '\n';
      break;
    }

  for (int i = 1; i <= n; ++i)
    g[i].clear();
  fill(dfn + 1, dfn + n + 1, 0);
  fill(low + 1, low + n + 1, 0);
  fill(cnt + 1, cnt + n + 1, 0);
  fill(cn + 1, cn + n + 1, 0);
  fill(ins + 1, ins + n + 1, false);
  fill(scc + 1, scc + n + 1, 0);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}