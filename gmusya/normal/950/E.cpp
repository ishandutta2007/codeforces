#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vector <bool> used;
vvi g, _g;

void dfs(int v, vi &ord, vvi &g) {
  used[v] = true;
  for (int u : g[v])
    if (!used[u])
      dfs(u, ord, g);
  ord.push_back(v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, h;
  cin >> n >> m >> h;
  vi t(n);
  g.assign(2 * n, {}), _g.assign(2 * n, {});
  for (int i = 0; i < n; i++)
    cin >> t[i];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int h1 = t[u], h2 = t[v];
    u *= 2, v *= 2;
    if ((h1 + 1) % h == h2) {
      g[u + 1].push_back(v + 1);
      _g[v + 1].push_back(u + 1);
      g[v].push_back(u);
      _g[u].push_back(v);
    }
    if ((h2 + 1) % h == h1) {
      g[v + 1].push_back(u + 1);
      _g[u + 1].push_back(v + 1);
      g[u].push_back(v);
      _g[v].push_back(u);
    }
  }
  used.assign(2 * n, false);
  vi ord, col(2 * n);
  vvi comp;
  for (int i = 0; i < 2 * n; i++)
    if (!used[i])
      dfs(i, ord, g);
  int cnt = 0;
  used.assign(2 * n, false);
  for (int i = 2 * n - 1; i >= 0; i--) {
    int v = ord[i];
    if (used[v])
      continue;
    comp.push_back({});
    dfs(v, comp.back(), _g);
    for (int u : comp.back())
      col[u] = cnt;
    cnt++;
  }
  int id = -1;
  for (int i = 0; i < cnt; i++) {
    if (comp[i][0] % 2 == 0)
      continue;
    bool tf = true;
    for (int v : comp[i])
      for (int u : g[v])
        if (col[u] != col[v])
          tf = false;
    if (tf && (id == -1 || comp[i].size() < comp[id].size()))
      id = i;
  }
  cout << comp[id].size() << '\n';
  for (auto &now : comp[id])
    cout << (now + 1) / 2 << ' ';
  return 0;
}