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
    vector<vector<vector<bool>>> D(N, vector<vector<bool>>(N, vector<bool>(N)));
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          char c;
          cin >> c;
          D[k][i][j] = D[k][j][i] = c - '0';
        }
      }
    }
                             
    vector<array<int, 2>> ans;
    for (int f = 1; f < N; ++f) { [&] {
      vector<vector<int>> d(N, vector<int>(N, N));
      vector<array<int, 2>> que;
      que.push_back({0, f});
      vector<bool> vis(N);
      vis[0] = vis[f] = true;
      for (int it = 0; it < int(que.size()); ++it) {
        auto[v, u] = que[it];
        for (int it1 = 0; it1 < 2; ++it1) {
          swap(v, u);
          for (int i = 0; i < N; ++i) {
            if (D[v][u][i] && !vis[i]) {
              vis[i] = true;
              que.push_back({v, i});
            }
          }
        }
      }
      if (int(que.size()) != N - 1) {
        return;
      }
      for (auto[v, u] : que) {
        d[v][u] = d[u][v] = 1;
      }
      for (int i = 0; i < N; ++i) {
        d[i][i] = 0;
      }
      for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < N; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          }
        }
      }
      debug(f, que, d);
      for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
          for (int j = i + 1; j < N; ++j) {
            if ((d[k][i] == d[k][j]) != D[k][i][j]) {
              return;
            } 
          }
        }
      }
      ans = que;
    }(); }
    if (ans.empty()) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      for (auto[v, u] : ans) {
        cout << v + 1 << ' ' << u + 1 << '\n';
      }
    }
  }
}