#include <bits/stdc++.h>
using namespace std;

int n, p[100100], curP[100100], depth[100100], maxDepth[100100];
vector<int> a[100100], ops, bamboo;

void dfs(int x)
{
  maxDepth[x] = depth[x];
  for (int y : a[x])
  {
    depth[y] = depth[x] + 1;
    dfs(y);
    maxDepth[x] = max(maxDepth[x], maxDepth[y]);
  }
}

void solve(int x)
{
  if (x)
  {
    curP[x] = bamboo.back();
    while (curP[x] != p[x])
    {
      curP[x] = curP[curP[x]];
      ops.push_back(x);
    }
  }
  bamboo.push_back(x);

  sort(a[x].begin(), a[x].end(), [](int u, int v) { return maxDepth[u] < maxDepth[v]; });
  for (int y : a[x])
    solve(y);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> p[i];
    a[p[i]].push_back(i);
  }

  dfs(0);
  solve(0);
  for (int x : bamboo)
    cout << x << ' ';
  cout << endl << ops.size() << endl;
  for (int x : ops)
    cout << x << ' ';
}