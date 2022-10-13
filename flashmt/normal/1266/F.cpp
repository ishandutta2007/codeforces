#include <bits/stdc++.h>
using namespace std;
const int N = 500500;

int n, ans[N], distDown[N], distUp[N];
vector<int> a[N], dists[N];

void dfsDown(int x, int par)
{
  for (int y : a[x])
    if (y != par)
    {
      dfsDown(y, x);
      dists[x].push_back(distDown[y] + 1);
      distDown[x] = max(distDown[x], distDown[y] + 1);
    }
}

void dfsUp(int x, int par)
{
  int maxDist = distUp[x], maxChild = par, secondMaxDist = 0;
  for (int y : a[x])
    if (y != par)
    {
      if (distDown[y] + 1 > maxDist)
      {
        secondMaxDist = maxDist;
        maxDist = distDown[y] + 1;
        maxChild = y;
      }
      else secondMaxDist = max(secondMaxDist, distDown[y] + 1);
    }

  for (int y : a[x])
    if (y != par)
    {
      distUp[y] = (y == maxChild ? secondMaxDist : maxDist) + 1;
      dists[y].push_back(distUp[y]);
      dfsUp(y, x);
    }
}

void solve(int x, int par)
{
  for (int y : a[x])
    if (y != par)
    {
      solve(y, x);
      for (int i = 1, j = 1; i < dists[x].size() && j < dists[y].size();)
      {
        int k = min(dists[x][i], dists[y][j]);
        ans[k * 2] = max(ans[k * 2], i + j);
        if (i + 1 == dists[x].size()) j++;
        else if (j + 1 == dists[y].size()) i++;
        else if (dists[x][i + 1] > dists[y][j + 1]) i++;
        else j++;
      }
    }
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
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dfsDown(1, 0);
  dfsUp(1, 0);

  for (int i = 1; i <= n; i++)
    ans[i] = 1;
  for (int i = 1; i <= n; i++)
  {
    ans[1] = max(ans[1], int(a[i].size()) + 1);
    sort(dists[i].begin(), dists[i].end(), greater<int>());
    for (int j = 1; j < dists[i].size(); j++)
    {
      int k = min(dists[i][j - 1] - 1, dists[i][j]);
      ans[k * 2 + 1] = max(ans[k * 2 + 1], j + 1);
      ans[dists[i][j] * 2] = max(ans[dists[i][j] * 2], j + 1);
    }
  }
  solve(1, 0);

  for (int i = n - 2; i; i--)
    ans[i] = max(ans[i], ans[i + 2]);

  for (int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
}