// September 6, 2020
// https://codeforces.com/contest/1404/problem/B

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1404B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1404B.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--; b--;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> depth(n);
    function<void (int, int)> Dfs = [&](int v, int p) {
      for (int u : g[v]) {
        if (u == p) {
          continue;
        }
        depth[u] = depth[v] + 1;
        Dfs(u, v);
      }
    };
    auto DoDfsFrom = [&](int v) {
      fill(depth.begin(), depth.end(), -1);
      depth[v] = 0;
      Dfs(v, -1);
    };
    DoDfsFrom(a);
    bool ok = false;
    if (depth[b] <= da) {
      ok = true;
    }
    int u = max_element(depth.begin(), depth.end()) - depth.begin();
    DoDfsFrom(u);
    int v = max_element(depth.begin(), depth.end()) - depth.begin();
    int diameter = depth[v];
    da = min(da, diameter);
    db = min(db, diameter);
    if (2 * da >= diameter) {
      ok = true;
    }
    if (db <= 2 * da) {
      ok = true;
    }
    cout << (ok ? "Alice" : "Bob") << '\n';
  }
  
  
  return 0;
}