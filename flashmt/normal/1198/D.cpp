#include <bits/stdc++.h>
using namespace std;

int n, a[55][55], f[55][55][55][55];

int dp(int x, int y, int xx, int yy)
{
  if (a[x][y] + a[xx][yy] == a[x][yy] + a[xx][y])
    return 0;
  int &res = f[x][y][xx][yy];
  if (res >= 0)
    return res;
    
  res = max(xx - x, yy - y);
  for (int i = x + 1; i < xx; i++)
    res = min(res, dp(x, y, i, yy) + dp(i, y, xx, yy));
  for (int i = y + 1; i < yy; i++)
    res = min(res, dp(x, y, xx, i) + dp(x, i, xx, yy));
  return res;
}

int main()
{
  string s;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> s;
    for (int j = 0; j < n; j++)
      a[i][j + 1] = a[i][j] + a[i - 1][j + 1] - a[i - 1][j] + (s[j] == '#');
  }

  memset(f, -1, sizeof f);
  cout << dp(0, 0, n, n) << endl;
}