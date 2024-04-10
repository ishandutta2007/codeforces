#include <bits/stdc++.h>
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

struct Rect
{
  int x, y, xx, yy;
};

int main()
{
  int m, n, x, y, xx, yy;
  vector<Rect> rects;
  cin >> n >> m;
  if (!m)
  {
    cout << 0 << endl;
    return 0;
  }

  map<int, int> allX, allY;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y >> xx >> yy;
    allX[--x] = allX[xx] = allY[--y] = allY[yy] = 0;
    rects.push_back({x, y, xx, yy});
  }

  int row = 0, col = 0;
  vector<int> sortedX, sortedY;
  for (auto u : allX)
  {
    allX[u.first] = row++;
    sortedX.push_back(u.first);
  }
  row--;
  for (auto u : allY)
  {
    allY[u.first] = col++;
    sortedY.push_back(u.first);
  }
  col--;

  int S = row + col + 1, T = S + 1;
  DinicFlow dinic(T, S, T);

  for (int i = 1; i <= row; i++)
    dinic.addEdge(S, i, sortedX[i] - sortedX[i - 1]);
  for (int i = 1; i <= col; i++)
    dinic.addEdge(row + i, T, sortedY[i] - sortedY[i - 1]);

  for (int i = 1; i <= row; i++)
    for (int j = 1; j <= col; j++)
    {
      int isBlack = 0;
      for (auto rect : rects)
        if (allX[rect.x] < i && i <= allX[rect.xx] && allY[rect.y] < j && j <= allY[rect.yy])
          isBlack = 1;
      if (isBlack)
        dinic.addEdge(i, row + j, oo);
    }

  cout << dinic.maxFlow() << endl;
}