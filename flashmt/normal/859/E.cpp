#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int n, isCurrentSeat[200200], flag[200200], onCycle[200200];
vector <int> a[200200], cycle, path;
long long f[200200][2];

long long power(long long x, int y)
{
  if (!y)
    return 1;
  long long res = power(x, y / 2);
  if (y % 2)
    res = res * x % BASE;
  return res;
}

void visit(int x)
{
  flag[x] = -1;
  if (a[x].empty())
  {
    f[x][0] = f[x][1] = 1;
    return;
  }

  f[x][1] = 1;
  for (int y : a[x])
    if (!onCycle[y])
    {
      visit(y);
      f[x][1] = f[x][1] * f[y][1] % BASE;
    }
  for (int y : a[x])
    f[x][0] = (f[x][0] + f[x][1] * power(f[y][1], BASE - 2) % BASE * f[y][0]) % BASE;
  f[x][0] = (f[x][0] + f[x][1]) % BASE;
}

void dfs(int x)
{
  flag[x] = 1;
  path.push_back(x);
  for (int y : a[x])
    if (!flag[y]) dfs(y);
    else if (flag[y] == 1)
    {
      for (int i = int(path.size()) - 1; i >= 0; i--)
      {
        onCycle[path[i]] = 1;
        cycle.push_back(path[i]);
        if (path[i] == y)
          break;
      }
    }
  flag[x] = 2;
  path.pop_back();
}

long long solveCycle()
{
  long long res = 1;
  for (int x : cycle)
  {
    visit(x);
    res = res * f[x][1] % BASE;
  }
  if (cycle.size() > 1)
    res = res * 2 % BASE;
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int x, y;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    isCurrentSeat[x] = 1;
    a[y].push_back(x);
  }

  long long ans = 1;
  for (int i = 1; i <= n * 2; i++)
    if (!isCurrentSeat[i] && !a[i].empty())
    {
      visit(i);
      ans = ans * f[i][0] % BASE;
    }

  for (int i = 1; i <= n * 2; i++)
    if (!flag[i] && !a[i].empty())
    {
      cycle.clear();
      dfs(i);
      ans = ans * solveCycle() % BASE;
    }

  cout << ans << endl;
}