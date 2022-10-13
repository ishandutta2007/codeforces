#include <bits/stdc++.h>
using namespace std;

int n, a[555], value[555][555], f[555];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    value[i][i] = a[i];
  }

  for (int len = 2; len <= n; len++)
    for (int i = 0; i + len <= n; i++)
    {
      int j = i + len - 1;
      for (int k = i + 1; k <= j; k++)
        if (value[i][k - 1] && value[k][j] && value[i][k - 1] == value[k][j])
        {
          value[i][j] = value[k][j] + 1;
          break;
        }
    }

  for (int i = 1; i <= n; i++)
  {
    f[i] = i;
    for (int j = 0; j < i; j++)
      if (value[j][i - 1])
        f[i] = min(f[i], f[j] + 1);
  }

  cout << f[n] << endl;
}