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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> cnt;
    for (int &x : a)
    {
      cin >> x;
      cnt[x]++;
    }

    vector<int> sum(n + 1);
    sum[0] = 1 - cnt.count(0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + 1 - cnt.count(i);

    vector<pair<int, int>> sortByCnt;
    for (auto [k, v] : cnt)
      sortByCnt.push_back({v, k});
    sort(begin(sortByCnt), end(sortByCnt));

    sort(begin(a), end(a));
    int initialDiff = size(cnt);
    int initialMex = 0;
    while (cnt.count(initialMex))
      initialMex++;
    int ans = initialDiff - initialMex;

    auto calc = [&](int goal)
    {
      if (sum[goal] > k)
        return -1;

      int budget = sum[goal];
      int bestDiff = initialDiff + budget;
      for (auto [curCnt, curVal] : sortByCnt)
        if (curVal > goal)
        {
          int use = min(curCnt, budget);
          budget -= use;
          curCnt -= use;
          if (!curCnt)
            bestDiff--;
          if (!budget)
            break;
        }

      return bestDiff - goal - 1;
    };

    int low = 0, high = n - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      int cur = calc(mid);
      if (cur < 0) high = mid - 1;
      else
      {
        ans = min(ans, cur);
        low = mid + 1;
      }
    }

    cout << ans << '\n';
  }
}