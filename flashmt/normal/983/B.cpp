#include <bits/stdc++.h>
using namespace std;

int n, a[5555][5555], f[5555][5555];

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i][i];
    f[i][i] = a[i][i];
  } 

  for (int l = 2; l <= n; l++)
    for (int i = 1; i + l - 1 <= n; i++)
    {
      int j = i + l - 1;
      f[i][j] = max(f[i][j - 1], f[i + 1][j]);
      a[i][j] = a[i][j - 1] ^ a[i + 1][j];
      f[i][j] = max(f[i][j], a[i][j]);
    }

  int q, l, r;
  cin >> q;
  while (q--)
  {
    cin >> l >> r;
    cout << f[l][r] << '\n';
  }
}