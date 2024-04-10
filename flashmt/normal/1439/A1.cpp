#include <bits/stdc++.h>
using namespace std;

int m, n;
string a[111];
vector<pair<int, int>> ans;

void toggle(pair<int, int> b)
{
  if (a[b.first][b.second] == '0') a[b.first][b.second] = '1';
  else a[b.first][b.second] = '0';
}

void move(pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
  ans.push_back(b);
  toggle(b);
  ans.push_back(c);
  toggle(c);
  ans.push_back(d);
  toggle(d);
}

void checkSquare(int x, int y)
{
  assert(x < m - 1);
  assert(y < n - 1);

  vector<pair<int, int>> same, diff;
  for (int i = x; i <= x + 1; i++)
    for (int j = y; j <= y + 1; j++)
      if (a[i][j] == '0') same.push_back({i, j});
      else diff.push_back({i, j});

  if (diff.size() == 1)
  {
    move(diff[0], same[0], same[1]);
    move(diff[0], same[0], same[2]);
    move(diff[0], same[1], same[2]);
  }

  if (diff.size() == 2)
  {
    move(diff[0], same[0], same[1]);
    move(diff[1], same[0], same[1]);
  }

  if (diff.size() == 3)
    move(diff[0], diff[1], diff[2]);

  if (diff.size() == 4)
  {
    move(diff[0], diff[1], diff[2]);
    move(diff[0], diff[1], diff[3]);
    move(diff[0], diff[2], diff[3]);
    move(diff[1], diff[2], diff[3]);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> m >> n;
    for (int i = 0; i < m; i++)
      cin >> a[i];

    ans.clear();
    if (m % 2)
    {
      for (int j = 0; j < n; j++)
        if (a[m - 1][j] == '1')
        {
          int jj = (j + 1 < n ? j + 1 : j - 1);
          move({m - 1, j}, {m - 2, j}, {m - 2, jj});
        }
      m--;
    }

    if (n % 2)
    {
      for (int i = 0; i < m; i++)
        if (a[i][n - 1] == '1')
        {
          int ii = (i + 1 < m ? i + 1 : i - 1);
          move({i, n - 1}, {i, n - 2}, {ii, n - 2});
        }
      n--;
    }

    for (int i = 0; i < m; i += 2)
      for (int j = 0; j < n; j += 2)
        checkSquare(i, j);

    cout << ans.size() / 3 << '\n';
    for (int i = 0; i < ans.size(); i += 3)
    {
      for (int j = 0; j < 3; j++)
        cout << ans[i + j].first + 1 << ' ' << ans[i + j].second + 1 << ' ';
      cout << '\n';
    }
  }
}