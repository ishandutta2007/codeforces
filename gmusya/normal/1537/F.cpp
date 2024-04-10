#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

typedef long long ll;

void dfs(int v, vi &col, vvi &g) {
  for (int u : g[v]) {
    if (col[u] != -1) {
      continue;
    }
    col[u] = 1 - col[v];
    dfs(u, col, g);
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
    vi s(n), f(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> f[i];
    }
    vvi g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ll sums = 0, sumf = 0;
    for (int i = 0; i < n; i++) {
      sums += s[i];
      sumf += f[i];
    }
    if ((sums + sumf) % 2) {
      cout << "NO\n";
      continue;
    }
    vi col(n, -1);
    col[0] = 0;
    dfs(0, col, g);
    bool bip = true;
    for (int v = 0; v < n; v++) {
      for (int u : g[v]) {
        if (col[u] == col[v]) {
          bip = false;
        }
      }
    }
    if (!bip) {
      cout << "YES\n";
      continue;
    }
    ll x = 0, y = 0;
    for (int v = 0; v < n; v++) {
      if (col[v] == 0) {
        x += s[v] - f[v];
      } else {
        y += s[v] - f[v];
      }
    }
    cout << (x == y ? "YES\n" : "NO\n");
  }
  return 0;
}