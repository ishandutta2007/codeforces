#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

void addMod(int &x, int y)
{
  x += y;
  if (x >= BASE)
    x -= BASE;
}

void minusMod(int &x, int y)
{
  x -= y;
  if (x < 0)
    x += BASE;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<vector<int>> f(201, vector<int>(2, 0));
  for (int i = 1; i <= 200; i++)
    if (a[0] == -1) f[i][0] = i;
    else f[i][0] = i >= a[0];

  for (int i = 1; i < n; i++)
  {
    vector<vector<int>> newF(201, vector<int>(2, 0));
    for (int j = 1; j <= 200; j++)
    {
      if (a[i] < 0 || j == a[i])
      {
        newF[j][0] = f[j - 1][0] + f[j - 1][1];
        if (newF[j][0] >= BASE)
          newF[j][0] -= BASE;
        newF[j][1] = f[j][0] - f[j - 1][0];
        if (newF[j][1] < 0)
          newF[j][1] += BASE;
        addMod(newF[j][1], f[200][1]);
        minusMod(newF[j][1], f[j - 1][1]);
      }

      for (int k = 0; k < 2; k++)
        addMod(newF[j][k], newF[j - 1][k]);
    }

    f = newF;
  }

  cout << f[200][1] << endl;
}