#include <bits/stdc++.h>
using namespace std;

int ds[200200];

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, r[200200];
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    ds[i] = r[i] = i;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    int dx = get(x), dy = get(y);
    if (dx != dy)
    {
      if (dx > dy) ds[dx] = dy;
      else ds[dy] = dx;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    int di = get(i);
    r[di] = max(r[di], i);
  }

  int curR = 0, ans = 0;
  for (int i = 1; i <= n; i++)
    if (get(i) == i)
    {
      if (i <= curR)
        ans++;
      curR = max(curR, r[i]);
    }

  cout << ans << endl;
}