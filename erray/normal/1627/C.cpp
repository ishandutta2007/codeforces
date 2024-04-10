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
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<vector<int>> g(N);
    vector<array<int, 2>> E(N - 1);
    for (int i = 0; i < N - 1; ++i) {
      int X, Y;
      cin >> X >> Y;
      --X, --Y;
      g[X].push_back(i);
      g[Y].push_back(i);
      E[i] = {X, Y};
    }

    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= int(g[i].size()) <= 2;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> ans(N - 1, -1);
    queue<int> que;
    que.push(0);
    vector<int> p(N);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto id : g[v]) {
        int u = v ^ E[id][0] ^ E[id][1];
        g[u].erase(find(g[u].begin(), g[u].end(), id));
        que.push(u);
        p[u] = p[v] ^ 1;
        ans[id] = p[v];
        p[v] ^= 1;
      }
    }

    for (auto e : ans) {
      cout << 2 + e << ' ';
    }
    cout << '\n';
  }
}