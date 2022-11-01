#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
vector <int> sz;
ll ansmin = 0, ansmax = 0;
vector <vector <pair <int, ll>>> g;

void dfs(int v, int p = -1) {
  for (auto [u, w] : g[v]) {
    if (u == p)
      continue;
    dfs(u, v);
    sz[v] += sz[u];
    ansmax += min(2 * n - sz[u], sz[u]) * 1ll * w;
    ansmin += w * (sz[u] % 2);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ansmax = ansmin = 0;
    cin >> n;
    g.assign(2 * n, {});
    for (int i = 1; i < 2 * n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    sz.assign(2 * n, 1);
    dfs(0);
    cout << ansmin << ' ' << ansmax << '\n';
  }
  return 0;
}