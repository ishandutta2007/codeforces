// September 14, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<bool> was(n, false);
  int nodes, edges;
  function<void(int)> dfs = [&](int v) {
    nodes++;
    edges += (int) g[v].size();
    for (int u : g[v]) {
      if (!was[u]) {
        was[u] = true;
        dfs(u);
      }
    }
  };
  int sad = 0;
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      nodes = edges = 0;
      was[i] = true;
      dfs(i);
      edges /= 2;
      sad += edges - (nodes - 1);
    }
  }
  cout << sad << '\n';


  return 0;
}