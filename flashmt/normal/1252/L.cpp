#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m, n;
  string a[111];
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++)
    for (int j = 1; j < n; j++)
      if (a[i][j] != a[i][0])
      {
        cout << "NO" << endl;
        return 0;
      }

  for (int i = 1; i < m; i++)
    if (a[i][0] == a[i - 1][0])
    {
      cout << "NO" << endl;
      return 0;
    }

  cout << "YES" << endl;
}