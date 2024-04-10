#include <bits/stdc++.h>
using namespace std;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

int m, n, d[1010][1010];
string a[1010];

int isValid(int x, int y)
{
  return x >= 0 && x < m && y >= 0 && y < n;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> m >> n >> t;
  for (int i = 0; i < m; i++)
    cin >> a[i];

  queue<pair<int, int>> q;
  memset(d, -1, sizeof d);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      int found = 0;
      for (int k = 0; k < 4; k++)
      {
        int ii = i + DX[k], jj = j + DY[k];
        if (isValid(ii, jj) && a[ii][jj] == a[i][j])
          found = 1;
      }
      if (found)
      {
        d[i][j] = 0;
        q.push({i, j});
      }
    }

  while (!empty(q))
  {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int xx = x + DX[i], yy = y + DY[i];
      if (isValid(xx, yy) && d[xx][yy] < 0)
      {
        d[xx][yy] = d[x][y] + 1;
        q.push({xx, yy});
      }
    }
  }

  while (t--)
  {
    int x, y;
    long long p;
    cin >> x >> y >> p;
    x--;
    y--;
    if (p <= d[x][y] || d[x][y] < 0) cout << a[x][y] << '\n';
    else cout << (p % 2 == d[x][y] % 2 ? a[x][y] : char(a[x][y] ^ '0' ^ '1')) << '\n';
  }
}