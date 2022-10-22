#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 3e5 + 128, logn = 19;
int l[logn][maxn], a[maxn], c[maxn];
int nz(int vr)
{
  for (int i = logn - 1; i >= 0; i--)
    if (a[l[i][vr]]) vr = l[i][vr];
  return vr;
}
int main()
{
  //ios::sync_with_stdio(false);
  //cin.tie(0);
  int q;
  cin >> q >> a[0] >> c[0];
  for (int nd = 1; nd <= q; nd++)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      cin >> l[0][nd] >> a[nd] >> c[nd];
      for (int i = 1; i < logn; i++)
        l[i][nd] = l[i-1][l[i-1][nd]];
    }
    else
    {
      int v, w;
      cin >> v >> w;
      int rw = 0;
      ll p = 0;
      while (a[v] && w)
      {
        int u = nz(v);
        ll buy = min(w, a[u]);
        w -= buy, a[u] -= buy, rw += buy;
        p += buy * (ll)c[u];
      }
      cout << rw << " " << p << endl;
    }
  }
  return 0;
}