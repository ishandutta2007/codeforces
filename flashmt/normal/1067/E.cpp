#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n;
vector<int> a[500500];
long long f[500500][2], ways[500500][2];

void dfs(int x, int par)
{
  ways[x][0] = 1;
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      long long oldF[2] = {f[x][0], f[x][1]}, oldWays[2] = {ways[x][0], ways[x][1]};
      long long sumFY = (f[y][0] + f[y][1]) % BASE, sumWaysY = (ways[y][0] + ways[y][1]) % BASE;
      // delete edge
      for (int i = 0; i < 2; i++)
      {
        f[x][i] = (oldWays[i] * sumFY + oldF[i] * sumWaysY) % BASE;
        ways[x][i] = oldWays[i] * sumWaysY % BASE;
      }
      // keep edge
      f[x][1] = (f[x][1] + oldWays[0] * (f[y][0] + ways[y][0]) + oldF[0] * ways[y][0]) % BASE;
      f[x][1] = (f[x][1] + oldWays[1] * sumFY + oldF[1] * sumWaysY) % BASE;
      ways[x][1] = (ways[x][1] + oldWays[0] * ways[y][0] + oldWays[1] * sumWaysY) % BASE;
      f[x][0] = (f[x][0] + oldWays[0] * f[y][1] + oldF[0] * ways[y][1]) % BASE;
      ways[x][0] = (ways[x][0] + oldWays[0] * ways[y][1]) % BASE;
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dfs(1, 0);
  cout << (f[1][0] + f[1][1]) * 2 % BASE << endl;
}