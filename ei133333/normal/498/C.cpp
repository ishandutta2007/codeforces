#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int INF = 1 << 30;

struct Dinic
{


  struct edge
  {
    int to, cap, rev;
  };

  vector< vector< edge > > graph;
  vector< int > min_cost, iter;

  Dinic(int n)
  {
    graph.resize(n);
  }

  void add_edge(int from, int to, int cap)
  {
    graph[from].push_back((edge) {to, cap, (int) graph[to].size()});
    graph[to].push_back((edge) {from, 0, (int) graph[from].size() - 1});
  }

  bool bfs(int s, int t)
  {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty()) {
      int p = que.front();
      que.pop();
      for(int i = 0; i < graph[p].size(); i++) {
        const edge &e = graph[p][i];
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return (min_cost[t] != -1);
  }

  int dfs(int idx, const int t, int flow)
  {
    if(idx == t) return (flow);
    for(int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        int d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return (d);
        }
      }
    }
    return (0);
  }

  int max_flow(int s, int t)
  {
    int flow = 0;
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      int f = 0;
      while((f = dfs(s, t, INF)) > 0) {
        flow += f;
      }
    }
    return (flow);
  }
};

map< int64, int > prime_factor(int64 n)
{
  map< int64, int > ret;
  for(int64 i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}

int main()
{
  int N, M;
  map< int64, int > vs[100];
  int X[100], Y[100];

  cin >> N >> M;
  set< int > st;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    vs[i] = prime_factor(a);
    for(auto &p : vs[i]) st.emplace(p.first);
  }
  for(int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i];
    --X[i], --Y[i];
    if(X[i] % 2 == 1) swap(X[i], Y[i]);
  }

  int ret = 0;
  for(auto &v : st) {
    Dinic flow(N + 2);

    vector< int > sum(N, 0);
    for(int i = 0; i < N; i++) sum[i] = vs[i][v];

    int s = N, t = N + 1;
    for(int i = 0; i < N; i += 2) {
      flow.add_edge(s, i, sum[i]);
    }
    for(int i = 0; i < M; i++) {
      flow.add_edge(X[i], Y[i], INF);
    }
    for(int i = 1; i < N; i += 2) {
      flow.add_edge(i, t, sum[i]);
    }
    ret += flow.max_flow(s, t);
  }
  cout << ret << endl;
}