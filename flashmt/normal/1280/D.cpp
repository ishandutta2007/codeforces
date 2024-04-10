#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, m, w[3333], subtree[3333];
vector<int> a[3333];
vector<pair<int, long long>> f[3333];
pair<int, long long> newF[3333];

void dfs(int x, int par)
{
  f[x] = vector<pair<int, long long>>(n + 1, make_pair(-oo, -oo));
  f[x][1] = {0, w[x]};
  subtree[x] = 1;
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);

      for (int i = 0; i <= subtree[x] + subtree[y]; i++)
        newF[i] = make_pair(-oo, -oo);

      for (int i = 1; i <= subtree[x]; i++)
        for (int j = 1; j <= subtree[y]; j++)
        {
          pair<int, long long> u(f[x][i].first + f[y][j].first, f[x][i].second + f[y][j].second);
          newF[i + j - 1] = max(newF[i + j - 1], u);

          pair<int, long long> v(f[x][i].first + f[y][j].first + (f[y][j].second > 0), f[x][i].second);
          newF[i + j] = max(newF[i + j], v);
        }

      subtree[x] += subtree[y];
      for (int i = 1; i <= subtree[x]; i++)
        f[x][i] = newF[i];
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      a[i].clear();

    for (int i = 1; i <= n; i++)
      cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
      int x;
      cin >> x;
      w[i] = x - w[i];
    }

    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    dfs(1, 0);
    cout << f[1][m].first + (f[1][m].second > 0) << endl;
  }
}