#include <bits/stdc++.h>
using namespace std;
const int N = 3030;

vector<int> a[N];
int par[N], preDfs[N], postDfs[N], dfsTime, cnt[N];
long long f[N][N];

void visit(int x)
{
  preDfs[x] = ++dfsTime;
  cnt[x] = 1;
  for (int y : a[x])
    if (y != par[x])
    {
      par[y] = x;
      visit(y);
      cnt[x] += cnt[y];
    }
  postDfs[x] = dfsTime;
}

int isAncestor(int x, int y)
{
  return preDfs[x] <= preDfs[y] && postDfs[y] <= postDfs[x];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }
  par[0] = -1;
  visit(0);

  vector<pair<int, int>> q;
  for (int i = 1; i < n; i++)
  {
    f[par[i]][i] = cnt[i] * (n - cnt[i]);
    q.push_back({par[i], i});
  }

  while (!empty(q))
  {
    vector<pair<int, int>> newQ;
    for (auto [x, y] : q)
    {
      int yAnc = -1;
      for (int z : a[x])
      {
        if (z == par[x])
          continue;
        if (isAncestor(z, y)) yAnc = z;
        else
        {
          if (!f[z][y])
            newQ.push_back({z, y});
          f[z][y] = max(f[z][y], f[x][y] + cnt[z] * cnt[y]);
        }
      }

      for (int z : a[y])
      {
        if (z == par[y])
          continue;
        if (!f[x][z])
          newQ.push_back({x, z});
        f[x][z] = max(f[x][z], f[x][y] + cnt[z] * (isAncestor(x, y) ? n - cnt[yAnc] : cnt[x]));
      }

      if (isAncestor(x, y) && par[x] >= 0)
      {
        if (!f[par[x]][y])
          newQ.push_back({par[x], y});
        f[par[x]][y] = max(f[par[x]][y], f[x][y] + cnt[y] * (n - cnt[x]));
      }
    }
    swap(q, newQ);
  }

  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans = max(ans, f[i][j]);

  cout << ans << endl;
}