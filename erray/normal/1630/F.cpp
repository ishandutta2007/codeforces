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
    debug(v, u);
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
      debug(d);
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
  const int MAX = int(5e4);
  vector<int> ind(MAX + 1, -1);
  while (TT--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      ind[A[i]] = i;
    }
    debug(A);
    auto Id = [&](int v, int phase, bool out = false) {
      v *= 4;
      if (phase == 0) {
        return v;
      } else if (phase == 1) {
        return (out ? 2 : 1) + v;
      } else if (phase == 2) {
        return 3 + v;
      } else {
        assert(false);
      }
    };
    Dinic<int, int> flow(N * 4 + 2);
    int source = N * 4;
    int sink = N * 4 + 1;    
    for (int i = 0; i < N; ++i) {
      flow.add_edge(source, Id(i, 0));
      flow.add_edge(Id(i, 1, false), Id(i, 1, true));
      flow.add_edge(Id(i, 2), sink);
    }

    for (int i = 0; i < N; ++i) {
      vector<int> divs;
      for (int j = 1; j * j <= A[i]; ++j) {
        if (A[i] % j == 0) {
          int ot = A[i] / j;
          if (j != A[i] && ind[j] != -1) {
            divs.push_back(ind[j]);
          } 
          if (ot != j && ot != A[i] && ind[ot] != -1) {
            divs.push_back(ind[ot]);
          }
        } 
      }
      //debug(i, divs);

      for (auto v : divs) {
        flow.add_edge(Id(i, 0), Id(v, 1, false));
        flow.add_edge(Id(i, 1, true), Id(v, 2));
      }
    }
    cout << flow.max_flow(source, sink) << '\n';
    for (auto e : A) {
      ind[e] = -1;
    }
  }
}