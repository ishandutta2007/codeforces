#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int n;
int c1 = 0, c2 = 0, ans = 0;
vi c;
vi sz1, sz2;
vvi g;

void dfs(int v, int p = -1) {
  sz1[v] = (c[v] == 1);
  sz2[v] = (c[v] == 2);
  for (int u : g[v]) {
    if (u == p)
      continue;
    dfs(u, v);
    sz1[v] += sz1[u];
    sz2[v] += sz2[u];
  }
  for (int u : g[v]) {
    if (u == p)
      continue;
    if ((sz1[u] == c1 && sz2[u] == 0) || (sz2[u] == c2 && sz1[u] == 0))
      ans++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  c.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    if (c[i] == 1)
      c1++;
    if (c[i] == 2)
      c2++;
  }
  g.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  sz1.resize(n), sz2.resize(n);
  dfs(0);
  cout << ans;
  return 0;
}