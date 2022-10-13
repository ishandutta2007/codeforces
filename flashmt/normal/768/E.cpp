#include <bits/stdc++.h>
using namespace std;

map<long long, int> g[66];

int calc(int x, long long mask)
{
  if (!x)
    return 0;
  if (g[x].count(mask))
    return g[x][mask];

  set<int> s;
  for (int i = 1; i <= x; i++)
    if (mask >> i & 1 ^ 1)
      s.insert(calc(x - i, mask | 1LL << i));

  g[x][mask] = 0;
  while (s.count(g[x][mask]))
    g[x][mask]++;
  return g[x][mask];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  cin >> n;
  while (n--)
  {
    int x;
    cin >> x;
    ans ^= calc(x, 0);
  }
  cout << (ans ? "NO" : "YES") << endl;
}