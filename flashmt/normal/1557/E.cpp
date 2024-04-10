#include <bits/stdc++.h>
using namespace std;
const vector<int> DX = {-1, -1, 0, 1, 1, 1, 0, -1};
const vector<int> DY = {0, 1, 1, 1, 0, -1, -1, -1};
const vector<string> DIR = {"Up", "Up-Right", "Right", "Down-Right", "Down", "Down-Left", "Left", "Up-Left", "Done"};

int go(int x, int y)
{
  cout << x + 1 << ' ' << y + 1 << endl;
  cout.flush();
  string resp;
  cin >> resp;
  return find(begin(DIR), end(DIR), resp) - begin(DIR);
}

int canAttack(int x, int y, int xx, int yy)
{
  return (x == xx || y == yy || x + y == xx + yy || x - y == xx - yy) && (x != xx || y != yy);
}

void getAttackCell(int &x, int &y, int kingX, int kingY)
{
  int resX = -1, resY = -1, bestDist = 8;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      if (canAttack(x, y, i, j) && i != kingX && j != kingY)
        if ((kingX < 4) ^ (i < kingX))
          if ((kingY < 4) ^ (j < kingY))
          {
            int dist = abs(i - kingX) + abs(j - kingY);
            if (dist < bestDist)
            {
              bestDist = dist;
              resX = i;
              resY = j;
            }
          }

  assert(resX >= 0);
  x = resX;
  y = resY;
}

int isValidCell(int x, int y)
{
  return 0 <= x && x < 8 && 0 <= y && y < 8;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    vector<vector<int>> isBad(8, vector<int>(8));
    int x = 3, y = 3;
    if (go(x, y) == 8)
      continue;

    isBad[x][y] = 1;
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        isBad[i][j] = canAttack(x, y, i, j);

    vector<int> kingMoves;
    int win = 0, moveCnt = 0;
    while (!win && moveCnt < 130)
    {
      int initialX = -1, initialY = -1;
      for (int i = 0; i < 8 && initialX < 0; i++)
        for (int j = 0; j < 8; j++)
          if (!isBad[i][j])
          {
            initialX = i;
            initialY = j;
            break;
          }

      assert(initialX >= 0);
      int kingX = initialX, kingY = initialY;
      for (int d : kingMoves)
      {
        kingX += DX[d];
        kingY += DY[d];
        if (!isValidCell(kingX, kingY))
          isBad[initialX][initialY] = 1;
      }

      if (isBad[initialX][initialY])
        continue;

      while (1)
      {
        getAttackCell(x, y, kingX, kingY);
        int d = go(x, y);
        moveCnt++;
        if (d == 8)
        {
          win = 1;
          break;
        }
        kingMoves.push_back(d);
        kingX += DX[d];
        kingY += DY[d];
        if (!isValidCell(kingX, kingY) || canAttack(x, y, kingX, kingY) || (kingX == x && kingY == y))
          break;
      }

      isBad[initialX][initialY] = 1;
    }
  }
}