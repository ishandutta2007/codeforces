#include <bits/stdc++.h>
using namespace std;

struct Snake
{
  int x, y, xx, yy;
};

int m, n, flag[2020][2020];
string a[2020];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cin >> m >> n;
    pair <int, int> minPos[26], maxPos[26];
    for (int i = 0; i < 26; i++)
    {
      minPos[i] = {m, n};
      maxPos[i] = {-1, -1};
    }

    int numSnake = 0;
    for (int i = 0; i < m; i++)
    {
      cin >> a[i];
      for (int j = 0; j < n; j++)
        if (a[i][j] != '.')
        {
          int snake = a[i][j] - 'a';
          numSnake = max(numSnake, snake + 1);
          minPos[snake] = min(minPos[snake], {i, j});
          maxPos[snake] = max(maxPos[snake], {i, j});
        }
    }

    vector <Snake> snakes;
    int hasAns = 1;
    for (int snake = numSnake - 1; snake >= 0; snake--)
    {
      int x = minPos[snake].first, y = minPos[snake].second;
      int xx = maxPos[snake].first, yy = maxPos[snake].second;
      if (x == m) snakes.push_back(snakes[0]);
      else if (x == xx)
      {
        for (int i = y; i <= yy; i++)
          if (a[x][i] != 'a' + snake && flag[x][i] != iTest)
          {
            hasAns = 0;
            break;
          }
          else flag[x][i] = iTest;
        snakes.push_back({x, y, xx, yy});
      }
      else if (y == yy)
      {
        for (int i = x; i <= xx; i++)
          if (a[i][y] != 'a' + snake && flag[i][y] != iTest)
          {
            hasAns = 0;
            break;
          }
          else flag[i][y] = iTest;
        snakes.push_back({x, y, xx, yy});
      }
      else
      {
        hasAns = 0;
        break;
      }
    }

    if (hasAns)
    {
      reverse(snakes.begin(), snakes.end());
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          if (a[i][j] != '.')
          {
            int id = a[i][j] - 'a';
            if (snakes[id].x == snakes[id].xx) hasAns &= i == snakes[id].x;
            else hasAns &= j == snakes[id].y;
          }
    }

    if (!hasAns) cout << "NO\n";
    else
    {
      cout << "YES\n" << numSnake << '\n';
      for (auto snake : snakes)
        cout << snake.x + 1 << ' ' << snake.y + 1 << ' ' << snake.xx + 1 << ' ' << snake.yy + 1 << '\n';
    }
  }
}