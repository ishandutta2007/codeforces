#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int R = 20;
const int C = 360;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<vector<int>> cWalls(R, vector<int>(C));
    vector<vector<int>> sWalls(R, vector<int>(C));
    while (n--)
    {
      char t;
      cin >> t;
      if (t == 'C')
      {
        int r, x, y;
        cin >> r >> x >> y;
        r--;
        if (x < y)
        {
          for (int i = x; i < y; i++)
            cWalls[r][i] = 1;
        }
        else
        {
          for (int i = 0; i < y; i++)
            cWalls[r][i] = 1;
          for (int i = x; i < C; i++)
            cWalls[r][i] = 1;
        }
      }
      else
      {
        int r1, r2, x;
        cin >> r1 >> r2 >> x;
        r1--; r2--;
        for (int i = r1; i < r2; i++)
          sWalls[i][x] = 1;
      }
    }

    vector<vector<int>> a(R * C * 2);
    vector<int> flag(R * C * 2);
    queue<int> q;
    for (int i = 0; i < C; i++)
      if (!cWalls[0][i])
      {
        q.push(i);
        flag[i] = 1;
      }

    int ans = 0;
    while (!empty(q))
    {
      int x = q.front();
      q.pop();
      if (x < R * C)
      {
        int i = x / C, j = x % C;
        if (i == R - 1)
        {
          ans = 1;
          break;
        }

        for (int ii : {i - 1, i})
          if (ii >= 0)
            for (int jj : {j, j + 1})
            {
              jj %= C;
              int y = ii * C + jj + R * C;
              if (!sWalls[ii][jj] && !flag[y])
              {
                q.push(y);
                flag[y] = 1;
              }
            }

        for (int ii : {i - 1, i + 1})
          if (ii >= 0)
          {
            int y = ii * C + j;
            if (!cWalls[ii][j] && !flag[y])
            {
              q.push(y);
              flag[y] = 1;
            }
          }
      }
      else
      {
        int i = x / C - R, j = x % C;
        for (int ii : {i, i + 1})
          for (int jj : {j - 1, j})
          {
            jj = (jj + C) % C;
            int y = ii * C + jj;
            if (!cWalls[ii][jj] && !flag[y])
            {
              q.push(y);
              flag[y] = 1;
            }
          }

        for (int jj : {j - 1, j + 1})
        {
          jj = (jj + C) % C;
          int y = i * C + jj + R * C;
          if (!sWalls[i][jj] && !flag[y])
          {
            q.push(y);
            flag[y] = 1;
          }
        }
      }
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}