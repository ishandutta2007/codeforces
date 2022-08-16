#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct Primal_Dual
{
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
  int N, A[5000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  deque< int > latte[7], malta[100002];
  for(int i = 0; i < N; i++) {
    latte[A[i] % 7].push_back(i);
    malta[A[i]].push_back(i);
  }

  Primal_Dual flow(N * 2 + 2);
  for(int i = 0; i < N; i++) {
    latte[A[i] % 7].pop_front();
    malta[A[i]].pop_front();
    for(int j = 0; j < 3; j++) {
      if(j < latte[A[i] % 7].size()) flow.add_edge(i, latte[A[i] % 7][j] + N, 1, 0);
      if(j < malta[A[i] - 1].size()) flow.add_edge(i, malta[A[i] - 1][j] + N, 1, 0);
      if(j < malta[A[i] + 1].size()) flow.add_edge(i, malta[A[i] + 1][j] + N, 1, 0);
    }
    flow.add_edge(i + N, i, 1, -1);
    flow.add_edge(i, N * 2 + 1, 1, 0);
    flow.add_edge(N * 2, i + N, 1, 0);
  }
  cout << -flow.min_cost_flow(N * 2, N * 2 + 1, 2) << endl;
}