#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int N = 4e5 + 5;
const int DX[] = {-1, 0, 1, 0, 0};
const int DY[] = {0, 1, 0, -1, 0};

int n, m;
vector<int> a[N], isBad[N], flag[N];
int badCnt, iter;

int isValid(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < m;
}

int checkBad(int x, int y)
{
  for (int i = 0; i < 4; i++)
  {
    int xx = x + DX[i], yy = y + DY[i];
    if (isValid(xx, yy) && a[xx][yy] < a[x][y])
      return 0;
  }
  return 1;
}

int move(int x, int y, int xx, int yy)
{
  ++iter;
  swap(a[x][y], a[xx][yy]);

  int newBadCnt = badCnt;
  vector<pair<int, int>> cand = {{x, y}, {xx, yy}};
  for (auto [curX, curY] : cand)
    for (int i = 0; i < 5; i++)
    {
      int checkX = curX + DX[i], checkY = curY + DY[i];
      if (checkX < 0 || checkX >= n || checkY < 0 || checkY >= m || flag[checkX][checkY] == iter)
        continue;
      flag[checkX][checkY] = iter;
      newBadCnt -= isBad[checkX][checkY];
      newBadCnt += checkBad(checkX, checkY);
    }

  swap(a[x][y], a[xx][yy]);
  return newBadCnt == 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      int x;
      cin >> x;
      a[i].push_back(--x);
    }

  pair<int, int> badPos(-1, -1);
  for (int i = 0; i < n; i++)
  {
    isBad[i].assign(m, 0);
    flag[i].assign(m, 0);
    for (int j = 0; j < m; j++)
    {
      isBad[i][j] = checkBad(i, j);
      if (isBad[i][j])
      {
        badCnt++;
        if (a[i][j] && badPos.first < 0)
          badPos = {i, j};
      }
    }
  }

  if (badCnt == 1) cout << 0 << endl;
  else
  {
    set<pair<int, int>> ans;
    for (int i = 0; i < 5; i++)
    {
      int x = badPos.first + DX[i], y = badPos.second + DY[i];
      if (!isValid(x, y))
        continue;
      for (int xx = 0; xx < n; xx++)
        for (int yy = 0; yy < m; yy++)
          if ((xx != x || yy != y) && move(x, y, xx, yy))
          {
            int u = a[x][y], v = a[xx][yy];
            if (u > v)
              swap(u, v);
            ans.insert({u, v});
          }
    }

    if (empty(ans)) cout << 2 << endl;
    else cout << 1 << ' ' << size(ans) << endl;
  }
}