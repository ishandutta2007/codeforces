#include <bits/stdc++.h>
using namespace std;
const int BIT = 19;

int a[300300], f[300300][BIT];

int check(int x, int y)
{
  for (int i = 0; i < BIT; i++)
    if ((a[y] >> i & 1) && f[x][i] <= y)
      return 1;
  return 0;
}

int main()
{
  int n, q, x, y;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);

  vector <int> last(BIT, n);
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < BIT; j++)
      f[i][j] = n;

    for (int j = 0; j < BIT; j++)
      if (a[i] >> j & 1)
      {
        f[i][j] = i;
        for (int k = 0; k < BIT; k++)
          if (last[j] < n)
            f[i][k] = min(f[i][k], f[last[j]][k]);
        last[j] = i;
      }
  }

  while (q--)
  {
    scanf("%d%d", &x, &y);
    puts((check(--x, --y) ? "Shi" : "Fou"));
  }
}