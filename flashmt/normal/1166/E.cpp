#include <bits/stdc++.h>
using namespace std;

int s[55], a[55][10100], flag[10100];

int intersect(int ii, int i)
{
  for (int j = 0; j < s[ii]; j++)
    if (flag[a[ii][j]] == i)
      return 1;
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  int m, n;
  cin >> m >> n;
  memset(flag, -1, sizeof flag);
  for (int i = 0; i < m; i++)
  {
    cin >> s[i];
    for (int j = 0; j < s[i]; j++)
    {
      cin >> a[i][j];
      flag[a[i][j]] = i;
    }

    for (int ii = 0; ii < i; ii++)
      if (!intersect(ii, i))
      {
        cout << "impossible\n";
        return 0;
      }
  }

  cout << "possible\n";
}