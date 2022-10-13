#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> a[500500];
long long f[500500][2];

void dfs(int x, int par)
{
  f[x][0] = f[x][1] = 0;
  vector<long long> children;
  for (auto u : a[x])
  {
    int y = u.first, w = u.second;
    if (y == par)
      continue;
    dfs(y, x);
    f[x][0] += max(f[y][0], f[y][1]);
    long long gain = f[y][0] + w - max(f[y][0], f[y][1]);
    if (gain > 0)
      children.push_back(gain);
  }

  sort(children.begin(), children.end(), greater<long long>());
  f[x][1] = f[x][0];
  for (int i = 0; i < children.size(); i++)
  {
    if (i < k - 1)
      f[x][0] += children[i];
    if (i < k)
      f[x][1] += children[i];
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
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
      int x, y, w;
      cin >> x >> y >> w;
      a[x].push_back({y, w});
      a[y].push_back({x, w});
    }

    dfs(1, 0);
    cout << max(f[1][0], f[1][1]) << '\n';

    for (int i = 1; i <= n; i++)
      a[i].clear();
  }
}