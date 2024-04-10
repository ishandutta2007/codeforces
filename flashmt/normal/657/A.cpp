#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d, h;
  cin >> n >> d >> h;
  if (d == 1 && n > 2)
  {
    cout << -1 << endl;
    return 0;
  }

  if (h * 2 < d)
  {
    cout << -1 << endl;
    return 0;
  }

  int rest = n - d - 1;
  for (int i = 1; i <= h; i++)
    cout << i << ' ' << i + 1 << '\n';
  int cur = h + 2;
  if (d > h)
  {
    cout << cur++ << ' ' << 1 << '\n';
    for (int i = 0; i < d - h - 1; i++, cur++)
      cout << cur << ' ' << cur - 1 << '\n';
  }
  while (cur <= n)
    cout << cur++ << ' ' << h << '\n';
}