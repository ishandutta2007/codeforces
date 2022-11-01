#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

void dfs (int v, vector <int> &colour, vector <vector <int>> &g) {
  for (int u : g[v]) {
    if (colour[u] != 0)
      continue;
    colour[u] = colour[v];
    dfs(u, colour, g);
  }
}

int main () {
  int n, m;
  cin >> n >> m;
  vector <vector <int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v), g[v].pb(u);
  }
  vector <int> colour(n);
  for (int i = 0; i < n; i++)
    if (g[i].size() == n - 1)
      colour[i] = 2;
  int x = 1;
  for (int i = 0; i < n; i++)
    if (colour[i] == 0) {
      colour[i] = x;
      x += 2;
      if (x == 7) {
        cout << "No\n";
        return 0;
      }
      dfs(i, colour, g);
    }
  bool tf = true;
  vector <vector <bool>> mat(n, vector <bool>(n));
  for (int i = 0; i < n; i++)
    for (int u : g[i])
      mat[i][u] = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if ((colour[i] * colour[j] == 3) ^ mat[i][j] ^ 1)
        tf = false;
    }
  if (!tf) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for (auto &now : colour)
    cout << (char)(now - 1 + 'a');
  return 0;
}