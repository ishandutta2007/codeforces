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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    vector<int> V(M), U(M), W(M);
    for (int i = 0; i < M; ++i) {
      cin >> V[i] >> U[i] >> W[i];
      --V[i], --U[i];
      g[V[i]].push_back(U[i]);
      g[U[i]].push_back(V[i]);
    }
    auto MsBfs = [&](vector<int> dist) {
      int size = N + (*min_element(dist.begin(), dist.end()));
      vector<vector<int>> que(size);
      for (int i = 0; i < N; ++i) {
        if (dist[i] < size) {
          que[dist[i]].push_back(i);
        }
      }
      for (int d = 0; d < size; ++d) {
        for (auto v : que[d]) {
          if (d == dist[v]) {
            for (auto u : g[v]) {
              if (dist[u] > dist[v] + 1) {
                que[dist[u] = dist[v] + 1].push_back(u);
              }
            }
          }
        } 
      }
      return dist;
    };
    auto SsBfs = [&](int v) {
      vector<int> a(N, N);
      a[v] = 0;
      return MsBfs(a);
    };
    auto source = SsBfs(0);
    auto sink = SsBfs(N - 1);
    vector<int> self(N);
    for (int i = 0; i < N; ++i) {
      self[i] = source[i] + sink[i];
    }
    self = MsBfs(self);
    long long ans = (long long) 1e15;
    for (int i = 0; i < M; ++i) {
      for (int it = 0; it < 2; ++it) {
        ans = min({ans, 1LL * W[i] * (1 + source[V[i]] + sink[U[i]]), 1LL * W[i] * (2 + self[V[i]])});
        swap(V[i], U[i]);
      } 
    }
    cout << ans << '\n';
  }
}