#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n;
vector<int> a[200200];
long long f[200200][3];

void dfs(int x, int par)
{
  int sz = a[x].size(), idPar = sz;
  vector<long long> prefix(sz + 1, 1), suffix(sz + 1, 1);
  for (int i = 0; i < sz; i++)
  {
    int y = a[x][i];
    if (y == par) idPar = i;
    else
    {
      dfs(y, x);
      prefix[i] = (f[y][0] + f[y][1]) % BASE;
    }
    if (i)
      prefix[i] = prefix[i] * prefix[i - 1] % BASE;
  }

  for (int i = sz - 1; i >= 0; i--)
  {
    int y = a[x][i];
    if (y == par) suffix[i] = suffix[i + 1];
    else suffix[i] = suffix[i + 1] * (f[y][0] + f[y][2]) % BASE;
  }

  // x is selected in an edge with its child
  for (int i = 0; i < idPar; i++)
  {
    long long ways = f[a[x][i]][2];
    if (i)
      ways = ways * prefix[i - 1] % BASE;
    if (i + 1 < sz)
      ways = ways * suffix[i + 1] % BASE;
    f[x][0] = (f[x][0] + ways) % BASE;
  }

  // x is selected in (x, par)
  f[x][1] = 1;
  if (idPar)
    f[x][1] = f[x][1] * prefix[idPar - 1] % BASE;
  if (idPar + 1 < sz)
    f[x][1] = f[x][1] * suffix[idPar + 1] % BASE;

  // par is selected in (x, par)
  f[x][2] = prefix[sz - 1]; // x is never selected
  for (int i = idPar + 1; i < sz; i++) // x is selected at this edge
  {
    long long ways = f[a[x][i]][2];
    if (i)
      ways = ways * prefix[i - 1] % BASE;
    if (i + 1 < sz)
      ways = ways * suffix[i + 1] % BASE;
    f[x][2] = (f[x][2] + ways) % BASE;
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

  dfs(1, 0);
  cout << (f[1][0] + f[1][2]) % BASE << endl;
}