#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, n, m, x, y;
  vector<pair<int, int>> a[300300];
  cin >> test;
  while (test--)
  {
    cin >> n >> m;
    for (int i = 1; i <= n * 3; i++)
      a[i].clear();
    for (int i = 1; i <= m; i++)
    {
      cin >> x >> y;
      a[x].push_back({y, i});
      a[y].push_back({x, i});
    }

    vector<int> done(n * 3, 0), independentSet, matches;
    for (int i = 1; i <= n * 3; i++)
      if (!done[i])
      {
        int found = 0;
        done[i] = 1;
        for (auto u : a[i])
          if (!done[u.first])
          {
            found = 1;
            matches.push_back(u.second);
            done[u.first] = 1;
            break;
          }

        if (!found)
          independentSet.push_back(i);
      }

    if (matches.size() >= n)
    {
      cout << "Matching\n";
      for (int i = 0; i < n; i++)
        cout << matches[i] << " \n"[i == n - 1];
    }
    else
    {
      assert(independentSet.size() >= n);
      cout << "IndSet\n";
      for (int i = 0; i < n; i++)
        cout << independentSet[i] << " \n"[i == n - 1];
    }
  }
}