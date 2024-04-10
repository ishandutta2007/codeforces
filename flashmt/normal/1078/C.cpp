#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n;
vector<int> a[300300];
long long f[300300][3];
// 0: no down edge
// 1: matched by 1 down edge
// 2: has at least 1 down edge but unmatched

void dfs(int x, int par)
{
  f[x][0] = 1;
  if (a[x].size() == 1 && par)
    return;
  f[x][2] = 1;

  vector<long long> f1Left(a[x].size(), 1);
  long long badF2 = 1;
  for (int i = 0; i < a[x].size(); i++)
  {
    int y = a[x][i];
    if (i)
      f1Left[i] = f1Left[i - 1];
    if (y == par)
      continue;

    dfs(y, x);
    f[x][0] = f[x][0] * (f[y][0] + f[y][1]) % BASE;
    f1Left[i] = f1Left[i] * ((f[y][0] + f[y][1] * 2) % BASE) % BASE;
    f[x][2] = f[x][2] * (f[y][0] + f[y][1] * 2) % BASE;
    badF2 = badF2 * (f[y][0] + f[y][1]) % BASE;
  }

  f[x][2] = (f[x][2] - badF2 + BASE) % BASE;

  long long f1Right = 1;
  for (int i = int(a[x].size()) - 1; i >= 0; i--)
  {
    int y = a[x][i];
    if (y == par)
      continue;

    long long waysF1 = (f[y][0] + f[y][2]) * f1Right % BASE;
    if (i)
      waysF1 = waysF1 * f1Left[i - 1] % BASE;
    f[x][1] = (f[x][1] + waysF1) % BASE;

    f1Right = f1Right * ((f[y][0] + f[y][1] * 2) % BASE) % BASE;
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

  if (n == 1)
  {
    cout << 1 << endl;
    return 0;
  }

  dfs(1, 0);
  cout << (f[1][0] + f[1][1]) % BASE << endl;
}