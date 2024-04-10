#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, -1, 0, 1};
const int N = 3e5 + 5;
const long long oo = 1LL << 60;

int n, m, rotateCost, shiftCost;
string a[N];

int isValid(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#';
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> rotateCost >> shiftCost;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<vector<pair<int, int>>> edges(n * m);
  vector<long long> dist(n * m, oo);
  priority_queue<pair<long long, int>> q;

  auto addEdge = [&](int u, int v, int c)
  {
    edges[v].push_back({u, c});
  };

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      int u = i * m + j;
      if (a[i][j] == '.')
      {
        q.push({0, u});
        dist[u] = 0;
      }
      else if (a[i][j] == 'L')
      {
        if (isValid(i, j - 1))
          addEdge(u + 1, u - 1, shiftCost);
        if (isValid(i, j + 2))
          addEdge(u, u + 2, shiftCost);

        if (isValid(i - 1, j))
          addEdge(u + 1, u - m, rotateCost);
        if (isValid(i + 1, j))
          addEdge(u + 1, u + m, rotateCost);

        if (isValid(i - 1, j + 1))
          addEdge(u, u - m + 1, rotateCost);
        if (isValid(i + 1, j + 1))
          addEdge(u, u + m + 1, rotateCost);
      }
      else if (a[i][j] == 'U')
      {
        if (isValid(i - 1, j))
          addEdge(u + m, u - m, shiftCost);
        if (isValid(i + 2, j))
          addEdge(u, u + m + m, shiftCost);

        if (isValid(i, j - 1))
          addEdge(u + m, u - 1, rotateCost);
        if (isValid(i, j + 1))
          addEdge(u + m, u + 1, rotateCost);

        if (isValid(i + 1, j - 1))
          addEdge(u, u + m - 1, rotateCost);
        if (isValid(i + 1, j + 1))
          addEdge(u, u + m + 1, rotateCost);
      }
    }

  vector<int> done(n * m);
  while (!empty(q))
  {
    auto [_, u] = q.top();
    q.pop();
    if (done[u])
      continue;
    done[u] = 1;

    for (auto [v, c] : edges[u])
      if (!done[v] && dist[v] > dist[u] + c)
      {
        dist[v] = dist[u] + c;
        q.push({-dist[v], v});
      }
  }

  long long ans = oo;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] != '#')
      {
        int u = i * m + j;
        for (int k = 0; k < 4; k++)
        {
          int ii = i + DX[k], jj = j + DY[k];
          if (isValid(ii, jj))
          {
            int v = ii * m + jj;
            ans = min(ans, dist[u] + dist[v]);
          }
        }
      }

  cout << (ans == oo ? -1 : ans) << endl;
}