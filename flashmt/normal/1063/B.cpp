#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;
const long long Z = 1LL << 31;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int m, n, sx, sy, isGood[2020][2020], done[2020][2020];
string a[2020];
pair<int, int> dist[2020][2020];

int isValidCell(int x, int y)
{
  return x >= 0 && x < m && y >= 0 && y < n && a[x][y] == '.';
}

void bfs(pair<int, int> maxDist)
{
  priority_queue<pair<long long, int>> q;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      done[i][j] = 0;
      dist[i][j] = {oo, oo};
    }

  dist[sx][sy] = {0, 0};
  q.push({0, sx * n + sy});

  while (!q.empty())
  {
    auto [_, v] = q.top();
    q.pop();
    int x = v / n, y = v % n;
    if (done[x][y])
      continue;
    done[x][y] = isGood[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
      int xx = x + dx[i], yy = y + dy[i];
      pair<int, int> newDist(dist[x][y].first + (i == 2), dist[x][y].second + (i == 3));
      if (newDist.first > maxDist.first || newDist.second > maxDist.second)
        continue;
      if (isValidCell(xx, yy) && newDist < dist[xx][yy])
      {
        dist[xx][yy] = newDist;
        q.push({-dist[xx][yy].first * Z - dist[xx][yy].second, xx * n + yy});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int maxL, maxR;
  cin >> m >> n >> sx >> sy >> maxL >> maxR;
  sx--;
  sy--;
  for (int i = 0; i < m; i++)
    cin >> a[i];

  maxL = min(maxL, m * n);
  maxR = min(maxR, m * n);
  bfs({maxL, maxR});
  swap(dy[2], dy[3]);
  bfs({maxR, maxL});

  int ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      ans += isGood[i][j];

  cout << ans << endl;
}