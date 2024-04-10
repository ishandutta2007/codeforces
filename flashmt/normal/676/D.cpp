#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int REV[] = {2, 3, 0, 1};

struct Triple
{
  int x, y, z;
};

int m, n, dist[1010][1010][4], a[1010][1010];

int get(char c)
{
  switch (c)
  {
    case '+': return 15;
    case '-': return 10;
    case '|': return 5;
    case '^': return 1;
    case '>': return 2;
    case 'v': return 4;
    case '<': return 8;
    case 'U': return 14;
    case 'R': return 13;
    case 'D': return 11;
    case 'L': return 7;
    case '*': return 0;
  }
  assert(0);
  return -1;
}

int hasDoor(int x, int y, int z, int dir)
{
  return a[x][y] >> ((dir + 4 - z) % 4) & 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int sx, sy, fx, fy;

  cin >> m >> n;
  for (int i = 0; i < m; i++)
  {
    cin >> s;
    for (int j = 0; j < n; j++)
      a[i][j] = get(s[j]);
  }
  cin >> sx >> sy >> fx >> fy;
  sx--;
  sy--;
  fx--;
  fy--;

  memset(dist, -1, sizeof dist);
  queue <Triple> q;
  q.push({sx, sy, 0});
  dist[sx][sy][0] = 0;
  while (!q.empty())
  {
    Triple u = q.front();
    q.pop();
    if (u.x == fx && u.y == fy)
    {
      cout << dist[u.x][u.y][u.z] << endl;
      return 0;
    }

    int z = (u.z + 1) % 4;
    if (dist[u.x][u.y][z] < 0)
    {
      dist[u.x][u.y][z] = dist[u.x][u.y][u.z] + 1;
      q.push({u.x, u.y, z});
    }

    for (int i = 0; i < 4; i++)
    {
      int x = u.x + dx[i], y = u.y + dy[i];
      if (x < 0 || y < 0 || x >= m || y >= n)
        continue;
      if (hasDoor(u.x, u.y, u.z, i) && hasDoor(x, y, u.z, REV[i]))
        if (dist[x][y][u.z] < 0)
        {
          dist[x][y][u.z] = dist[u.x][u.y][u.z] + 1;
          q.push({x, y, u.z});
        }
    }
  }

  cout << -1 << endl;
}