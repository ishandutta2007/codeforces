#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int m, n, a[1010][1010];

void fill(int x, int y, int v)
{
  if (a[x][y] < 0) a[x][y] = v;
  else if (a[x][y] != v)
  {
    cout << 0 << endl;
    exit(0);
  }
}

int main()
{
  memset(a, -1, sizeof a);
  cin >> m >> n;
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++)
      fill(i, j, 1);
    if (x < n)
      fill(i, x, 0);
  }
  for (int j = 0; j < n; j++)
  {
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
      fill(i, j, 1);
    if (x < m)
      fill(x, j, 0);
  }

  int ans = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] < 0)
        ans = ans * 2 % BASE;
  cout << ans << endl;
}