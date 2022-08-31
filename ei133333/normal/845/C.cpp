#include <bits/stdc++.h>

using namespace std;

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
  int N, L[200000], R[200000];
  vector< int > nums;

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &L[i], &R[i]);
    ++R[i];
    nums.push_back(L[i]);
    nums.push_back(R[i]);
  }
  sort(begin(nums), end(nums));
  nums.erase(unique(begin(nums), end(nums)), end(nums));
  for(int i = 0; i < N; i++) {
    L[i] = lower_bound(begin(nums), end(nums), L[i]) - begin(nums);
    R[i] = lower_bound(begin(nums), end(nums), R[i]) - begin(nums);
  }

  vector< vector< int > > ev(nums.size());
  for(int i = 0; i < N; i++) {
    ev[L[i]].push_back(R[i]);
  }

  int latte = -1, malta = -1;
  for(int i = 0; i < nums.size(); i++) {
    for(auto &r : ev[i]) {
      if(latte <= i) latte = r;
      else if(malta <= i) malta = r;
      else {
        cout << "NO" << endl;
        return(0);
      }
    }
  }
  cout << "YES" << endl;

}