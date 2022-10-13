#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, p[2020], match[2020] = {0}, t;
  cin >> n >> m;
  for (int i = 1; i <= n * 2; i++)
    cin >> p[i];
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    match[x] = y;
    match[y] = x;
  }
  cin >> t;

  int used[2020] = {0}, x = 0;
  if (t == 2)
    cin >> x;
  for (int turn = 0; turn < n; turn++)
  {
    used[x] = 1;
    int y = 0;
    if (match[x] && !used[match[x]]) y = match[x];
    else
    {
      int bestDif = -1;
      for (int i = 1; i <= n * 2; i++)
        if (!used[i] && match[i] && p[i] - p[match[i]] > bestDif)
        {
          bestDif = p[i] - p[match[i]];
          y = i;
        }
    }

    if (!y)
    {
      int maxP = 0;
      for (int i = 1; i <= n * 2; i++)
        if (!used[i] && p[i] > maxP)
        {
          maxP = p[i];
          y = i;
        }
    }

    assert(y);
    cout << y << endl;
    used[y] = 1;
    cout.flush();

    if (turn == n - 1 && t == 2)
      break;

    cin >> x;
  }
}