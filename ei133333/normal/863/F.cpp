#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Primal_Dual
{
  const int INF = 1 << 30;
  typedef pair< int, int > Pi;

  struct edge
  {
    int to, cap, cost, rev;
  };
  vector< vector< edge > > graph;
  vector< int > potential, min_cost, prevv, preve;

  Primal_Dual(int V) : graph(V) {}

  void add_edge(int from, int to, int cap, int cost)
  {
    graph[from].push_back((edge) {to, cap, cost, (int) graph[to].size()});
    graph[to].push_back((edge) {from, 0, -cost, (int) graph[from].size() - 1});
  }

  int min_cost_flow(int s, int t, int f)
  {
    int V = graph.size(), ret = 0;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);

    while(f > 0) {
      min_cost.assign(V, INF);
      que.push(Pi(0, s));
      min_cost[s] = 0;

      while(!que.empty()) {
        Pi p = que.top();
        que.pop();
        if(min_cost[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++) {
          edge &e = graph[p.second][i];
          int nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if(e.cap > 0 && min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.push(Pi(min_cost[e.to], e.to));
          }
        }
      }
      if(min_cost[t] == INF) return -1;
      for(int v = 0; v < V; v++) potential[v] += min_cost[v];
      int addflow = f;
      for(int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for(int v = t; v != s; v = prevv[v]) {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }
};

int main()
{
  int N, Q;
  int low[50], high[50];

  cin >> N >> Q;
  for(int i = 0; i < N; i++) low[i] = 0;
  for(int i = 0; i < N; i++) high[i] = N - 1;

  for(int i = 0; i < Q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --b, --d;
    for(int j = b; j < c; j++) {
      if(a == 1) low[j] = max(low[j], d);
      else high[j] = min(high[j], d);
    }
  }

  for(int i = 0; i < N; i++) {
    if(low[i] > high[i]) {
      cout << -1 << endl;
      return (0);
    }
  }

  Primal_Dual flow(N + N + 2);
  int s = N + N;
  int t = N + N + 1;

  for(int i = 0; i < N; i++) {
    for(int j = 1; j <= N; j++) {
      int cost = j * j - (j - 1) * (j - 1);
      flow.add_edge(i, t, 1, cost);
    }
  }
  for(int i = 0; i < N; i++) {
    flow.add_edge(s, N + i, 1, 0);
    for(int j = low[i]; j <= high[i]; j++) {
      flow.add_edge(N + i, j, 1, 0);
    }
  }
  cout << flow.min_cost_flow(s, t, N) << endl;
}