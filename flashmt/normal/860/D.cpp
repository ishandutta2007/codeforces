#include <bits/stdc++.h>
using namespace std;

struct Tour
{
  int x, y, z;
};

int n, d[200200], flag[200200];
vector <int> treeEdges[200200];
set <int> extraEdges[200200];
vector <Tour> ans;

int get(int x)
{
  return x == d[x] ? x : d[x] = get(d[x]);
}

int visit(int x, int par)
{
  flag[x] = 1;
  for (int y : treeEdges[x])
    if (y != par)
      if (visit(y, x))
        extraEdges[x].insert(y);

  while (extraEdges[x].size() >= 2)
  {
    int u = *extraEdges[x].begin();
    extraEdges[x].erase(u);
    extraEdges[u].erase(x);
    int v = *extraEdges[x].begin();
    extraEdges[x].erase(v);
    extraEdges[v].erase(x);
    ans.push_back({u, x, v});
  }

  if (extraEdges[x].empty() || !par)
    return 1;
  int y = *extraEdges[x].begin();
  extraEdges[y].erase(x);
  ans.push_back({y, x, par});
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int m, x, y;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    d[i] = i;
  while (m--)
  {
    cin >> x >> y;
    int dx = get(x), dy = get(y);
    if (dx != dy)
    {
      treeEdges[x].push_back(y);
      treeEdges[y].push_back(x);
      d[dx] = dy;
    }
    else
    {
      extraEdges[x].insert(y);
      extraEdges[y].insert(x);
    }
  }

  for (int i = 1; i <= n; i++)
    if (!flag[i])
      visit(i, 0);

  cout << ans.size() << '\n';
  for (auto t : ans)
    cout << t.x << ' ' << t.y << ' ' << t.z << '\n';
}