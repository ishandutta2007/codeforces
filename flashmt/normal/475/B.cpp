#include <bits/stdc++.h>
using namespace std;

int m, n, visited[22][22];
string horizontal, vertical;

void visit(int x, int y)
{
  if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) return;
  visited[x][y] = 1;
  if (horizontal[x] == '<') visit(x, y - 1);
  else visit(x, y + 1);
  if (vertical[y] == '^') visit(x - 1, y);
  else visit(x + 1, y);
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> m >> n >> horizontal >> vertical;
  
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      memset(visited, 0, sizeof visited);
      visit(i, j);
      for (int ii = 0; ii < m; ii++)
        for (int jj = 0; jj < n; jj++)
          if (!visited[ii][jj])
          {
            cout << "NO" << endl;
            return 0;
          }
    }
  
  cout << "YES" << endl;
}