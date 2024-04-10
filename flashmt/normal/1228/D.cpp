#include <bits/stdc++.h>
using namespace std;

set<int> a[100100];

void check(vector<int> &group0, vector<int> &group1)
{
  for (int x : group0)
    for (int y : group1)
      if (!a[x].count(y))
      {
        cout << -1 << endl;
        exit(0);
      }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x].insert(--y);
    a[y].insert(x);
  }

  vector<int> ans(n, -1), groups[3];
  for (int c = 0; c < 3; c++)
  {
    int found = 0;
    for (int x = 0; x < n; x++)
      if (ans[x] < 0)
      {
        ans[x] = c;
        groups[c].push_back(x);
        for (int y = 0; y < n; y++)
          if (!a[x].count(y))
          {
            if (ans[y] < 0)
            {
              ans[y] = c;
              groups[c].push_back(y);
            }
            else if (ans[y] != c)
            {
              cout << -1 << endl;
              return 0;
            }
          }
        found = 1;
        break;
      }

    if (!found)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 0; i < n; i++)
    if (ans[i] < 0)
    {
      cout << -1 << endl;
      return 0;
    }

  for (int i = 0; i < 3; i++)
    for (int x : groups[i])
      if (a[x].size() != n - groups[i].size())
      {
        cout << -1 << endl;
        return 0;
      }

  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++)
      check(groups[i], groups[j]);

  for (int i = 0; i < n; i++)
    cout << ans[i] + 1 << " \n"[i == n - 1];
}