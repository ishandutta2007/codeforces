#include <bits/stdc++.h>
using namespace std;

int n, c[200200], maxC[200200];
vector<int> a[200200];
set<int> optimal;
long long f[200200];

void dfs(int x, int par)
{
  maxC[x] = -1;
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      f[x] += f[y];
      maxC[x] = max(maxC[x], maxC[y]);
    }

  if (maxC[x] < 0) f[x] = maxC[x] = c[x];
  else if (c[x] < maxC[x])
  {
    f[x] += c[x] - maxC[x];
    maxC[x] = c[x];
  }
}

void trace(int x, int par, int canPick)
{
  if (c[x] == maxC[x] && canPick)
    optimal.insert(x);

  int maxChild = -1, cntMax = 1;
  for (int y : a[x])
    if (y != par)
    {
      if (maxC[y] == maxChild) cntMax++;
      else if (maxC[y] > maxChild)
      {
        maxChild = maxC[y];
        cntMax = 1;
      }
    }

  for (int y : a[x])
    if (y != par)
    {
      if (c[x] > maxChild) trace(y, x, maxC[y] < maxChild || cntMax > 1 || canPick);
      else trace(y, x, maxC[y] < maxChild || cntMax > 1 || (canPick && maxC[y] == c[x]));
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dfs(1, 0);
  trace(1, 0, 1);
  cout << f[1] << ' ' << optimal.size() << endl;
  for (int x : optimal)
    cout << x << ' ';
}