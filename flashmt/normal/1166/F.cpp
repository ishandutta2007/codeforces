using namespace std;
#include <bits/stdc++.h>

int ds[100100];
set <int> neighbors[100100];
map <pair<int, int>, int> coloredNode;

int get(int x)
{
  return ds[x] == x ? x : ds[x] = get(ds[x]);
}

void join(int x, int y)
{
  int dx = get(x), dy = get(y);
  if (dx != dy)
  {
    if (neighbors[dx].size() < neighbors[dy].size())
      swap(dx, dy);
    for (int u : neighbors[dy])
      neighbors[dx].insert(u);
    ds[dy] = dx;
  }
}

void addEdge(int x, int y, int z)
{
  neighbors[get(x)].insert(y);
  if (!coloredNode.count({y, z})) coloredNode[{y, z}] = x;
  else join(coloredNode[{y, z}], x);
}

string query(int x, int y)
{
  int dx = get(x), dy = get(y);
  return dx == dy || neighbors[dx].count(y) ? "Yes" : "No";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, c, q, x, y, z;
  cin >> n >> m >> c >> q;
  for (int i = 1; i <= n; i++)
  {
    ds[i] = i;
    neighbors[i].insert(i);
  }

  while (m--)
  {
    cin >> x >> y >> z;
    addEdge(x, y, z);
    addEdge(y, x, z);
  }
  while (q--)
  {
    char t;
    cin >> t >> x >> y;
    if (t == '?') cout << query(x, y) << '\n';
    else
    {
      cin >> z;
      addEdge(x, y, z);
      addEdge(y, x, z);
    }
  }
}