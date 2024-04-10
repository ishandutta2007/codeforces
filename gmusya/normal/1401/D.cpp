#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

void dfs(int v, int p, vector <long long> &sz, vector <vector <int>> &g, vector <long long> &w) {
  sz[v] = 1;
  for (int u : g[v])
    if (u != p) {
      dfs(u, v, sz, g, w);
      sz[v] += sz[u];
      w.push_back(sz[u] * (g.size() - sz[u]));
    }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <int>> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    vector <long long> sz(n), w;
    dfs(0, -1, sz, g, w);
    int m;
    cin >> m;
    vector <long long> p(m);
    for (int i = 0; i < m; i++)
      cin >> p[i];
    while (p.size() < n - 1) p.push_back(1);
    sort(p.begin(), p.end());
    while (p.size() > n - 1) {
      p[p.size() - 2] = p[p.size() - 2] * p[p.size() - 1] % MOD;
      p.pop_back();
    }
    long long ans = 0;
    sort(w.begin(), w.end());
    for (int i = 0; i < n - 1; i++)
      ans = (ans + w[i] * p[i]) % MOD;
    cout << ans << '\n';
  }
  return 0;
}