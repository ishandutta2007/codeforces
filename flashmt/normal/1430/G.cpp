#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int n, m, w[20][20], sumW[20], hasEdge[1 << 18], sumWMask[1 << 18], leaves[1 << 18];
int f[20][1 << 18], tr[20][1 << 18];

int main()
{
  cin >> n >> m;
  vector<int> isRoot(n, 1);
  for (int i = 0; i < m; i++)
  {
    int x, y, c;
    cin >> x >> y >> c;
    w[--x][--y] = c;
    sumW[x] += c;
    sumW[y] -= c;
    isRoot[y] = 0;
  }

  int maskAll = (1 << n) - 1;
  for (int v = 0; v <= n; v++)
    for (int mask = 0; mask <= maskAll; mask++)
      f[v][mask] = oo;

  for (int mask = 0; mask < 1 << n; mask++)
  {
    leaves[mask] = mask;
    for (int i = 0; i < n; i++)
      if (mask >> i & 1)
      {
        sumWMask[mask] += sumW[i];
        for (int j = 0; j < n; j++)
          if ((mask >> j & 1) && w[i][j])
          {
            hasEdge[mask] = 1;
            leaves[mask] &= maskAll ^ (1 << i);
          }
      }
  }

  int ans = oo, bestV = -1;
  f[0][0] = 0;
  for (int v = 0; v <= min(n, m + 1); v++)
    for (int mask = 0; mask <= maskAll; mask++)
      if (f[v][mask] != oo)
      {
        if (mask == maskAll && ans > f[v][mask])
        {
          ans = f[v][mask];
          bestV = v;
        }

        int invMask = leaves[maskAll ^ mask];
        for (int submask = invMask; submask; submask = (submask - 1) & invMask)
          if (!hasEdge[submask])
          {
            // set all nodes in submask to v + 1
            int newMask = mask | submask;
            int newF = f[v][mask] + sumWMask[submask] * (v + 1);
            if (f[v + 1][newMask] > newF)
            {
              f[v + 1][newMask] = newF;
              tr[v + 1][newMask] = mask;
            }
          }
      }

  vector<int> a(n);
  for (int v = bestV, mask = maskAll; v; v--)
  {
    int submask = mask ^ tr[v][mask];
    for (int i = 0; i < n; i++)
      if (submask >> i & 1)
        a[i] = v;
    mask = tr[v][mask];
  }

  for (int x : a)
    cout << x << ' ';
}