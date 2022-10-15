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
  vector<vector<int>> g(N);
  vector<int> P(N, -1);
  for (int i = 1; i < N; ++i) {
    cin >> P[i];
    --P[i];
    g[P[i]].push_back(i);
    g[i].push_back(P[i]);
  }
  int Q;
  cin >> Q;
  vector<int> X(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> X[i];
  }
  vector<int> leaf(N, -1);
  queue<int> que;
  for (int i = 0; i < N; ++i) {
    if (int(g[i].size()) == 1) {
      que.push(i);
      leaf[i] = 0;
    }
  }
  while (!que.empty()) {
    auto v = que.front();
    que.pop();
    for (auto u : g[v]) {
      if (leaf[u] == -1) {
        leaf[u] = leaf[v] + 1;
        que.push(u);
      }
    }
  }
  vector<int> ans(Q);
  vector<vector<int>> mx(N);
  for (int i = 0; i < N; ++i) {
    mx[i] = {leaf[i]};
  }
  for (int i = N - 1; i > 0; --i) {
    mx[i].push_back(mx[i].back());
    int p = P[i];
    if (int(mx[p].size()) < int(mx[i].size())) {
      swap(mx[p], mx[i]);
    }
    int ps = int(mx[p].size());
    int is = int(mx[i].size());
    for (int j = 0; j < is; ++j) {
      for (int q = 0; q < Q; ++q) {
        while (true) {
          int need_l = ans[q] - X[q] - mx[i][is - 1 - j];
          int need_d = max(0, ans[q] - j);
          if (need_d < int(mx[p].size()) && mx[p][ps - 1 - need_d] >= need_l) {
            ++ans[q];
          } else {
            break;
          }
        }
      } 
    }
    for (int j = 0; j < is; ++j) {
      mx[p][ps - 1 - j] = max(mx[p][ps - 1 - j], mx[i][is - 1 - j]); 
    }
    vector<int>().swap(mx[i]);
  }
  for (int i = 0; i < Q; ++i) {
    cout << ans[i] - 1 << " \n"[i == Q - 1];
  }
}