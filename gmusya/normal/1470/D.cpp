#include <iostream>
#include <deque>
#include <vector>

using namespace std;

typedef vector <bool> vb;
typedef vector <int> vi;
typedef vector <vi> vvi;

void dfs(int v, vb &used, vi &color, vvi &g, int &cnt) {
  cnt++;
  used[v] = true;
  if (color[v] == 1) {
    for (int u : g[v])
      color[u] = 0;
    for (int u : g[v]) {
      if (used[u])
        continue;
      dfs(u, used, color, g, cnt);
    }
    return;
  }
  for (int u : g[v]) {
    if (color[u] != -1)
      continue;
    color[u] = 1;
    dfs(u, used, color, g, cnt);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vb used(n);
    vi color(n, -1);
    int cnt = 0;
    color[0] = 1;
    dfs(0, used, color, g, cnt);
    if (cnt != n) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vi ans;
    for (int v = 0; v < n; v++)
      if (color[v] == 1)
        ans.push_back(v + 1);
    cout << ans.size() << '\n';
    for (auto &now : ans)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}