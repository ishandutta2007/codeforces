#include <bits/stdc++.h>
using namespace std;

int n, subtree[200200];
vector<pair<int, int>> a[200200];
long long minAns, maxAns;

void dfs(int x, int par)
{
  subtree[x] = 1;
  for (auto [y, z] : a[x])
    if (y != par)
    {
      dfs(y, x);
      if (subtree[y] % 2)
        minAns += z;
      maxAns += 1LL * z * min(subtree[y], n - subtree[y]);
      subtree[x] += subtree[y];
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
    cin >> n;
    n *= 2;
    for (int i = 1; i <= n; i++)
      a[i].clear();
    for (int i = 1; i < n; i++)
    {
      int x, y, z;
      cin >> x >> y >> z;
      a[x].push_back({y, z});
      a[y].push_back({x, z});
    }

    minAns = maxAns = 0;
    dfs(1, 0);
    cout << minAns << ' ' << maxAns << '\n';
  }
}