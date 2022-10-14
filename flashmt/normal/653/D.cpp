#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

struct Edge
{
  int x, y, cap, flow;
};

struct DinicFlow
{
  const int oo = 1 << 30;

  int n, S, T;
  vector<vector<int>> a;
  vector<int> cur, d;
  vector<Edge> e;

  DinicFlow(int n, int S, int T): n(n), S(S), T(T)
  {
    a = vector<vector<int>>(n + 1);
    cur = vector<int>(n + 1);
    d = vector<int>(n + 1);
  }

  void addEdge(int x, int y, int cap)
  {
    Edge e1 = {x, y, cap, 0};
    Edge e2 = {y, x, 0, 0};
    a[x].push_back(e.size());
    e.push_back(e1);
    a[y].push_back(e.size());
    e.push_back(e2);
  }

  int bfs()
  {
    queue<int> q;
    for (int i = 1; i <= n; i++)
      d[i] = -1;
    q.push(S);
    d[S] = 0;
    while (!q.empty() && d[T] < 0)
    {
      int x = q.front();
      q.pop();
      for (int i = 0; i < int(a[x].size()); i++)
      {
        int id = a[x][i], y = e[id].y;
        if (d[y] < 0 && e[id].flow < e[id].cap)
          q.push(y), d[y] = d[x] + 1;
      }
    }
    return d[T] >= 0;
  }

  int dfs(int x, int val)
  {
    if (!val)
      return 0;
    if (x == T)
      return val;
    for (; cur[x] < int(a[x].size()); cur[x]++)
    {
      int id = a[x][cur[x]], y = e[id].y;
      if (d[y] != d[x] + 1)
        continue;
      int pushed = dfs(y, min(val, e[id].cap - e[id].flow));
      if (pushed)
      {
        e[id].flow += pushed;
        e[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

  int maxFlow()
  {
    int res = 0;
    while (bfs())
    {
      for (int i = 1; i <= n; i++)
        cur[i] = 0;
      while (1)
      {
        int val = dfs(S, oo);
        if (!val)
          break;
        res += val;
      }
    }
    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, bear;
  cin >> n >> m >> bear;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    edges.push_back({x, y, w});
  }

  double low = 0, high = 1e6;
  for (int turn = 0; turn < 100; turn++)
  {
    double mid = (low + high) / 2;
    DinicFlow f(n, 1, n);
    for (auto [x, y, w] : edges)
      f.addEdge(x, y, int(min(w / mid, bear * 1.)));
    if (f.maxFlow() < bear) high = mid;
    else low = mid;
  }

  cout << fixed << setprecision(9) << low * bear << endl;
}