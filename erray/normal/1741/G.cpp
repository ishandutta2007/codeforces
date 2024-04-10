// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

template<typename T, typename R = int64_t> struct Dinic {
  vector<pair<int, T>> es;
  vector<vector<int>> g;
  vector<T> flow;
  vector<int> d;
  vector<int> pt;
  int n;
  Dinic(int _n) : n(_n) {
    g.resize(n);
  }

  void add_edge(int v, int u, T cap = 1, bool directed = true) {
    int id = int(es.size());
    es.push_back(pair<int, T>{u, cap});
    es.push_back(pair<int, T>{v, directed ? 0 : cap});
    g[v].push_back(id);
    g[u].push_back(id ^ 1);
  }

  T dfs(int v, T push, int& t) {
    if (v == t) {
      return push;  
    }
    for (int &i = pt[v]; i < int(g[v].size()); ++i) {
      int id = g[v][i];
      auto[u, cap] = es[id];
      if (d[u] == d[v] + 1 && flow[id] < cap) {
        T res = dfs(u, min(push, cap - flow[id]), t);   
        if (res > 0) {
          flow[id] += res;
          flow[id ^ 1] -= res;
          return res;
        }
      }
    }
    return 0;
  }

  R max_flow(int s, int t) {
    flow.assign(int(es.size()), 0);
    d.resize(n);
    pt.resize(n);
    auto Bfs = [&] {
      queue<int> que;
      fill(d.begin(), d.end(), -1);
      d[s] = 0;
      que.push(s);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto id : g[v]) {
          auto[u, cap] = es[id];
          if (d[u] == -1 && flow[id] < cap) {
            d[u] = d[v] + 1;
            que.push(u);
          }    
        }
      }
      return d[t] != -1;
    };
    R res = 0;
    while (Bfs()) {
      fill(pt.begin(), pt.end(), 0);
      while (T add = dfs(s, numeric_limits<T>::max(), t)) {
        res += add;
      } 
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; ++i) {
      int X, Y;
      cin >> X >> Y;
      --X, --Y;
      g[X].push_back(Y);
      g[Y].push_back(X);
    } 
    int F;
    cin >> F;
    vector<int> H(F);
    for (int i = 0; i < F; ++i) {
      cin >> H[i];
      --H[i];
    }
    int K;
    cin >> K;
    vector<int> P(K);
    for (int i = 0; i < K; ++i) {
      cin >> P[i];
      --P[i]; 
    }
    queue<pair<int, int>> que;
    vector<vector<int>> dist(N, vector<int>(1 << K, N));
    dist[0][0] = 0;
    que.emplace(0, 0);
    while (!que.empty()) {
      auto[v, mask] = que.front();
      que.pop();
      for (auto u : g[v]) {
        int new_mask = mask;
        for (int i = 0; i < K; ++i) {
          if (u == H[P[i]]) {
            new_mask |= 1 << i;
          }
        }
        if (dist[u][new_mask] == N) {
          dist[u][new_mask] = dist[v][mask] + 1;
          que.emplace(u, new_mask);
        }
      }
    }
    vector<bool> dp(1 << K);
    dp[0] = true;
    for (int ii = 0; ii < F; ++ii) {
      if (binary_search(P.begin(), P.end(), ii)) {
        continue;
      }
      int v = H[ii];
      debug(ii, v);
      int mn = N;
      auto new_dp = dp;
      for (int i = 0; i < (1 << K); ++i) {
        mn = min(mn, dist[v][i]);
      } 
      debug(mn);
      for (int i = 0; i < (1 << K); ++i) {
        if (mn == dist[v][i]) {
          debug(i);      
          for (int m = 0; m < (1 << K); ++m) {
            if (dp[m]) {
              new_dp[i | m] = true;
            }
          }
        } 
      }
      swap(dp, new_dp);
    }
    debug(dp);
    int ans = 0;
    for (int i = 0; i < (1 << K); ++i) {
      if (dp[i]) {
        ans = max(ans, __builtin_popcount(i));
      }
    }
    cout << K - ans << '\n';

  }
}