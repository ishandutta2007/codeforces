#include <bits/stdc++.h>
using namespace std;

bool waysLeft[101][101][11100], waysRight[101][101][11100];

int main()
{
  int n, a[101];
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  sort(a + 1, a + n + 1);

  for (int i = 2; i < n; i++)
    if (a[i] == a[1] && a[i + 1] == a[n])
    {
      cout << n << endl;
      return 0;
    }

  waysLeft[0][0][0] = 1;
  for (int i = 1, sum = 0; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
      for (int k = 0; k <= sum; k++)
        if (waysLeft[i - 1][j][k])
          waysLeft[i][j][k] = waysLeft[i][j + 1][k + a[i]] = 1;
    sum += a[i];
  }

  waysRight[n + 1][0][0] = 1;
  for (int i = n, sum = 0; i; i--)
  {
    for (int j = 0; j < i; j++)
      for (int k = 0; k <= sum; k++)
        if (waysRight[i + 1][j][k])
          waysRight[i][j][k] = waysRight[i][j + 1][k + a[i]] = 1;
    sum += a[i];
  }

  int ans = 1;
  for (int i = 1; i <= n;)
  {
    int j = i + 1;
    while (j <= n && a[j] == a[i])
      j++;

    for (int cnt = 1; cnt <= j - i; cnt++)
    {
      int found = 0, sum = cnt * a[i];
      for (int k = 0; k <= cnt; k++)
        for (int p = 0; p <= sum; p++)
          if (waysLeft[i - 1][k][p] && waysRight[j][cnt - k][sum - p])
          {
            found = 1;
            break;
          }

      if (found)
        break;
      ans = max(ans, cnt);
    }

    i = j;
  }

  cout << ans << endl;
}