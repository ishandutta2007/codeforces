#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

typedef vector <bool> vb;
typedef vector <int> vi;
typedef vector <vi> vvi;

vb used;
vi c;
vvi g;

void dfs(int v, int col) {
  used[v] = true;
  c[col]++;
  for (int u : g[v]) {
    if (used[u])
      continue;
    dfs(u, col);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    g.assign(n, {});
    vi deg(n);
    for (int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
      deg[u]++, deg[v]++;
    }
    vb leaves(n);
    queue <int> q;
    for (int v = 0; v < n; v++)
      if (deg[v] == 1) {
        q.push(v);
        leaves[v] = true;
      }
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : g[v]) {
        if (leaves[u])
          continue;
        deg[u]--;
        if (deg[u] == 1) {
          leaves[u] = true;
          q.push(u);
        }
      }
    }
    c.assign(n, 0);
    used.assign(n, false);
    for (int v = 0; v < n; v++) {
      if (used[v] || leaves[v])
        continue;
      used[v] = true;
      c[v]++;
      for (int u : g[v])
        if (leaves[u] && !used[u])
          dfs(u, v);
    }
    ll ans = 0;
    for (ll sz : c) {
      ans += sz * (sz - 1) / 2;
      ans += sz * (n - sz);
    }
    cout << ans << '\n';
  }
  return 0;
}