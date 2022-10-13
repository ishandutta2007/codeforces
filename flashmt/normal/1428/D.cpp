#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, a[100100], c[100100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> sz[3];
  vector<pair<int, int>> ans;
  for (int i = n - 1, row = n - 1; i >= 0; i--)
    if (a[i] == 1)
    {
      ans.push_back({row, i});
      c[i] = row--;
      sz[1].push_back(i);
    }
    else if (a[i] == 2)
    {
      if (sz[1].empty())
      {
        cout << -1 << endl;
        return 0;
      }
      c[i] = c[sz[1].back()];
      ans.push_back({c[i], i});
      sz[1].pop_back();
      sz[2].push_back(i);
    }
    else if (a[i] == 3)
    {
      int found = 0;
      for (int j = 2; j >= 1; j--)
        if (!sz[j].empty())
        {
          ans.push_back({row, i});
          ans.push_back({row--, sz[j].back()});
          sz[j].pop_back();
          sz[2].push_back(i);
          found = 1;
          break;
        }

      if (!found)
      {
        cout << -1 << endl;
        return 0;
      }
    }

  cout << ans.size() << '\n';
  for (auto [x, y] : ans)
    cout << x + 1 << ' ' << y + 1 << '\n';
}