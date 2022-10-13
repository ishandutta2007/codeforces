#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const long long oo = 1LL << 60;

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
    vector<pair<long long, long long>> a;
    vector<tuple<long long, int, int>> events;
    for (int i = 0; i < n; i++)
    {
      int x, p;
      cin >> x >> p;
      a.push_back({x, p});
      events.push_back({x - p, -1, i});
      events.push_back({x, 0, i});
      events.push_back({x, 1, i});
      events.push_back({x + 1, -2, i});
      events.push_back({x + p, 2, i});
    }

    sort(begin(events), end(events));
    long long numL = 0, numR = 0, sumL = 0, sumR = 0;
    vector<pair<long long, long long>> bad;
    for (auto [_, t, id] : events)
    {
      auto [x, p] = a[id];
      if (t == -1)
      {
        numL++;
        sumL += x - p;
      }
      else if (t == 1)
      {
        numL--;
        sumL -= x - p;
      }
      else if (t == -2)
      {
        numR++;
        sumR += x + p;
      }
      else if (t == 2)
      {
        numR--;
        sumR -= x + p;
      }
      else
      {
        long long rain = numL * x - sumL + sumR - numR * x;
        if (rain > m)
          bad.push_back({x, rain - m});
      }
    }

    string ans(n, '1');
    if (empty(bad))
    {
      cout << ans << '\n';
      continue;
    }

    int numBad = size(bad);
    vector<long long> prefix(numBad, -oo), suffix(numBad, -oo);
    for (int i = 0; i < numBad; i++)
    {
      prefix[i] = bad[i].second - bad[i].first;
      if (i)
        prefix[i] = max(prefix[i], prefix[i - 1]);
    }
    for (int i = numBad - 1; i >= 0; i--)
    {
      suffix[i] = bad[i].second + bad[i].first;
      if (i + 1 < numBad)
        suffix[i] = max(suffix[i], suffix[i + 1]);
    }

    int curId = 0; // first bad position that is greater than current x
    for (auto [_, t, id] : events)
      if (!t)
      {
        auto [x, p] = a[id];
        while (curId < numBad && bad[curId].first <= x)
          curId++;

        if (curId && p - x < prefix[curId - 1])
          ans[id] = '0';

        if (curId < numBad && p + x < suffix[curId])
          ans[id] = '0';
      }

    cout << ans << '\n';
  }
}