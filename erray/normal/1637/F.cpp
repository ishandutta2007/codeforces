// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
  int root = int(max_element(H.begin(), H.end()) - H.begin());
  debug(g, H, root);
  vector<int> mx(N);
  long long ans = 0;
  function<void(int, int)> Dfs = [&](int v, int pr) {
    for (auto u : g[v]) {
      if (u == pr) {
        continue;
      }             
      Dfs(u, v);
      mx[v] = max(mx[v], mx[u]);
    }
    if (v != root) {
      ans += max(0, H[v] - mx[v]);
    }
    mx[v] = max(mx[v], H[v]);
  };
  Dfs(root, -1);
  vector<int> all;
  all.push_back(0);
  for (auto u : g[root]) {
    all.push_back(mx[u]);
  }
  sort(all.rbegin(), all.rend());
  ans += 2 * H[root] - all[0] - all[1];
  cout << ans << '\n';
}