#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector <bool> vb;
typedef vector <int> vi;
typedef vector <vi> vvi;

void dfs1(int v, vb &used, vi &order, vvi &g) {
  used[v] = true;
  for (int u : g[v])
    if (!used[u])
      dfs1(u, used, order, g);
  order.push_back(v);
}

void dfs2(int v, int col, vb &used, vi &comp, vvi &g) {
  used[v] = true;
  comp[v] = col;
  for (int u : g[v])
    if (!used[u])
      dfs2(u, col, used, comp, g);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vvi g(n), _g(n);
  vi p(n), q(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    cin >> q[i];
  for (int i = 0; i + 1 < n; i++) {
    int u = p[i], v = p[i + 1];
    u--, v--;
    g[u].push_back(v);
    _g[v].push_back(u);
  }
  for (int i = 0; i + 1 < n; i++) {
    int u = q[i], v = q[i + 1];
    u--, v--;
    g[u].push_back(v);
    _g[v].push_back(u);
  }
  vb used(n);
  vi order;
  for (int i = 0; i < n; i++)
    if (!used[i])
      dfs1(i, used, order, g);
  used.assign(n, false);
  int cnt = 0;
  vi comp(n);
  for (int i = n - 1; i >= 0; i--) {
    int v = order[i];
    if (used[v])
      continue;
    dfs2(v, cnt, used, comp, _g);
    cnt++;
  }
  vvi cg(cnt);
  for (int v = 0; v < n; v++)
    for (int u : g[v])
      if (comp[u] != comp[v])
        cg[comp[v]].push_back(comp[u]);
  for (int i = 0; i < cnt; i++) {
    sort(cg[i].begin(), cg[i].end());
    cg[i].resize(unique(cg[i].begin(), cg[i].end()) - cg[i].begin());
  }
  vi deg(cnt);
  for (int i = 0; i < cnt; i++)
    for (int j : cg[i])
      deg[j]++;
  if (cnt < k) {
    cout << "NO";
    return 0;
  }
  queue <int> que;
  for (int i = 0; i < cnt; i++)
    if (!deg[i])
      que.push(i);
  vi ans(cnt);
  int it = 0;
  while (!que.empty()) {
    int v = que.front();
    ans[v] = min(it, k - 1);
    it++;
    que.pop();
    for (int u : cg[v]) {
      deg[u]--;
      if (!deg[u])
        que.push(u);
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++)
    cout << (char)(ans[comp[i]] + 'a');
  return 0;
}