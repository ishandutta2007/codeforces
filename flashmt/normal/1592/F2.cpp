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

  vector<vector<int>> f(m + 1, vector<int>(n + 1));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] == 'B')
      {
        f[i][j] ^= 1;
        f[i + 1][j] ^= 1;
        f[i][j + 1] ^= 1;
        f[i + 1][j + 1] ^= 1;
      }

  int sum = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      sum += f[i][j];

  int ans = sum;
  HopcroftKarp hk(m, n);
  for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++)
      if (f[i][j] && f[i][n] && f[m][j])
        hk.addEdge(i - 1, j - 1);

  int maxMatch = hk.maxMatch();
  for (int i = maxMatch; i >= max(0, maxMatch - 1); i--)
    ans = min(ans, sum - i + (i + f[m][n]) % 2 - f[m][n]);
  cout << ans << endl;
}