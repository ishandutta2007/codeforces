// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct Djikstra {
  vector<vector<array<int, 2>>> g;
  int n;
  Djikstra(int _n) : n(_n) {
    g.resize(n);
  }
  void add(int x, int y, int c) {
    if (x == n || y == n) {
      return; 
    }
    g[x].push_back({y, c});
  }
  vector<long long> get(vector<int> sources) {
    const long long inf = (long long) 1e17;
    vector<long long> dist(n + 1, inf);
    using T = pair<long long, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    for (auto v : sources) {
      dist[v] = 0;
      pq.emplace(0, v);
    }
    while (!pq.empty()) {
      auto[c, v] = pq.top();
      pq.pop();
      if (dist[v] < c) {
        continue;
      }
      for (auto[u, w] : g[v]) {
        if (dist[u] > dist[v] + w) {
          dist[u] = dist[v] + w;
          pq.emplace(dist[u], u);
        }
      }
    }
    return dist;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, P, Q;
  cin >> N >> M >> P >> Q;
  vector<string> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  auto Id = [&](int x, int y) {  
    if (x < 0 || x >= N || y < 0 || y >= M || A[x][y] == '#') {
      return N * M;
    }
    return x * M + y;
  };
  Djikstra g(N * M);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int to = Id(i, j);
      if (A[i][j] == 'L') {
        g.add(Id(i + 1, j + 1), to, P);
        g.add(Id(i - 1, j + 1), to, P);  
        g.add(Id(i, j + 2), to, Q);
      } else if (A[i][j] == 'R') {
        g.add(Id(i - 1, j - 1), to, P);
        g.add(Id(i + 1, j - 1), to, P);
        g.add(Id(i, j - 2), to, Q);
      } else if (A[i][j] == 'U') {
        g.add(Id(i + 1, j - 1), to, P);
        g.add(Id(i + 1, j + 1), to, P);
        g.add(Id(i + 2, j), to, Q);
      } else if (A[i][j] == 'D') {
        g.add(Id(i - 1, j + 1), to, P);
        g.add(Id(i - 1, j - 1), to, P);
        g.add(Id(i - 2, j), to, Q);
      }
    }
  }  
  debug("a");        	
  vector<int> emp;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (A[i][j] == '.') {
        emp.push_back(Id(i, j));
      }
    }
  }
  debug(emp);
  auto dist = g.get(emp);
  debug(dist);
  const long long inf = (long long) 1e17;
  long long ans = inf;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      for (auto[ni, nj] : vector{pair{i + 1, j}, {i, j + 1}}) {
        ans = min(ans, dist[Id(i, j)] + dist[Id(ni, nj)]);  
      }
    }
  }
  cout << (ans == inf ? -1LL : ans);
}