#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, s, a[2][1010];
  cin >> n >> s;
  for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];

  if (!a[0][1]) cout << "NO";
  else if (a[0][s]) cout << "YES";
  else
  {
    for (int i = s + 1; i <= n; i++)
      if (a[0][i] && a[1][i] && a[1][s])
      {
        cout << "YES";
        return 0;
      }
    cout << "NO";
  }
}