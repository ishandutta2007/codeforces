#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector <bool> vb;
typedef vector <int> vi;
typedef vector <vi> vvi;

vi bfs(int s, vvi &g) {
  int n = (int)g.size();
  vi d(n, n);
  queue <int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v])
      if (d[v] + 1 < d[u]) {
        d[u] = d[v] + 1;
        q.push(u);
      }
  }
  return d;
}

void dfs(int v, vb &used, vi &order, vvi &g) {
  used[v] = true;
  for (int u : g[v])
    if (!used[u])
      dfs(u, used, order, g);
  order.push_back(v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vvi g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
    }
    vi d = bfs(0, g);
    vvi freeg(n), costg(n), _freeg(n);
    for (int v = 0; v < n; v++)
      for (int u : g[v]) {
        if (d[v] < d[u]) {
          freeg[v].push_back(u);
          _freeg[u].push_back(v);
        } else {
          costg[v].push_back(u);
        }
      }
    vb used(n);
    vi order;
    for (int i = 0; i < n; i++)
      if (!used[i])
        dfs(i, used, order, freeg);
    used.assign(n, false);
    vi distfree(n), ans(n, n + 1);
    for (int i = 0; i < n; i++)
      distfree[i] = d[i];
    vvi comp;
    for (int i = n - 1; i >= 0; i--) {
      int v = order[i];
      if (used[v])
        continue;
      comp.push_back({});
      dfs(v, used, comp.back(), _freeg);
    }
    for (int i = (int)comp.size() - 1; i >= 0; i--) {
      for (int v : comp[i])
        for (int u : freeg[v])
          distfree[v] = min(distfree[v], distfree[u]);
      int res = n;
      for (int v : comp[i])
        res = min(res, distfree[v]);
      for (int v : comp[i])
        distfree[v] = res;
    }
    for (int i = 0; i < n; i++)
      ans[i] = distfree[i];
    for (int i = (int)comp.size() - 1; i >= 0; i--) {
      for (int v : comp[i])
        for (int u : costg[v])
          ans[v] = min(ans[v], distfree[u]);
      for (int v : comp[i])
        for (int u : freeg[v])
          ans[v] = min(ans[v], ans[u]);
      int res = n;
      for (int v : comp[i])
        res = min(res, ans[v]);
      for (int v : comp[i])
        ans[v] = res;
    }
    for (auto &now : ans)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}