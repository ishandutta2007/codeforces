#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const int LOG = 18;
const int oo = 1 << 30;

vector<pair<int, int>> a[N];
int enjoyment[N], ds[N], bestCity[N], maxToll[N];
int depth[N], p[N][LOG], f[N][LOG]; // parent and max toll path

void dfs(int x)
{
  for (auto [y, toll] : a[x])
    if (y != p[x][0])
    {
      p[y][0] = x;
      f[y][0] = toll;
      depth[y] = depth[x] + 1;
      for (int i = 0; i + 1 < LOG; i++)
        if (p[y][i] >= 0)
        {
          p[y][i + 1] = p[p[y][i]][i];
          f[y][i + 1] = max(f[y][i], f[p[y][i]][i]);
        }

      dfs(y);
    }
}

int getPath(int x, int y)
{
  if (depth[x] > depth[y])
    swap(x, y);

  int res = 0;
  for (int i = LOG - 1; i >= 0; i--)
    if (depth[y] - (1 << i) >= depth[x])
    {
      res = max(res, f[y][i]);
      y = p[y][i];
    }

  if (x == y)
    return res;

  for (int i = LOG - 1; i >= 0; i--)
    if (p[x][i] != p[y][i])
    {
      res = max({res, f[x][i], f[y][i]});
      x = p[x][i];
      y = p[y][i];
    }

  res = max({res, f[x][0], f[y][0]});
  return res;
}

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

void join(int x, int y)
{
  int dx = get(x), dy = get(y);
  ds[dy] = dx;
  if (enjoyment[bestCity[dx]] < enjoyment[bestCity[dy]])
  {
    bestCity[dx] = bestCity[dy];
    maxToll[dx] = maxToll[dy];
  }
  else if (enjoyment[bestCity[dx]] == enjoyment[bestCity[dy]])
  {
    maxToll[dx] = max({maxToll[dx], maxToll[dy], getPath(bestCity[dx], bestCity[dy])});
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    cin >> enjoyment[i];
    bestCity[i] = ds[i] = i;
  }
  vector<tuple<int, int, int, int>> e;
  for (int i = 1; i < n; i++)
  {
    int x, y, cap, toll;
    cin >> x >> y >> cap >> toll;
    a[--x].push_back({--y, toll});
    a[y].push_back({x, toll});
    e.push_back({cap, oo, x, y});
  }
  for (int i = 0; i < q; i++)
  {
    int x, cap;
    cin >> cap >> x;
    e.push_back({cap, i, --x, 0});
  }

  memset(p, -1, sizeof p);
  dfs(0);

  sort(rbegin(e), rend(e));
  vector<pair<int, int>> ans(q);
  for (auto [_, id, x, y] : e)
    if (id == oo) join(x, y);
    else
    {
      int dx = get(x);
      ans[id] = {enjoyment[bestCity[dx]], max(maxToll[dx], getPath(x, bestCity[dx]))};
    }

  for (auto [x, y] : ans)
    cout << x << ' ' << y << '\n';
}