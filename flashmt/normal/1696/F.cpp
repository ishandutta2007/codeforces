#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 111;
const int oo = 27081993;

int n;
string s[N][N];
vector<pair<int, int>> edges;

int check()
{
  vector<vector<int>> d(n, vector<int>(n, oo));
  for (int i = 0; i < n; i++)
    d[i][i] = 0;
  for (auto [x, y] : edges)
    d[x][y] = d[y][x] = 1;

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = 0; k < n; k++)
        if ((d[i][k] == d[j][k]) ^ (s[i][j][k] == '1'))
          return 0;

  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    int isBad = 0;
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
      {
        cin >> s[i][j];
        s[j][i] = s[i][j];
        if (s[i][j][i] == '1' || s[i][j][j] == '1')
          isBad = 1;
      }

    if (isBad)
    {
      cout << "No" << endl;
      continue;
    }

    int found = 0;
    // assume (0, u) is an edge
    for (int u = 1; u < n; u++)
    {
      edges = {{0, u}};
      vector<int> par(n, -1);
      par[0] = par[u] = 0;
      queue<int> q;
      q.push(u);

      for (int i = 1; i < n; i++)
        if (i != u && s[i][u][0] == '1')
        {
          par[i] = 0;
          q.push(i);
          edges.push_back({0, i});
        }

      while (!empty(q))
      {
        int x = q.front();
        q.pop();
        for (int i = 1; i < n; i++)
          if (par[i] < 0 && s[i][par[x]][x] == '1')
          {
            par[i] = x;
            q.push(i);
            edges.push_back({x, i});
          }
      }

      if (size(edges) < n - 1)
        continue;

      if (check())
      {
        cout << "Yes" << endl;
        for (auto [x, y] : edges)
          cout << x + 1 << ' ' << y + 1 << endl;
        found = 1;
        break;
      }
    }

    if (!found)
      cout << "No" << endl;
  }
}