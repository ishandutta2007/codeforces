#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n, k;
vector<int> a[5555];
int f[5555][5555];

void add(int &x, int y)
{
  x += y;
  if (x >= BASE)
    x -= BASE;
}

void visit(int x, int par)
{
  vector<int> oldF(n + 1);
  for (int i = 0; i <= k; i++)
    f[x][i] = 1;

  for (int y : a[x])
    if (y != par)
    {
      visit(y, x);
      for (int i = 0; i <= k; i++)
      {
        oldF[i] = f[x][i];
        f[x][i] = 0;
      }

      for (int i = 0; i <= k; i++)
      {
        long long curFx = oldF[i];
        if (i)
          curFx = (curFx - oldF[i - 1] + BASE) % BASE;
        add(f[x][i], curFx * f[y][k] % BASE);
        if (!i) continue;

        int maxJ = k - 1 - i;
        add(f[x][i], curFx * f[y][min(maxJ, i - 1)] % BASE);
        long long curFy = f[y][i - 1];
        if (i > 1)
          curFy = (curFy - f[y][i - 2] + BASE) % BASE;
        add(f[x][i], curFy * oldF[min(i - 1, maxJ + 1)] % BASE);
      }

      for (int i = 1; i <= k; i++)
        add(f[x][i], f[x][i - 1]);
    }
}

int main()
{
  cin >> n >> k;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  visit(1, 0);
  cout << f[1][k] << endl;
}