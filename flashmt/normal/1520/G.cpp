#include <bits/stdc++.h>
using namespace std;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, -1, 0, 1};
const long long oo = 1LL << 60;

int m, n, w, a[2020][2020], dist[2][2020][2020];
long long minDist[2] = {oo, oo};

void bfs(int id, int x, int y)
{
  memset(dist[id], -1, sizeof dist[id]);
  dist[id][x][y] = 0;
  queue<pair<int, int>> q;
  q.push({x, y});
  while (!q.empty())
  {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    if (a[x][y] > 0)
      minDist[id] = min(minDist[id], 1LL * w * dist[id][x][y] + a[x][y]);
    for (int i = 0; i < 4; i++)
    {
      int xx = x + DX[i], yy = y + DY[i];
      if (xx >= 0 && xx < m && yy >= 0 && yy < n && dist[id][xx][yy] < 0 && a[xx][yy] >= 0)
      {
        dist[id][xx][yy] = dist[id][x][y] + 1;
        q.push({xx, yy});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n >> w;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  bfs(0, 0, 0);
  long long ans = oo;
  if (dist[0][m - 1][n - 1] >= 0)
    ans = 1LL * dist[0][m - 1][n - 1] * w;
  bfs(1, m - 1, n - 1);
  ans = min(ans, minDist[0] + minDist[1]);
  cout << (ans == oo ? -1 : ans) << endl;
}