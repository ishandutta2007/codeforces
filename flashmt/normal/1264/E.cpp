#include <bits/stdc++.h>
using namespace std;

template<class Flow=int, class Cost=int>
struct MinCostFlow
{
  const Flow INF_FLOW = 1000111000;
  const Cost INF_COST = 1000111000;

  int n, t, S, T;
  Flow totalFlow;
  Cost totalCost;
  vector<int> last, visited;
  vector<Cost> dis;
  struct Edge
  {
    int to;
    Flow cap;
    Cost cost;
    int next;
    Edge(int to, Flow cap, Cost cost, int next): to(to), cap(cap), cost(cost), next(next) {}
  };
  vector<Edge> edges;

  MinCostFlow(int n): n(n), t(0), totalFlow(0), totalCost(0), last(n, -1), visited(n, 0), dis(n, 0)
  {
    edges.clear();
  }

  int addEdge(int from, int to, Flow cap, Cost cost)
  {
    edges.push_back(Edge(to, cap, cost, last[from]));
    last[from] = t++;
    edges.push_back(Edge(from, 0, -cost, last[to]));
    last[to] = t++;
    return t - 2;
  }

  pair<Flow, Cost> minCostFlow(int _S, int _T)
  {
    S = _S; T = _T;
    SPFA();
    while (1)
    {
      while (1)
      {
        for (int i = 0; i < n; i++)
          visited[i] = 0;
        if (!findFlow(S, INF_FLOW))
          break;
      }
      if (!modifyLabel())
        break;
    }
    return {totalFlow, totalCost};
  }

  private:
  void SPFA()
  {
    for (int i = 0; i < n; i++)
      dis[i] = INF_COST;
    priority_queue<pair<Cost, int>> Q;
    dis[S] = 0;
    Q.push({0, S});
    while (!Q.empty())
    {
      int x = Q.top().second;
      Cost d = -Q.top().first;
      Q.pop();
      // For double: dis[x] > d + EPS
      if (dis[x] != d)
        continue;
      for (int it = last[x]; it >= 0; it = edges[it].next)
        if (edges[it].cap > 0 && dis[edges[it].to] > d + edges[it].cost)
        {
          dis[edges[it].to] = d + edges[it].cost;
          Q.push({-dis[edges[it].to], edges[it].to});
        }
    }
    Cost disT = dis[T];
    for (int i = 0; i < n; i++)
      dis[i] = disT - dis[i];
  }

  Flow findFlow(int x, Flow flow)
  {
    if (x == T)
    {
      totalCost += dis[S] * flow;
      totalFlow += flow;
      return flow;
    }
    visited[x] = 1;
    Flow now = flow;
    for (int it = last[x]; it >= 0; it = edges[it].next)
      // For double: fabs(dis[edges[it].to] + edges[it].cost - dis[x]) < EPS
      if (edges[it].cap && !visited[edges[it].to] && dis[edges[it].to] + edges[it].cost == dis[x])
      {
        Flow tmp = findFlow(edges[it].to, min(now, edges[it].cap));
        edges[it].cap -= tmp;
        edges[it ^ 1].cap += tmp;
        now -= tmp;
        if (!now) break;
      }
    return flow - now;
  }

  int modifyLabel()
  {
    Cost d = INF_COST;
    for (int i = 0; i < n; i++)
      if (visited[i])
        for (int it = last[i]; it >= 0; it = edges[it].next)
          if (edges[it].cap && !visited[edges[it].to])
            d = min(d, dis[edges[it].to] + edges[it].cost - dis[i]);

    // For double: if (d > INF_COST / 10)     INF_COST = 1e20
    if (d == INF_COST)
      return 0;
    for (int i = 0; i < n; i++)
      if (visited[i])
        dis[i] += d;
    return 1;
  }
};

int main()
{
  int n, m, a[55][55], deg[55] = {0};
  cin >> n >> m;
  memset(a, -1, sizeof a);
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x][--y] = 1;
    a[y][x] = 0;
    deg[x]++;
  }

  MinCostFlow<int, int> mcf(2 + n + n * (n - 1) / 2);
  int s = 0, t = 1;
  for (int i = 0; i < n; i++)
    for (int j = deg[i] + 1; j < n; j++)
      mcf.addEdge(2 + i, t, 1, 2 * j - 1);

  pair<int, int> matches[2020];
  for (int i = 0, curId = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i][j] < 0)
      {
        matches[curId] = {i, j};
        int u = 2 + n + curId;
        curId++;
        mcf.addEdge(s, u, 1, 0);
        mcf.addEdge(u, i + 2, 1, 0);
        mcf.addEdge(u, j + 2, 1, 0);
      }

  mcf.minCostFlow(s, t);
  for (int i = 0; i < mcf.edges.size(); i += 2)
  {
    auto e = mcf.edges[i];
    int to = e.to, from = mcf.edges[i + 1].to;
    if (!e.cap && from >= n + 2 && to >= 2 && to < n + 2)
    {
      auto [x, y] = matches[from - n - 2];
      if (to == x + 2) a[x][y] = 1;
      else a[x][y] = 0;
      a[y][x] = a[x][y] ^ 1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << (i == j ? 0 : a[i][j]);
    cout << endl;
  }
}