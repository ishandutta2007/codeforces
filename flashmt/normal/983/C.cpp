#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

struct Node
{
  int i, x, y, z, floor, lastOne;
};

int n, a[2020], b[2020], f[2020][10][10][10][10][2];
queue <Node> q;

void go(int i, int x, int y, int z, int floor, int lastOne, int dist)
{
  if (f[i][x][y][z][floor][lastOne] < 0)
  {
    f[i][x][y][z][floor][lastOne] = dist + 1;
    q.push({i, x, y, z, floor, lastOne});
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  memset(f, -1, sizeof f);
  f[0][0][0][0][a[0]][1] = a[0];
  q.push({0, 0, 0, 0, a[0], 1});
  while (!q.empty())
  {
    Node cur = q.front();
    q.pop();
    int i = cur.i, x = cur.x, y = cur.y, z = cur.z, floor = cur.floor, lastOne = cur.lastOne;
    int dist = f[i][x][y][z][floor][lastOne];
    if (i == n - 1 && x + y + z + lastOne == 0)
    {
      cout << dist << endl;
      return 0;
    }
    if (lastOne && b[i] == floor) go(i, x, y, z, floor, 0, dist);
    else if (x == floor) go(i, 0, y, z, floor, lastOne, dist);
    else if (y == floor) go(i, x, 0, z, floor, lastOne, dist);
    else if (z == floor) go(i, x, y, 0, floor, lastOne, dist);
    else if (i + 1 < n && a[i + 1] == floor)
    {
      if (!lastOne) go(i + 1, x, y, z, floor, 1, dist);
      else if (!x) go(i + 1, b[i], y, z, floor, 1, dist);
      else if (!y) go(i + 1, x, b[i], z, floor, 1, dist);
      else if (!z) go(i + 1, x, y, b[i], floor, 1, dist);
    }
    if (floor < 9)
      go(i, x, y, z, floor + 1, lastOne, dist);
    if (floor > 1)
      go(i, x, y, z, floor - 1, lastOne, dist);
  }
}