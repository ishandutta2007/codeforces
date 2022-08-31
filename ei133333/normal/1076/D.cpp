#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template< typename T >
struct edge {
  int src, to;
  T cost;
  int idx;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};


int main() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  WeightedGraph< int64 > g(N);
  for(int i = 0; i < M; i++) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    --x, --y;
    g[x].emplace_back(y, w);
    g[y].emplace_back(x, w);
    g[x].back().idx = i;
    g[y].back().idx = i;
  }
  auto dist = dijkstra(g, 0);

  WeightedGraph< int64 > dag(N);
  bool used[300000] = {};
  Edges< int64 > ok, ng;
  for(int i = 0; i < N; i++) {
    for(auto &e : g[i]) {
      if(dist[i] + e.cost == dist[e.to]) {
        dag[i].emplace_back(e);
        used[e.idx] = true;
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(auto &e : g[i]) {
      if(!used[e.idx]) {
        ok.emplace_back(e);
        used[e.idx] = true;
      }
    }
  }
  vector< int > dir(N);
  iota(begin(dir), end(dir), 0);
  sort(begin(dir), end(dir), [&](int a, int b) {
      return dist[a] < dist[b];
  });
  UnionFind uf(N);
  for(int i : dir) {
    for(auto &e : dag[i]) {
      if(uf.find(i) == uf.find(e.to)) {
        ok.emplace_back(e);
      } else {
        ng.emplace_back(e);
        ng.back().cost = dist[e.to];
        uf.unite(i, e.to);
      }
    }
  }
  int rest = M - K;
  bool v[300000] = {};
  for(auto &p : ok) {
    if(rest > 0) {
      rest--;
      v[p.idx] = true;
    }
  }
  sort(begin(ng), end(ng), [&](auto p, auto q) {
    return p.cost > q.cost;
  });
  for(auto &p : ng) {
    if(rest > 0) {
      rest--;
      v[p.idx] = true;
    }
  }
  vector< int > remain;
  for(int i = 0; i < M; i++) {
    if(!v[i]) remain.emplace_back(i);
  }
  printf("%d\n", (int) remain.size());
  for(auto &p : remain) printf("%d ", p + 1);
  puts("");
}