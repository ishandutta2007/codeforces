// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);

  }

  const int SQ = 500;
  vector<vector<int>> big(N, {0});
  vector<int> ord;
  function<void(int)> Dfs = [&](int v) {
    for (auto u : g[v]) {
      g[u].erase(find(g[u].begin(), g[u].end(), v));
      Dfs(u);
      int s = int(big[v].size());
      big[v].resize(s + int(big[u].size()), 0);
      for (int i = s - 1; i >= 0; --i) {
        for (int j = 0; j < int(big[u].size()); ++j) {
          big[v][i + j + 1] = max(big[v][i + j + 1], big[v][i] + big[u][j]);
        }
        big[v][i] += 1;
      }
      big[v].resize(min(int(big[v].size()), SQ));
    }
    ord.push_back(v);
  };
  Dfs(0);
  debug(big);
  //debug(small);
                                                                                              
  int Q;
  cin >> Q;
  vector<array<int, 3>> QS(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> QS[i][0] >> QS[i][1];
    QS[i][0]--;
    QS[i][2] = i;
  }
  sort(QS.begin(), QS.end(), [&](auto x, auto y) {
    return x[1] < y[1];
  });

  vector<int> small(N);
  vector<int> ans(Q);
  for (int i = 0; i < Q; ++i) {
    auto[V, K, ID] = QS[i];
    if (K >= SQ) {
      for (int j = 0; j < int(big[V].size()); ++j) {
        ans[ID] = max(ans[ID], big[V][j] - j * K);
      } 
    } else {
      if (i == 0 || QS[i - 1][1] != QS[i][1]) {
        small.assign(N, 0);
        for (auto v : ord) {
          for (auto u : g[v]) {
            small[v] = max(small[v] + 1, small[u] + small[v] - K);
          }
        } 
      }
      ans[ID] = small[V];
    }
  }

  for (auto e : ans) {
    cout << e << '\n';
  }
}