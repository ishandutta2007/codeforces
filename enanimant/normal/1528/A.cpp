/*
 * author:  ADMathNoob
 * created: 05/24/21 10:34:36
 * problem: https://codeforces.com/contest/1528/problem/A
 */

/*
g++ 1528A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1528A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
      cin >> L[i] >> R[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<long long> dpL(n), dpR(n);
    function<void(int, int)> Dfs = [&](int v, int p) {
      for (int u : g[v]) {
        if (u == p) {
          continue;
        }
        Dfs(u, v);
        dpL[v] += max(dpL[u] + abs(L[v] - L[u]), dpR[u] + abs(L[v] - R[u]));
        dpR[v] += max(dpL[u] + abs(R[v] - L[u]), dpR[u] + abs(R[v] - R[u]));
      }
    };
    Dfs(0, -1);
    cout << max(dpL[0], dpR[0]) << '\n';
  }
  return 0;
}