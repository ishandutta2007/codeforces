#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  int root = -1;
  for (int i = 0; i < n; i++)
    if (size(a[i]) > 1)
      root = i;

  int maxAns = n - 1, leafDist[2] = {0};

  function<int(int, int, int)> dfs = [&](int x, int par, int dist)
  {
    int isLeaf = 1, cntLeaf = 0;
    for (int y : a[x])
      if (y != par)
      {
        cntLeaf += dfs(y, x, dist ^ 1);
        isLeaf = 0;
      }

    maxAns -= max(0, cntLeaf - 1);
    if (isLeaf)
      leafDist[dist] = 1;

    return isLeaf;
  };

  dfs(root, -1, 0);
  cout << (leafDist[0] && leafDist[1] ? 3 : 1) << ' ' << maxAns << endl;
}