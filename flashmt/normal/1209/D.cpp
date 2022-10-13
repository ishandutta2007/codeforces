#include <bits/stdc++.h>
using namespace std;

int ds[100100];

int get(int x)
{
  return x == ds[x] ? x : ds[x] = get(ds[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    ds[i] = i;

  int ans = 0;
  while (k--)
  {
    int x, y;
    cin >> x >> y;
    int dx = get(x), dy = get(y);
    if (dx == dy) ans++;
    else ds[dx] = dy;
  }

  cout << ans << endl;
}