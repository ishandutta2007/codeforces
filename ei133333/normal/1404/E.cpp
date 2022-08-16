#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

template< typename T >
struct Dinic {
  struct edge {
    int to;
    T cap;
    int rev;
  };

  const T INF;
  vector< vector< edge > > graph;
  vector< T > min_cost;
  vector< int > iter;

  Dinic(int n) : INF(numeric_limits< T >::max()) {
    graph.resize(n);
  }

  void add_edge(int from, int to, T cap) {
    graph[from].push_back((edge) {to, cap, (int) graph[to].size()});
    graph[to].push_back((edge) {from, 0, (int) graph[from].size() - 1});
  }

  bool bfs(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty()) {
      int p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return (min_cost[t] != -1);
  }

  T dfs(int idx, const int t, T flow) {
    if(idx == t) return (flow);
    for(int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        T d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return (d);
        }
      }
    }
    return (0);
  }

  T max_flow(int s, int t) {
    T flow = 0;
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      T f = 0;
      while((f = dfs(s, t, INF)) > 0) {
        flow += f;
      }
    }
    return (flow);
  }
};

int main() {
  int H, W;
  string S[222];

  int ret = 0;

  cin >> H >> W;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
  }

  Dinic< int > flow((H * W) * 3 + 2);
  int ptr = H * W;
  int s = (H * W) * 3, t = (H * W) * 3 + 1;

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#') {
        int u = i * W + j;
        ++ret;
        if(i && S[i - 1][j] == '#') {
          int v = u - W;
          flow.add_edge(s, ptr, 1);
          flow.add_edge(ptr, u, flow.INF);
          flow.add_edge(ptr, v, flow.INF);
          ++ptr;
          --ret;
        }

        if(j && S[i][j - 1] == '#') {
          int v = u - 1;
          flow.add_edge(u, ptr, flow.INF);
          flow.add_edge(v, ptr, flow.INF);
          flow.add_edge(ptr, t, 1);
          ++ptr;
          --ret;
        }
      }
    }
  }
  cout << flow.max_flow(s, t) + ret << endl;
}