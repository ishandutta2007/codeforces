// July 30, 2019
// https://codeforces.com/contest/1199/problem/E

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


  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(3 * n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].emplace_back(v, i);
      g[v].emplace_back(u, i);
    }
    vector<bool> used(3 * n, false);
    vector<int> mat;
    for (int i = 0; i < 3 * n; i++) {
      if (used[i]) {
        continue;
      }
      for (const auto &p : g[i]) {
        if (!used[p.first]) {
          used[i] = used[p.first] = true;
          mat.push_back(p.second);
          break;
        }
      }
    }
    if ((int) mat.size() >= n) {
      cout << "Matching\n";
      for (int i = 0; i < n; i++) {
        cout << mat[i] + 1 << (i < n - 1 ? ' ' : '\n');
      }
    } else {
      cout << "IndSet\n";
      int p = 0;
      for (int i = 0; i < 3 * n; i++) {
        if (!used[i] && p < n) {
          cout << i + 1 << (p < n - 1 ? ' ' : '\n');
          p++;
        }
      }
    }
  }


  return 0;
}