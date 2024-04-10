/*
 * author:  ADMathNoob
 * created: 08/01/21 10:35:12
 * problem: https://codeforces.com/contest/1548/problem/A
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<set<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].insert(y);
    g[y].insert(x);
  }
  auto Lives = [&](int v) {
    return (g[v].empty() || *prev(g[v].end()) < v);
  };
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += Lives(i);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int op;
    cin >> op;
    if (op == 3) {
      cout << ans << '\n';
    } else {
      int x, y;
      cin >> x >> y;
      --x; --y;
      ans -= Lives(x);
      ans -= Lives(y);
      if (op == 1) {
        g[x].insert(y);
        g[y].insert(x);
      } else {
        g[x].erase(y);
        g[y].erase(x);
      }
      ans += Lives(x);
      ans += Lives(y);
    }
  }
  return 0;
}