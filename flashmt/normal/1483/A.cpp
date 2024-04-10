#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, m, k[100100], played[100100];
vector<int> a[100100];
set<int> days[100100];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n >> m;
    int bound = (m + 1) / 2;
    for (int i = 0; i < n; i++)
    {
      days[i].clear();
      played[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
      cin >> k[i];
      a[i].resize(k[i]);
      for (int j = 0; j < k[i]; j++)
      {
        cin >> a[i][j];
        a[i][j]--;
        days[a[i][j]].insert(i);
      }
    }

    set<pair<int ,int>> s;
    for (int i = 0; i < n; i++)
      s.insert({days[i].size(), i});

    vector<int> ans(m, -1);
    while (!s.empty())
    {
      int x = s.begin()->second;
      s.erase(s.begin());
      if (days[x].size() > bound)
        break;

      for (int y : days[x])
      {
        ans[y] = x;
        for (int xx : a[y])
          if (xx != x)
          {
            s.erase({days[xx].size(), xx});
            days[xx].erase(y);
            if (!days[xx].empty())
              s.insert({days[xx].size(), xx});
          }
      }
      days[x].clear();
    }

    int isGood = 1;
    vector<pair<int, int>> sortedDays;
    for (int i = 0; i < m; i++)
      if (ans[i] < 0)
        sortedDays.push_back({k[i], i});
    sort(sortedDays.begin(), sortedDays.end());
    for (auto [_, i] : sortedDays)
      if (ans[i] < 0)
      {
        int x = -1, minPlayed = oo;
        for (int j : a[i])
          if (played[j] < bound && played[j] < minPlayed)
          {
            minPlayed = played[j];
            x = j;
          }

        if (x < 0)
        {
          isGood = 0;
          break;
        }

        played[x]++;
        ans[i] = x;
      }

    for (int x : ans)
      if (x < 0)
        isGood = 0;

    if (!isGood) cout << "NO\n";
    else
    {
      cout << "YES\n";
      for (int x : ans)
        cout << x + 1 << ' ';
      cout << '\n';
    }
  }
}