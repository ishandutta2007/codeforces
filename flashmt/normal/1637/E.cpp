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
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      cnt[x]++;
    }

    unordered_map<int, vector<int>> bad;
    while (m--)
    {
      int x, y;
      cin >> x >> y;
      bad[x].push_back(y);
      bad[y].push_back(x);
    }

    vector<vector<int>> ofCnt(n + 1);
    for (auto [x, cntX] : cnt)
      ofCnt[cntX].push_back(x);

    vector<int> possibleCnt;
    for (int i = 1; i <= n; i++)
      if (!empty(ofCnt[i]))
      {
        possibleCnt.push_back(i);
        sort(rbegin(ofCnt[i]), rend(ofCnt[i]));
      }

    for (auto &u : bad)
      sort(begin(u.second), end(u.second), [&](int x, int y) { return cnt[x] < cnt[y] || (cnt[x] == cnt[y] && x > y); });

    long long ans = 0;
    for (auto [x, cntX] : cnt)
    {
      auto curBad = bad[x];
      int idBad = 0;
      for (int cntY : possibleCnt)
      {
        while (idBad < size(curBad) && cnt[curBad[idBad]] < cntY)
          idBad++;
        for (int y : ofCnt[cntY])
          if (idBad < size(curBad) && curBad[idBad] == y) idBad++;
          else if (y != x)
          {
            ans = max(ans, 1LL * (x + y) * (cntX + cntY));
            break;
          }
      }
    }
    cout << ans << '\n';
  }
}