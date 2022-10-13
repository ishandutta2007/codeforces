#include <bits/stdc++.h>
using namespace std;
const int N = 3636;
const int BASE = 998244353;

long long fRow[N][N], fCol[N][N], c[N][N], fact[N];

void calc(int n, long long f[N][N], int flag[])
{
  f[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j * 2 <= i; j++)
    {
      f[i][j] = f[i - 1][j];
      if (i > 1 && j && !flag[i] && !flag[i - 1])
        f[i][j] = (f[i][j] + f[i - 2][j - 1]) % BASE;
    }
}

int main()
{
  for (int i = 0; i < N; i++)
    fact[i] = i ? fact[i - 1] * i % BASE : 1;
  for (int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % BASE : 1;

  int h, w, n, row[N] = {0}, col[N] = {0};
  cin >> h >> w >> n;
  while (n--)
  {
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    row[x] = row[xx] = col[y] = col[yy] = 1;
  }

  calc(h, fRow, row);
  calc(w, fCol, col);
  int emptyRow = 0, emptyCol = 0;
  for (int i = 1; i <= h; i++)
    emptyRow += !row[i];
  for (int i = 1; i <= w; i++)
    emptyCol += !col[i];

  long long ans = 0;
  for (int hor = 0; hor * 2 <= emptyCol; hor++)
    for (int ver = 0; ver * 2 <= emptyRow; ver++)
      if (hor + ver * 2 <= emptyRow && hor * 2 + ver <= emptyCol)
      {
        long long waysRow = fRow[h][ver] * c[emptyRow - ver * 2][hor] % BASE;
        long long waysCol = fCol[w][hor] * c[emptyCol - hor * 2][ver] % BASE;
        ans = (ans + waysRow * waysCol % BASE * fact[hor] % BASE * fact[ver]) % BASE;
      }

  cout << ans << endl;
}