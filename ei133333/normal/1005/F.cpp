#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;

template< typename T >
struct edge {
  int src, to;
  T cost;

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
vector< T > bfs(UnWeightedGraph &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);
  queue< int > que;
  dist[s] = 0;
  que.emplace(s);

  while(!que.empty()) {
    int idx = que.front();
    que.pop();
    for(auto &e : g[idx]) {
      auto next_cost = dist[idx] + 1;
      if(dist[e] <= next_cost) continue;
      dist[e] = next_cost;
      que.emplace(e);
    }
  }
  return dist;
}

int main() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  UnWeightedGraph g(N);
  map< int, int > st[202020];
  for(int i = 0; i < M; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    st[x][y] = i;
    st[y][x] = i;
  }
  auto beet = bfs< int >(g, 0);

  vector< int > dist[202020];
  for(int i = 0; i < N; i++) {
    dist[beet[i]].emplace_back(i);
  }
  vector< int > add[202020];
  for(int i = 1; i < N; i++) {
    for(auto &to : g[i]) {
      if(binary_search(begin(dist[beet[i] - 1]), end(dist[beet[i] - 1]), to)) {
        add[i].emplace_back(to);
      }
    }
  }


  vector< string > ans;

  int used[202020] = {};

  for(int i = 0; i < K; i++) {
    string uku = string(M, '0');
    for(int j = 1; j < N; j++) {
      uku[st[j][add[j][used[j]]]] = '1';
    }
    ans.emplace_back(uku);
    bool update = false;
    for(int j = N - 1; j >= 0; j--) {
      if(used[j] + 1 < add[j].size()) {
        used[j]++;
        for(int k = j + 1; k < N; k++) {
          used[k] = 0;
        }
        update = true;
        break;
      }
    }
    if(!update) break;
  }


  int latte = 0, malta = 0;
  printf("%d\n", (int) ans.size());
  for(auto &s : ans) printf("%s\n", s.c_str());
}