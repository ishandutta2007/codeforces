#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <bool> vb;
typedef vector <int> vi;
typedef vector <vi> vvi;

void dfs(int v, vi &colv, vi &to, vi &cole, vvi &g) {
  colv[v] = 1;
  for (int i : g[v]) {
    int u = to[i];
    if (colv[u] == 0) {
      dfs(u, colv, to, cole, g);
      cole[i] = 1;
      continue;
    }
    cole[i] = 3 - colv[u];
  }
  colv[v] = 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi g(n);
  vi to(m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(i);
    to[i] = v;
  }
  vi cole(m, 0), colv(n);
  for (int v = 0; v < n; v++)
    if (colv[v] == 0)
      dfs(v, colv, to, cole, g);
  cout << *max_element(cole.begin(), cole.end()) << '\n';
  for (auto &now : cole)
    cout << now << ' ';
  return 0;
}