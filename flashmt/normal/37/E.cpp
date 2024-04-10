#include <bits/stdc++.h>
using namespace std;
const vector<pair<int, int>> DIR = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int m, n;
string a[55];

int findFurthestBlack(int sx, int sy)
{
  int res = -1;
  vector<vector<int>> dist(m, vector<int>(n, -1));
  deque<pair<int, int>> q;
  dist[sx][sy] = 0;
  q.push_back({sx, sy});

  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop_front();
    if (a[x][y] == 'B')
      res = dist[x][y];

    for (auto [dx, dy] : DIR)
    {
      int xx = x + dx, yy = y + dy;
      if (xx >= 0 && xx < m && yy >= 0 && yy < n && dist[xx][yy] < 0)
      {
        if (a[xx][yy] == a[x][y])
        {
          dist[xx][yy] = dist[x][y];
          q.push_front({xx, yy});
        }
        else
        {
          dist[xx][yy] = dist[x][y] + 1;
          q.push_back({xx, yy});
        }
      }
    }
  }

  return res;
}

int main()
{
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    cin >> a[i];

  int ans = m * n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      ans = min(ans, findFurthestBlack(i, j) + 1);

  cout << ans << endl;
}