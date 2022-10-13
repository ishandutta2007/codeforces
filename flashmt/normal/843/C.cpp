#include <bits/stdc++.h>
using namespace std;
const int N = 200200;

int n, sz[N], isCentroid[N], par[N];
vector<int> a[N], centroids, line;
vector<tuple<int, int, int>> ans;

void dfs(int x)
{
  sz[x] = isCentroid[x] = 1;
  for (int y : a[x])
    if (y != par[x])
    {
      par[y] = x;
      dfs(y);
      sz[x] += sz[y];
      if (sz[y] * 2 > n)
        isCentroid[x] = 0;
    }

  if ((n - sz[x]) * 2 > n)
    isCentroid[x] = 0;

  if (isCentroid[x])
    centroids.push_back(x);
}

// turn subtree at root into a line
void go(int x, int root)
{
  for (int y : a[x])
    if (y != par[x])
    {
      par[y] = x;
      go(y, root);
    }

  int u = line.back();
  if (par[u] != x)
  {
    if (isCentroid[u]) ans.push_back({u, root, x});
    else ans.push_back({u, par[u], x});
  }
  line.push_back(x);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }
  par[0] = -1;
  dfs(0);

  for (auto x : centroids)
  {
    par[x] = -1;
    for (auto y : a[x])
      if (!isCentroid[y])
      {
        par[y] = x;
        line = {x};
        go(y, y);
        // turn line into a star
        if (size(line) >= 4)
        {
          int center = line[size(line) - 2];
          for (int i = size(line) - 3; i; i--)
            ans.push_back({line[i - 1], line[i], center});
        }
      }
  }

  cout << size(ans) << '\n';
  for (auto [x, y, z] : ans)
    cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
}