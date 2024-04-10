#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x[1010], y[1010];
  cin >> n;
  if (n == 2)
  {
    cout << 1 << endl << 1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
    x[i] += 1000000;
    y[i] += 1000000;
  }

  while (1)
  {
    int cnt[2][2] = {0};
    for (int i = 0; i < n; i++)
      cnt[x[i] % 2][y[i] % 2]++;

    if (cnt[0][0] + cnt[1][1] && cnt[0][1] + cnt[1][0])
    {
      cout << cnt[0][0] + cnt[1][1] << endl;
      for (int i = 0; i < n; i++)
        if (x[i] % 2 == y[i] % 2)
          cout << i + 1 << ' ';
      return 0;
    }

    if (cnt[0][0] && cnt[1][1])
    {
      cout << cnt[1][1] << endl;
      for (int i = 0; i < n; i++)
        if (x[i] % 2 && y[i] % 2)
          cout << i + 1 << ' ';
      return 0;
    }

    if (cnt[0][1] && cnt[1][0])
    {
      cout << cnt[1][0] << endl;
      for (int i = 0; i < n; i++)
        if (x[i] % 2 && y[i] % 2 == 0)
          cout << i + 1 << ' ';
      return 0;
    }

    for (int i = 0; i < n; i++)
    {
      x[i] /= 2;
      y[i] /= 2;
    }
  }
}