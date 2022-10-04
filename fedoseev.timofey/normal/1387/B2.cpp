#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector <int> g[N];
int sz[N];
int n;

ll ans = 0;
int c = -1;

void dfs(int u, int p) {
  sz[u] = 1;
  bool ok = true;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
      ok &= (2 * sz[v] <= n);
    }
  }
  ok &= (2 * (n - sz[u]) <= n);
  if (ok) c = u;
  ans += 2 * min(sz[u], n - sz[u]);
}

vector <int> cmp;

void jhfs(int u, int p) {
  cmp.push_back(u);
  for (auto v : g[u]) {
    if (v != p) {
      jhfs(v, u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  cout << ans << '\n';
  assert(c != -1);
  vector <vector <int>> gs;
  for (auto v : g[c]) {
    cmp.clear();
    jhfs(v, c);
    gs.push_back(cmp);
  }
  vector <int> cycle; 
  set <pair <int, int>> have;
  int m = gs.size();
  vector <int> sz(m);
  for (int i = 0; i < m; ++i) {
    sz[i] = (int)gs[i].size();
    have.insert({sz[i], i});
  }
  int lst = -1;
  while (!have.empty()) {
    auto p = *have.rbegin();
    int col = -1;
    if (lst == p.second) {
      assert(have.size() > 1);
      col = prev(prev(have.end()))->second;
    } else {
      col = p.second;
    }
    have.erase({sz[col], col});
    cycle.push_back(gs[col].back());
    gs[col].pop_back();
    --sz[col];
    if (sz[col] > 0) {
      have.insert({sz[col], col});
    }
    lst = col;
  }
  cycle.push_back(c);
  vector <int> go(n);
  for (int i = 0; i < (int)cycle.size(); ++i) {
    go[cycle[i]] = cycle[(i + 1) % (int)cycle.size()];
  }
  for (int i = 0; i < n; ++i) {
    cout << go[i] + 1 << ' ';
  }
}