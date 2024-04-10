#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 2e5;
const int oo = 27081993;

vector<int> a[N];
int f[N][2];

void dfs(int x, int par = -1)
{
  vector<int> curF(3, oo);
  curF[0] = 0;
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      vector<int> newF(3, oo);
      for (int i = 0; i < 3; i++)
      {
        newF[i] = curF[i] + min(f[y][0], f[y][1]);
        if (i)
          newF[i] = min(newF[i], curF[i - 1] + f[y][1]);
      }
      swap(newF, curF);
    }

  f[x][0] = min(curF[1], curF[2] - 1);
  f[x][1] = min(curF[0] + 1, curF[1]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, u, v;
  cin >> n >> u >> v;
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  if (u >= v)
  {
    int maxDeg = 0;
    for (int i = 0; i < n; i++)
      maxDeg = max(maxDeg, int(size(a[i])));

    long long ans = (n - 1LL) * v;
    if (maxDeg == n - 1)
      ans += u - v;
    cout << ans << endl;
  }
  else
  {
    dfs(0, -1);
    long long ans = (n - 1LL) * u;
    ans += (min(f[0][0], f[0][1]) - 1LL) * (v - u);
    cout << ans << endl;
  }
}