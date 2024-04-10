#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp
{
  vector<int> leftMatch, rightMatch, dist, cur;
  vector<vector<int>> a;
  int m, n;

  HopcroftKarp(int m, int n): m(m), n(n)
  {
    a = vector<vector<int>>(m);
    leftMatch = vector<int>(n, -1);
    rightMatch = dist = cur = vector<int>(m, -1);
  }

  void addEdge(int x, int y)
  {
    a[x].push_back(y);
  }

  int bfs()
  {
    int found = 0;
    queue<int> q;
    for (int i = 0; i < m; i++)
      if (rightMatch[i] < 0)
      {
        dist[i] = 0;
        q.push(i);
      }
      else dist[i] = -1;

    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for (int y : a[x])
        if (leftMatch[y] < 0) found = 1;
        else if (dist[leftMatch[y]] < 0)
        {
          dist[leftMatch[y]] = dist[x] + 1;
          q.push(leftMatch[y]);
        }
    }

    return found;
  }

  int dfs(int x)
  {
    for (; cur[x] < a[x].size(); cur[x]++)
    {
      int y = a[x][cur[x]];
      if (leftMatch[y] < 0 || (dist[leftMatch[y]] == dist[x] + 1 && dfs(leftMatch[y])))
      {
        leftMatch[y] = x;
        rightMatch[x] = y;
        return 1;
      }
    }
    return 0;
  }

  int maxMatch()
  {
    int match = 0;
    while (bfs())
    {
      cur.assign(m, 0);
      for (int i = 0; i < m; i++)
        if (rightMatch[i] < 0)
          match += dfs(i);
    }
    return match;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<string> a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];

  HopcroftKarp hk(m * n, m * n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j + 1 < n; j++)
      if (a[i][j] == '#' && a[i][j + 1] == '#')
      {
        if (i && a[i - 1][j] == '#')
          hk.addEdge(i * n + j, (i - 1) * n + j);
        if (i && a[i - 1][j + 1] == '#')
          hk.addEdge(i * n + j, (i - 1) * n + j + 1);
        if (i + 1 < m && a[i + 1][j] == '#')
          hk.addEdge(i * n + j, i * n + j);
        if (i + 1 < m && a[i + 1][j + 1] == '#')
          hk.addEdge(i * n + j, i * n + j + 1);
      }

  int ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] == '#')
      {
        ans++;
        if (i + 1 < m && a[i + 1][j] == '#')
          ans--;
        if (j + 1 < n && a[i][j + 1] == '#')
          ans--;
      }

  ans += hk.maxMatch();
  cout << ans << endl;
}