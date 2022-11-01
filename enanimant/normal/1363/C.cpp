// May 31, 2020
// https://codeforces.com/contest/1363/problem/A

/*

*/


#include <bits/stdc++.h>

using namespace std;


int n, x;
vector<vector<int>> g;

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
    cin >> n >> x;
    x--;
    g.clear();
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if ((int) g[x].size() <= 1) {
      cout << "Ayush\n";
      continue;
    }
    cout << ((n - 1) % 2 == 1 ? "Ayush" : "Ashish") << '\n';
  }
  
  
  return 0;
}