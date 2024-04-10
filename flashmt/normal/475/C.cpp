#include <bits/stdc++.h>
using namespace std;

int m, n, rowStart[1010], rowEnd[1010], colStart[1010], colEnd[1010], sum[1010][1010];
int startX = -1, startY;
string a[1010];

void quit()
{
  cout << -1 << endl;
  exit(0);
}

int getSum(int x, int y, int row, int col)
{
  return sum[x][y] + sum[x - row][y - col] - sum[x - row][y] - sum[x][y - col];
}

int ok(int row, int col)
{
  int x = startX + row - 1, y = startY + col - 1, covered = col * row;
  while (1)
  {
    if (x < m && getSum(x + 1, y, row, col) == row * col)
    {
      x++;
      covered += col;
    }
    else if (y < n && getSum(x, y + 1, row, col) == row * col)
    {
      y++;
      covered += row;
    }
    else break;
  }
  
  return covered == sum[m][n];
}

void solve()
{
  int sideRow = colEnd[startY] - colStart[startY] + 1;
  int sideCol = rowEnd[startX] - rowStart[startX] + 1;
  
  int ans = m * n + 1;
  for (int col = 1; col <= sideCol; col++)
    if (ok(sideRow, col))
    {
      ans = min(ans, sideRow * col);
      break;
    }
    
  for (int row = 1; row <= sideRow; row++)
    if (ok(row, sideCol))
    {
      ans = min(ans, sideCol * row);
      break;
    }
    
  if (ans > m * n) ans = -1;
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> m >> n;
  for (int i = 1; i <= m; i++) 
  {
    cin >> a[i];
    rowStart[i] = rowEnd[i] = -1;
    int cntX = 0;
    
    for (int j = 1; j <= n; j++)
    {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      if (a[i][j - 1] == 'X')
      {
        if (startX < 0) 
        {
          startX = i;
          startY = j;
        }
        if (rowStart[i] < 0) rowStart[i] = j;
        rowEnd[i] = j;
        cntX++;
        sum[i][j]++;
      }
    }
      
    if (rowStart[i] > 0 && cntX != rowEnd[i] - rowStart[i] + 1) quit();
  }
  
  for (int j = 1; j <= n; j++)
  {
    colStart[j] = colEnd[j] = -1;
    int cntX = 0;
    
    for (int i = 1; i <= m; i++)
      if (a[i][j - 1] == 'X')
      {
        if (colStart[j] < 0) colStart[j] = i;
        colEnd[j] = i;
        cntX++;
      }
      
    if (colStart[j] > 0 && cntX != colEnd[j] - colStart[j] + 1) quit();
  }
  
  solve();
}