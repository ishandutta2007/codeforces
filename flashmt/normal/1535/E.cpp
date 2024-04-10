#include <bits/stdc++.h>
using namespace std;

int a[300300], c[300300], p[300300][20], depth[300300];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(p, -1, sizeof p);
  int q;
  cin >> q >> a[0] >> c[0];
  for (int x = 1; x <= q; x++)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      cin >> p[x][0] >> a[x] >> c[x];
      depth[x] = depth[p[x][0]] + 1;
      for (int i = 1; 1 << i <= depth[x]; i++)
        if (p[x][i - 1] >= 0)
          p[x][i] = p[p[x][i - 1]][i - 1];
    }
    else
    {
      int v, w, total = 0;
      cin >> v >> w;
      long long ans = 0;
      while (total < w)
      {
        int u = v;
        for (int i = 19; i >= 0; i--)
          if (p[u][i] >= 0 && a[p[u][i]])
            u = p[u][i];

        int buy = min(a[u], w - total);
        ans += 1LL * buy * c[u];
        total += buy;
        a[u] -= buy;
        if (u == v)
          break;
      }
      cout << total << ' ' << ans << endl;
    }
  }
}