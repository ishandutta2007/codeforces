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
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    --P[i];
  }

  vector<int> X(M), Y(M);
  vector<vector<int>> g(N);
  for (int i = 0; i < M; ++i) {
    cin >> X[i] >> Y[i];
    --X[i], --Y[i];
    g[X[i]].push_back(i);
    g[Y[i]].push_back(i);
  }

  vector<bool> vis(N);
  vector<int> id(N);
  for (int i = 0; i < N; ++i) {
    if (vis[i]) {
      continue;
    }
    int v = i;
    int cur = 0;
    do {
      vis[v] = true;
      id[v] = cur++;
      v = P[v];
    } while (v != i);
  }
  
  vector<vector<int>> ans_g(M);
  vector<int> indeg(M);
  for (int i = 0; i < N; ++i) {
    auto G = [&](int x) {
      return pair{id[x] < id[i], id[x]};
    };

    sort(g[i].begin(), g[i].end(), [&](int x, int y) {
      int vx = X[x] ^ Y[x] ^ i;
      int vy = X[y] ^ Y[y] ^ i;
      return G(vx) < G(vy);
    });

    debug(g[i]);
    for (int j = 0; j < int(g[i].size()) - 1; ++j) {
      int v = g[i][j];
      int u = g[i][j + 1];
      ans_g[v].push_back(u);
      indeg[u] += 1;
    }
  }

  vector<int> que;
  for (int i = 0; i < M; ++i) {
    if (indeg[i] == 0) {
      que.push_back(i);
    }
  }
  for (int it = 0; it < int(que.size()); ++it) {
    int v = que[it];
    for (auto u : ans_g[v]) {
      if (--indeg[u] == 0) {
        que.push_back(u);
      }
    }
  }

  for (auto e : que) {
    cout << e + 1 << ' ';
  }
  cout << '\n';
}