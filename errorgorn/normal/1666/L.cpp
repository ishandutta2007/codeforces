#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, s;
  cin >> n >> m >> s;
  s--;
  vector<vector<int>> adj(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
  }
  vector<map<int, int>> par(n);
  const auto Dfs = [&](const auto &self, int u, int p, int st) -> void {
    if (par[u].count(st)) return;
    if (st != -1) par[u][st] = p;
    if (u != s && par[u].size() == 2) {
      cout << "Possible\n";
      vector<vector<int>> X;
      for (auto [t, prv] : par[u]) {
        X.emplace_back();
        int x = u;
        while (x != s) {
          X.back().emplace_back(x);
          x = par[x][t];
        }
        X.back().emplace_back(s);
      }
      assert(X.size() == 2);
      for (auto i : X) {
        cout << i.size();
        reverse(begin(i), end(i));
        for (auto j : i) {
          cout << ' ' << j + 1;
        }
        cout << '\n';
      }
      exit(0);
    }
    for (auto v : adj[u]) {
      if (v != s) {
        self(self, v, u, st == -1 ? v : st);
      }
    }
  };
  Dfs(Dfs, s, -1, -1);
  cout << "Impossible\n";
  return 0;
}