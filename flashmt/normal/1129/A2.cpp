#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, x, y, cnt[5050] = {0}, closest[5050];

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    closest[i] = n;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    cnt[--x]++;
    --y;
    closest[x] = min(closest[x], (y - x + n) % n);
  }

  for (int i = 0; i < n; i++)
  {
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
      int id = (i + j) % n;
      if (cnt[id])
        ans = max(ans, (cnt[id] - 1) * n + closest[id] + j);
    }
    cout << ans << ' ';
  }
}