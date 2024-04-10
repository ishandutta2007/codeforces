#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int n;

vi ans;
vi c;
vi sz;
vvi g;

void dfs(int v, int p = -1) {
  sz[v] = 1;
  for (int u : g[v])
    if (u != p) {
      dfs(u, v);
      sz[v] += sz[u];
    }
}

void dfs2(int v, int cursz, int p = -1) {
  if (cursz <= n / 2)
    ans[v] = 1;
  for (int u : g[v])
    if (u != p)
      dfs2(u, cursz + sz[v] - sz[u], v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  g.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (n <= 2) {
    for (int i = 0; i < n; i++)
      cout << 1 << ' ';
    return 0;
  }
  sz.resize(n);
  dfs(0);
  for (int v = 0; v < n; v++) {
    sort(g[v].begin(), g[v].end(), [&](int i, int j) {
      int szi = (sz[i] < sz[v] ? sz[i] : n - sz[v]);
      int szj = (sz[j] < sz[v] ? sz[j] : n - sz[v]);
      return szi > szj;
    });
    int k = (sz[g[v][0]] < sz[v] ? sz[g[v][0]] : n - sz[v]);
    if (k <= n / 2)
      c.push_back(v);
  }
  if (c.size() == 2) {
    for (int i = 0; i < n; i++)
      cout << 1 << ' ';
    return 0;
  }
  ans.resize(n);
  dfs(c[0]);
  for (int v = 0; v < n; v++)
    sort(g[v].begin(), g[v].end(), [&](int i, int j) {
        int szi = (sz[i] < sz[v] ? sz[i] : n - sz[v]);
        int szj = (sz[j] < sz[v] ? sz[j] : n - sz[v]);
        return szi > szj;
    });
  for (int i = 1; i < (int)g[c[0]].size(); i++)
    dfs2(g[c[0]][i], n - sz[g[c[0]][0]] - sz[g[c[0]][i]], c[0]);
  dfs2(g[c[0]][0], n - sz[g[c[0]][0]] - sz[g[c[0]][1]], c[0]);
  ans[c[0]] = 1;
  for (auto &now : ans)
    cout << now << ' ';
  return 0;
}