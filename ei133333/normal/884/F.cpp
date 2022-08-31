#include<bits/stdc++.h>

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
  int N, B[100];
  string S;

  cin >> N;
  cin >> S;
  int sum[26] = {};
  for(int i = 0; i < N; i++) {
    sum[S[i] - 'a']++;
  }

  for(int i = 0; i < N; i++) {
    cin >> B[i];
  }

  Primal_Dual flow(N / 2 + 28);
  int s = N / 2 + 26, t = N / 2 + 27;
  for(int i = 0; i < 26; i++) {
    flow.add_edge(s, N / 2 + i, sum[i], 0);
  }
  for(int i = 0; i < N / 2; i++) {
    flow.add_edge(i, t, 2, 0);
  }
  for(int i = 0; i < N / 2; i++) {
    for(int j = 0; j < 26; j++) {
      int ret = 0;
      if(S[i] - 'a' == j) ret = max(ret, B[i]);
      if(S[N - i - 1] - 'a' == j) ret = max(ret, B[N - i - 1]);
      flow.add_edge(N / 2 + j, i, 1, -ret);
    }
  }
  cout << -flow.min_cost_flow(s, t, N) << endl;
}