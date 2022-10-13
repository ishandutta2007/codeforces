// simplify a bit

#include <bits/stdc++.h>
using namespace std;
const int N = 300300;

vector<int> a[N], depth, par;

void dfs(int x)
{
  for (int y : a[x])
    if (y != par[x])
    {
      par[y] = x;
      depth[y] = depth[x] + 1;
      dfs(y);
    }
}

vector<int> update(int x, int y)
{
  vector<int> pathX = {x}, pathY = {y};
  while (x != y)
  {
    int dx = depth[x], dy = depth[y];
    if (dx >= dy)
    {
      x = par[x];
      pathX.push_back(x);
    }
    if (dy >= dx)
    {
      y = par[y];
      pathY.push_back(y);
    }
  }

  pathY.pop_back();
  reverse(begin(pathY), end(pathY));
  for (int u : pathY)
    pathX.push_back(u);
  return pathX;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  par.assign(n, -1);
  depth.assign(n, 0);
  vector<int> ds(n);
  iota(begin(ds), end(ds), 0);

  function<int(int)> get = [&](int x)
  {
    return x == ds[x] ? x : ds[x] = get(ds[x]);
  };

  while (m--)
  {
    int x, y;
    cin >> x >> y;
    int dx = get(--x), dy = get(--y);
    if (dx != dy)
    {
      ds[dy] = dx;
      a[x].push_back(y);
      a[y].push_back(x);
    }
  }

  dfs(0);
  int q;
  cin >> q;
  vector<vector<int>> paths;
  vector<int> cnt(n);
  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> x >> y;
    paths.push_back(update(--x, --y));
    cnt[x] ^= 1;
    cnt[y] ^= 1;
  }

  int sumCnt = accumulate(begin(cnt), end(cnt), 0);
  if (sumCnt) cout << "NO" << endl << sumCnt / 2 << endl;
  else
  {
    cout << "YES\n";
    for (auto path : paths)
    {
      cout << size(path) << '\n';
      for (int x : path)
        cout << x + 1 << ' ';
      cout << '\n';
    }
  }
}