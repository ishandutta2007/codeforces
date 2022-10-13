#include <bits/stdc++.h>
using namespace std;

int n, fib[30], isFib[200200], sz[200200], isBlocked[200200];
vector<pair<int, int>> a[200200];

void dfs(int x, int par)
{
  sz[x] = 1;
  for (auto [y, edgeId] : a[x])
    if (!isBlocked[edgeId] && y != par)
    {
      dfs(y, x);
      sz[x] += sz[y];
    }
}

int findSubtree(int x, int par, int fibId)
{
  for (auto [y, edgeId] : a[x])
    if (!isBlocked[edgeId] && y != par)
    {
      if (sz[y] == fib[fibId - 1] || sz[y] == fib[fibId - 2])
      {
        isBlocked[edgeId] = 1;
        return y;
      }

      if (sz[y] < fib[fibId - 2])
        continue;
      int res = findSubtree(y, x, fibId);
      if (res)
        return res;
    }

  return 0;
}

int solve(int x, int fibId)
{
  if (fibId <= 3)
    return 1;

  dfs(x, 0);
  int y = findSubtree(x, 0, fibId);
  if (!y)
    return 0;
  if (sz[y] == fib[fibId - 1])
    return solve(x, fibId - 2) && solve(y, fibId - 1);
  return solve(x, fibId - 1) && solve(y, fibId - 2);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fib[0] = fib[1] = 1;
  isFib[1] = 1;
  for (int i = 2; i <= 26; i++)
  {
    fib[i] = fib[i - 1] + fib[i - 2];
    isFib[fib[i]] = i;
  }

  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back({y, i});
    a[y].push_back({x, i});
  }

  if (!isFib[n]) cout << "NO" << endl;
  else cout << (solve(1, isFib[n]) ? "YES" : "NO") << endl;
}