#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 200200;

vector<pair<int, int>> a[N];
vector<int> c;

void dfs(int x)
{
  for (auto [y, t] : a[x])
    if (c[y] < 0)
    {
      c[y] = c[x] ^ 1;
      dfs(y);
    }
    else if (c[y] == c[x])
    {
      cout << "NO" << endl;
      exit(0);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--)
  {
    int t, x, y;
    cin >> t >> x >> y;
    a[--x].push_back({--y, t});
    a[y].push_back({x, t});
  }

  c.assign(n, -1);
  for (int i = 0; i < n; i++)
    if (c[i] < 0)
    {
      c[i] = 0;
      dfs(i);
    }

  vector<vector<int>> edges(n);
  vector<int> degIn(n);
  auto addEdge = [&](int x, int y)
  {
    edges[x].push_back(y);
    degIn[y]++;
  };

  for (int i = 0; i < n; i++)
    for (auto [j, t] : a[i])
      if ((t == 1) ^ c[i]) addEdge(i, j);
      else addEdge(j, i);

  vector<int> q, coor(n);
  for (int i = 0; i < n; i++)
    if (!degIn[i])
      q.push_back(i);

  for (int i = 0; i < size(q); i++)
  {
    int x = q[i];
    coor[x] = i;
    for (int y : edges[x])
      if (!--degIn[y])
        q.push_back(y);
  }

  if (size(q) < n) cout << "NO\n";
  else
  {
    cout << "YES\n";
    for (int i = 0; i < n; i++)
      cout << "LR"[c[i]] << ' ' << coor[i] << '\n';
  }
}