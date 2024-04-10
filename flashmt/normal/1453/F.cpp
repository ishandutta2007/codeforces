#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, a[3030], f[3030][3030];

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        f[i][j] = oo;

      for (int j = i - 1, cnt = 0; j >= 0; j--)
        if (j + a[j] >= i)
        {
          f[i][j + a[j]] = min(f[i][j + a[j]], f[j][i - 1] + cnt);
          cnt++;
        }

      for (int j = 1; j < n; j++)
        f[i][j] = min(f[i][j], f[i][j - 1]);
    }

    cout << f[n - 1][n - 1] << endl;
  }
}