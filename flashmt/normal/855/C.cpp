#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int n, k, num, m;
long long f[100100][11][3];
vector <int> a[100100];

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y / 2);
  res = res * res % BASE;
  if (y % 2)
    res = res * x % BASE;
  return res;
}

void addMod(long long &x, long long y)
{
  x = (x + y) % BASE;
}

void visit(int x, int par)
{
  f[x][0][0] = m - k;
  f[x][0][1] = k - 1;
  f[x][1][2] = 1;
  long long g[11][3];
  for (int y : a[x])
    if (y != par)
    {
      visit(y, x);
      memset(g, 0, sizeof g);
      for (int i = 0; i <= num; i++)
        for (int j = 0; i + j <= num; j++)
        {
          addMod(g[i + j][0], f[x][i][0] * f[y][j][0]);
          addMod(g[i + j][0], f[x][i][0] * f[y][j][1]);
          addMod(g[i + j][1], f[x][i][1] * f[y][j][0]);
          addMod(g[i + j][1], f[x][i][1] * f[y][j][1]);
          addMod(g[i + j][1], f[x][i][1] * f[y][j][2]);
          addMod(g[i + j][2], f[x][i][2] * f[y][j][1]);
        }

      for (int i = 0; i <= num; i++)
        for (int j = 0; j < 3; j++)
          f[x][i][j] = g[i][j];
    }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int x, y;
  cin >> n >> m;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  cin >> k >> num;
  visit(1, 0);

  long long ans = 0;
  for (int i = 0; i <= num; i++)
    for (int j = 0; j < 3; j++)
      addMod(ans, f[1][i][j]);
  cout << ans << endl;
}