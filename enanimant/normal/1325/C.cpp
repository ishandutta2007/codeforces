// March 14, 2020
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


  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<pair<int, int>> edges;
  set<int> unused;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(i);
    g[v].push_back(i);
    edges.emplace_back(u, v);
    unused.insert(i);
  }
  vector<int> ans(n - 1, -1);
  for (int i = 0; i < n; i++) {
    if (g[i].size() >= 3) {
      for (int j = 0; j < 3; j++) {
        ans[g[i][j]] = j;
        unused.erase(j);
      }
      for (int j = 0; j < n - 1; j++) {
        if (ans[j] == -1) {
          ans[j] = *unused.begin();
          unused.erase(unused.begin());
        }
      }
      for (int x : ans) {
        cout << x << '\n';
      }
      return 0;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    cout << i << '\n';
  }


  return 0;
}