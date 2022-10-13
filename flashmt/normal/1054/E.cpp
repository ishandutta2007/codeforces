#include <bits/stdc++.h>
using namespace std;

int m, n, cnt[333][333][2];
deque<int> a[333][333];
vector<vector<int>> ans;

void move(int x, int y, int xx, int yy)
{
  int c = a[x][y].back();
  a[x][y].pop_back();
  cnt[x][y][c]--;
  a[xx][yy].push_front(c);
  cnt[xx][yy][c]++;
  ans.push_back({x + 1, y + 1, xx + 1, yy + 1});
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string target[333][333];
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      string s;
      cin >> s;
      for (char c : s)
      {
        a[i][j].push_back(c - '0');
        cnt[i][j][c - '0']++;
      }
    }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> target[i][j];
      reverse(target[i][j].begin(), target[i][j].end());
    }

  // make (0, 0) empty
  while (!a[0][0].empty())
    if (a[0][0].back()) move(0, 0, 0, n - 1);
    else move(0, 0, m - 1, 0);

  // make (i, 0) and (0, j) empty
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if ((i > 0) ^ (j > 0))
        while (!a[i][j].empty())
        {
          if (i == m - 1 && !cnt[i][j][1])
            break;
          if (j == n - 1 && !cnt[i][j][0])
            break;
          move(i, j, 0, 0);
          if (a[0][0].back()) move(0, 0, 0, n - 1);
          else move(0, 0, m - 1, 0);
        }

  // make (i, j) empty
  for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++)
      while (!a[i][j].empty())
        if (a[i][j].back())
        {
          move(i, j, 0, j);
          if (j < n - 1)
            move(0, j, 0, n - 1);
        }
        else
        {
          move(i, j, i, 0);
          if (i < m - 1)
            move(i, 0, m - 1, 0);
        }

  // distribute to all but (i, j)
  for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++)
      for (char c : target[i][j])
        if (c == '0')
        {
          if (i < m - 1)
            move(m - 1, 0, i, 0);
          move(i, 0, i, j);
        }
        else
        {
          if (j < n - 1)
            move(0, n - 1, 0, j);
          move(0, j, i, j);
        }

  // distribute to (i, 0) and (0, j)
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if ((i > 0) ^ (j > 0))
      {
        for (char c : target[i][j])
          if (c == '0')
          {
            if (i == m - 1)
            {
              move(m - 1, 0, 0, 0);
              move(0, 0, m - 1, 0);
            }
            else
            {
              move(m - 1, 0, i, 0);
              if (j)
                move(i, 0, i, j);
            }
          }
          else
          {
            if (j == n - 1)
            {
              move(0, n - 1, 0, 0);
              move(0, 0, 0, n - 1);
            }
            else
            {
              move(0, n - 1, 0, j);
              if (i)
                move(0, j, i, j);
            }
          }
      }

  // distribute to (0, 0)
  for (char c : target[0][0])
    if (c == '0') move(m - 1, 0, 0, 0);
    else move(0, n - 1, 0, 0);

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      for (char c : target[i][j])
      {
        assert(!a[i][j].empty());
        assert(c - '0' == a[i][j].back());
        a[i][j].pop_back();
      }

  cout << ans.size() << '\n';
  for (auto m : ans)
  {
    for (auto i : m)
      cout << i << ' ';
    cout << '\n';
  }
}