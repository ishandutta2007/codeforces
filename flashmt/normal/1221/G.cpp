#include <bits/stdc++.h>
using namespace std;

int n, flag[40];
long long a[40];

int dfs(int x, int par)
{
  int isBipartite = 1;
  for (int y = 0; y < n; y++)
    if ((a[x] >> y & 1) && y != par)
    {
      if (flag[y] >= 0) isBipartite &= flag[y] != flag[x];
      else
      {
        flag[y] = flag[x] ^ 1;
        isBipartite &= dfs(y, x);
      }
    }
  return isBipartite;
}

long long calcIndependentSet()
{
  int n0 = n / 2, n1 = n - n0;
  vector<int> cnt(1 << n0, 0);
  for (int mask = 0; mask < 1 << n0; mask++)
  {
    long long adjMask = 0;
    for (int i = 0; i < n0; i++)
      if (mask >> i & 1)
        adjMask |= a[i];

    if (!(adjMask & mask))
      cnt[mask]++;
  }

  for (int i = 0; i < n0; i++)
    for (int mask = 0; mask < 1 << n0; mask++)
      if (mask >> i & 1)
        cnt[mask] += cnt[mask ^ 1 << i];

  long long res = 0;
  for (int mask = 0; mask < 1 << n1; mask++)
  {
    long long adjMask = 0;
    for (int i = 0; i < n1; i++)
      if (mask >> i & 1)
        adjMask |= a[n0 + i];

    if (!(adjMask >> n0 & mask))
      res += cnt[adjMask % (1 << n0) ^ ((1 << n0) - 1)];
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> n >> m;
  if (n < 3 || !m)
  {
    cout << 0 << endl;
    return 0;
  }
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[x - 1] |= 1LL << y - 1;
    a[y - 1] |= 1LL << x - 1;
  }

  int isBipartite = 1, numComponent = 0;
  memset(flag, -1, sizeof flag);
  for (int i = 0; i < n; i++)
    if (flag[i] < 0)
    {
      flag[i] = 0;
      numComponent++;
      isBipartite &= dfs(i, -1);
    }

  int numIso = 0;
  for (int i = 0; i < n; i++)
    numIso += !a[i];

  long long ans = 1LL << n;
  ans -= calcIndependentSet() * 2 + (1LL << numComponent);
  ans += 1LL << numIso + 1;
  if (isBipartite)
    ans += 1LL << numComponent;
  cout << ans << endl;
}