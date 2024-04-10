#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

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
    vector<int> a(n);
    vector<vector<int>> id(n + 2);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      id[a[i]].push_back(i);
    }

    for (int i = 0; i <= n; i++)
      reverse(begin(id[i]), end(id[i]));

    vector<int> ans;
    int cur = 0, last = -1;
    while (!empty(id[cur]))
      cur++;

    while (1)
    {
      if (!cur)
      {
        for (int i = last + 1; i < n; i++)
          ans.push_back(0);
        break;
      }

      ans.push_back(cur);
      int maxId = -1;
      for (int i = 0; i < cur; i++)
        maxId = max(maxId, id[i].back());

      for (int i = last + 1; i <= maxId; i++)
      {
        id[a[i]].pop_back();
        if (empty(id[a[i]]))
          cur = min(cur, a[i]);
      }

      if (maxId == n - 1)
        break;
      last = maxId;
    }

    cout << size(ans) << '\n';
    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
  }
}