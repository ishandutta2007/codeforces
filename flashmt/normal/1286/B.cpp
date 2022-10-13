#include <bits/stdc++.h>
using namespace std;

int n, c[2020], p[2020], subtree[2020], id[2020];
vector<int> a[2020];

void dfs(int x)
{
  subtree[x] = 1;
  for (int y : a[x])
  {
    dfs(y);
    subtree[x] += subtree[y];
  }
}

void solve(int x, int from, int to)
{
  if (c[x] > to - from)
  {
    cout << "NO\n";
    exit(0);
  }

  id[to] = x;
  if (a[x].empty())
    return;

  int cur = from;
  for (int y : a[x])
  {
    solve(y, cur, cur + subtree[y] - 1);
    cur += subtree[y];
  }

  for (int i = to; i > from + c[x]; i--)
    id[i] = id[i - 1];
  id[from + c[x]] = x;
}

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> p[i] >> c[i];
    a[p[i]].push_back(i);
  }
  dfs(a[0][0]);
  solve(a[0][0], 1, n);

  cout << "YES\n";
  int ans[2020];
  for (int i = 1; i <= n; i++)
    ans[id[i]] = i;
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
}