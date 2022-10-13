#include <bits/stdc++.h>
using namespace std;

double a[11][11];

int main()
{
  int n;
  cin >> n >> a[1][1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
    {
      double overflow = max(0., a[i][j] - 1);
      a[i + 1][j] += overflow / 2;
      a[i + 1][j + 1] += overflow / 2;
      a[i][j] -= overflow;
    }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      ans += fabs(a[i][j] - 1) < 1e-9;
  cout << ans << endl;
}