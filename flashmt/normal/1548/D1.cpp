#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;

int getEdge(int u, int v)
{
  return (a[u].first ^ a[v].first) | (a[u].second ^ a[v].second);
}

int isLess(int x, int y, int z, int xx, int yy, int zz)
{
  if (x < xx)
    return 1;
  if (x > xx)
    return 0;
  if (y < yy)
    return 1;
  if (y > yy)
    return 0;
  return z < zz;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a.push_back({x / 2 % 2, y / 2 % 2});
  }

  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    int cnt[2][2][2] = {0};
    for (int j = 0; j < n; j++)
      if (i != j)
        cnt[a[j].first][a[j].second][getEdge(i, j)]++;

    int done[2][2][2] = {0};
    for (int x = 0; x < 2; x++)
      for (int y = 0; y < 2; y++)
        for (int z = 0; z < 2; z++)
          for (int xx = 0; xx < 2; xx++)
            for (int yy = 0; yy < 2; yy++)
              for (int zz = 0; zz < 2; zz++)
              {
                int sum = ((x ^ xx) | (y ^ yy)) + z + zz;
                if (sum % 2)
                  continue;

                if (x == xx && y == yy && z == zz)
                {
                  if (done[x][y][z])
                    continue;
                  done[x][y][z] = 1;
                  ans += (cnt[x][y][z] - 1LL) * cnt[x][y][z] / 2;
                }
                else if (isLess(x, y, z, xx, yy, zz))
                {
                  ans += 1LL * cnt[x][y][z] * cnt[xx][yy][zz];
                }
              }
  }

  cout << ans / 3 << endl;
}