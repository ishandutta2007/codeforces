#include <bits/stdc++.h>
using namespace std;

vector<int> a[200200], b[200200];
int flag[200200], hasCycle, f[200200], g[200200];

void visitA(int x)
{
  flag[x] = 1;
  f[x] = x;
  for (int y : a[x])
  {
    if (!flag[y]) visitA(y);
    else if (flag[y] > 0) hasCycle = 1;
    f[x] = min(f[x], f[y]);
  }
  flag[x] = -1;
}

void visitB(int x)
{
  flag[x] = 1;
  g[x] = x;
  for (int y : b[x])
  {
    if (!flag[y])
      visitB(y);
    g[x] = min(g[x], g[y]);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    b[y].push_back(x);
  }

  for (int i = 0; i < n; i++)
  {
    a[n].push_back(i);
    b[n].push_back(i);
  }
  visitA(n);
  memset(flag, 0, sizeof flag);
  visitB(n);

  for (int i = 0; i < n; i++)
    if (!flag[i])
      hasCycle = 1;

  if (hasCycle)
  {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += f[i] == i && g[i] == i;
  cout << ans << endl;
  for (int i = 0; i < n; i++)
    cout << (f[i] == i && g[i] == i ? 'A' : 'E');
  cout << endl;
}