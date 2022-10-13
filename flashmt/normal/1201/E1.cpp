#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int DX[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int DY[] = {2, -2, 2, -2, 1, -1, 1, -1};

int n, m, dist[2][1010][1010];
pair<int, int> tr[2][1010][1010];

int isValid(int x, int y)
{
  return x > 0 && x <= m && y > 0 && y <= n;
}

void bfs(int z, int sx, int sy)
{
  memset(dist[z], -1, sizeof dist[z]);
  queue<pair<int, int>> q;
  dist[z][sx][sy] = 0;
  q.push({sx, sy});
  while (!q.empty())
  {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++)
    {
      int xx = x + DX[i], yy = y + DY[i];
      if (isValid(xx, yy) && dist[z][xx][yy] < 0)
      {
        dist[z][xx][yy] = dist[z][x][y] + 1;
        tr[z][xx][yy] = {x, y};
        q.push({xx, yy});
      }
    }
  }
}

int choose(int xw, int yw, int xb, int yb)
{
  int ww = dist[0][xw][yw], wb = dist[1][xw][yw];
  int bw = dist[0][xb][yb], bb = dist[1][xb][yb];
  if (ww <= bb && (ww < bw))
    return 0;
  if (bb < ww && (bb < wb - 1))
    return 1;
  if ((xw + yw) % 2 != (xb + yb) % 2)
    return 2;
  return 3;
}

void move(int x, int y, int c)
{
  cout << x << ' ' << y << '\n';
  cout.flush();
  if (c % 2 == 1 && x == m / 2 + 1 && y == n / 2)
    exit(0);
  if (c % 2 == 0 && x == m / 2 && y == n / 2)
    exit(0);
}


void getNextStep(int &c, int &x, int &y, int xx, int yy)
{
  for (int i = 0; i < 8; i++)
  {
    int tx = x + DX[i], ty = y + DY[i];
    if (tx == xx && ty == yy)
    {
      move(xx, yy, c);
      exit(0);
    }
  }

  if (c / 2 == 0)
  {
    tie(x, y) = tr[c % 2][x][y];
    return;
  }

  pair<int, int> best(oo, oo);
  int bestX = 0, bestY = 0;
  for (int i = 0; i < 8; i++)
  {
    int tx = x + DX[i], ty = y + DY[i];
    if (!isValid(tx, ty))
      continue;

    pair<int, int> cur(dist[1 - c % 2][tx][ty], dist[c % 2][tx][ty]);
    if (cur < best)
    {
      best = cur;
      bestX = tx;
      bestY = ty;
    }
  }

  x = bestX;
  y = bestY;
  assert(isValid(x, y));
  if (dist[1 - c % 2][x][y] == 1 && dist[c % 2][x][y] == 2)
    c -= 2;
}

int main()
{
  int xw, yw, xb, yb;
  cin >> m >> n >> xw >> yw >> xb >> yb;
  for (int i = 0; i < 8; i++)
  {
    int x = xw + DX[i], y = yw + DY[i];
    if (x == xb && y == yb)
    {
      cout << "WHITE\n" << xb << ' ' << yb << "\n";
      cout.flush();
      return 0;
    }
  }

  for (int i = 0; i < 2; i++)
    bfs(i, m / 2 + i, n / 2);

  int c = choose(xw, yw, xb, yb), x, y, xx, yy;
  cout << (c % 2 ? "BLACK\n" : "WHITE\n");
  if (c % 2)
  {
    x = xb; y = yb;
    xx = xw; yy = yw;
    cout.flush();
  }
  else
  {
    x = xw; y = yw;
    xx = xb; yy = yb;
    getNextStep(c, x, y, xx, yy);
    move(x, y, c);
  }

  while (1)
  {
    cin >> xx >> yy;
    getNextStep(c, x, y, xx, yy);
    move(x, y, c);
  }
}