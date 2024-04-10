#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int oo = 1 << 30;

struct Edge
{
  int x, y, cap, flow;
};

struct DinicFlow
{
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
  int n, m;
  cin >> n >> m;
  vector<int> s(n + 1), a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector<pair<int, int>> edges;
  vector<int> deg(n + 1);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    edges.push_back({x, y});
    deg[x]++;
    deg[y]++;
  }

  int S = m + n + 1, extra = S + 1, T = extra + 1;
  DinicFlow f(T, S, T);
  int free = m;
  for (int i = 1; i <= n; i++)
    if (!s[i]) f.addEdge(i, extra, oo);
    else if (abs(a[i]) > deg[i] || (deg[i] + a[i]) % 2)
    {
      cout << "NO" << endl;
      return 0;
    }
    else
    {
      int inDeg = (a[i] + deg[i]) / 2;
      f.addEdge(i, T, inDeg);
      free -= inDeg;
    }

  if (free < 0)
  {
    cout << "NO" << endl;
    return 0;
  }
  f.addEdge(extra, T, free);

  for (int i = 0; i < m; i++)
  {
    int cur = n + i + 1;
    auto [x, y] = edges[i];
    f.addEdge(S, cur, 1);
    f.addEdge(cur, x, 1);
    f.addEdge(cur, y, 1);
  }

  if (f.maxFlow() != m) cout << "NO" << endl;
  else
  {
    cout << "YES" << endl;
    vector<int> dir(m);
    for (auto e : f.e)
      if (e.flow == 1 && e.x > n && e.x <= n + m)
      {
        int i = e.x - n - 1;
        auto [x, y] = edges[i];
        if (y != e.y)
          dir[i] = 1;
      }

    for (int i = 0; i < m; i++)
    {
      auto [x, y] = edges[i];
      if (dir[i])
        swap(x, y);
      cout << x << ' ' << y << '\n';
    }
  }
}