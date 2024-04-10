#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> m >> n;
  if (m == 1 && n == 1)
  {
    cout << 0 << endl;
    return 0;
  }

  int r[555], c[555];
  if (m == 1)
  {
    for (int i = 1; i <= m; i++)
      r[i] = i;
    for (int i = 1; i <= n; i++)
      c[i] = m + i;
  }
  else
  {
    for (int i = 1; i <= n; i++)
      c[i] = i;
    for (int i = 1; i <= m; i++)
      r[i] = n + i;
  }

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      cout << r[i] * c[j] << " \n"[j == n];
}