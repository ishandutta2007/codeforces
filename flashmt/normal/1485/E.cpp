#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 50;

int n, par[200200], depth[200200], maxDepth, num[200200];
vector<int> a[200200], atDepth[200200];
long long f[200200], fChild[200200];

void visit(int x)
{
  maxDepth = max(maxDepth, depth[x]);
  atDepth[depth[x]].push_back(x);
  for (int y : a[x])
    if (y != par[x])
    {
      depth[y] = depth[x] + 1;
      par[y] = x;
      visit(y);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      a[i].clear();
      f[i] = fChild[i] = 0;
    }

    for (int i = 2; i <= n; i++)
    {
      int v;
      cin >> v;
      a[i].push_back(v);
      a[v].push_back(i);
    }
    for (int i = 2; i <= n; i++)
      cin >> num[i];

    depth[1] = maxDepth = 0;
    visit(1);

    for (int d = maxDepth; d >= 0; d--)
    {
      int sz = atDepth[d].size();
      sort(atDepth[d].begin(), atDepth[d].end(), [](int u, int v) { return num[u] < num[v]; });

      // calc child
      for (int x : atDepth[d])
        for (int y : a[x])
          if (y != par[x])
            fChild[x] = max(fChild[x], f[y]);

      vector<long long> maxL(sz), maxR(sz);
      // calc left
      for (int i = 0; i < sz; i++)
      {
        int x = atDepth[d][i];
        maxL[i] = fChild[x] - num[x];
        if (i)
          maxL[i] = max(maxL[i], maxL[i - 1]);
      }

      // calc right
      for (int i = sz - 1; i >= 0; i--)
      {
        int x = atDepth[d][i];
        maxR[i] = fChild[x] + num[x];
        if (i + 1 < sz)
          maxR[i] = max(maxR[i], maxR[i + 1]);
      }

      // calc F
      for (int i = 0; i < sz; i++)
      {
        int x = atDepth[d][i];
        f[x] = max(num[x] - num[atDepth[d][0]], num[atDepth[d][sz - 1]] - num[x]) + fChild[x];
        if (i)
          f[x] = max(f[x], maxL[i - 1] + num[x]);
        if (i + 1 < sz)
          f[x] = max(f[x], maxR[i + 1] - num[x]);
      }
    }

    cout << f[1] << '\n';

    for (int i = 0; i <= maxDepth; i++)
      atDepth[i].clear();
  }
}