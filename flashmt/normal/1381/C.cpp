#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, x, y;
    cin >> n >> x >> y;
    y -= x;
    vector<vector<int>> id(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      id[--a[i]].push_back(i);
    }

    set<pair<int, int>> cnt;
    int free = -1;
    for (int i = 0; i <= n; i++)
      if (!empty(id[i])) cnt.insert({size(id[i]), i});
      else free = i;

    vector<int> ans(n, free);
    for (int i = 0; i < x; i++)
    {
      int u = rbegin(cnt)->second;
      cnt.erase(*rbegin(cnt));
      ans[id[u].back()] = u;
      id[u].pop_back();
      if (!empty(id[u]))
        cnt.insert({size(id[u]), u});
    }

    if (y)
    {
      int rem = n - x, u = rbegin(cnt)->second, maxCnt = size(id[u]);
      if (y > (rem - maxCnt) * 2)
      {
        cout << "NO\n";
        continue;
      }

      vector<int> order, remIds, remValues;
      for (auto [_, u] : cnt)
        for (int i : id[u])
        {
          remIds.push_back(i);
          remValues.push_back(u);
        }
      reverse(begin(remIds), end(remIds));
      reverse(begin(remValues), end(remValues));
      int shift = 0;
      for (int i = 0; i < rem; i++)
        if (a[remIds[i]] != remValues[0])
        {
          shift = i;
          break;
        }
      assert(shift > 0);

      for (int i = 0; i < rem && y > 0; i++)
      {
        int curId = remIds[(i + shift) % rem];
        if (a[curId] != remValues[i])
        {
          ans[curId] = remValues[i];
          y--;
        }
      }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
      cout << ans[i] + 1 << " \n"[i == n - 1];
  }
}