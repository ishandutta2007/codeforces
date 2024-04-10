#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(4, vector<int>(n, -1));
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      a[i][j]--;
    }

  vector<pair<int, int>> order;
  for (int i = 0; i < n; i++)
    order.push_back({1, i});
  for (int i = n - 1; i >= 0; i--)
    order.push_back({2, i});

  int parked = 0;
  vector<tuple<int, int, int>> ans;
  while (1)
  {
    int x = -1, y = -1;
    for (int i = 1; i < 3; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] < 0)
        {
          x = i;
          y = j;
        }
        else if (a[i ^ 1][j] == a[i][j])
        {
          ans.push_back({a[i][j], i ^ 1, j});
          a[i][j] = -1;
          x = i;
          y = j;
          parked++;
        }

    if (parked == k)
      break;

    if (x < 0)
    {
      cout << -1 << endl;
      return 0;
    }

    int id = find(begin(order), end(order), make_pair(x, y)) - begin(order);
    for (int i = 1; i < n * 2; i++)
    {
      int nextId = (id + 1) % (n * 2);
      auto [xx, yy] = order[nextId];
      if (a[xx][yy] >= 0)
      {
        ans.push_back({a[xx][yy], x, y});
        swap(a[xx][yy], a[x][y]);
      }
      x = xx;
      y = yy;
      id = nextId;
    }
  }

  cout << size(ans) << '\n';
  for (auto [i, x, y] : ans)
    cout << i + 1 << ' ' << x + 1 << ' ' << y + 1 << '\n';
}