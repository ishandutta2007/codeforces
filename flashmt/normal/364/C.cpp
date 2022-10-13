#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int MAX = 15000000;

int main()
{
  int k;
  cin >> k;

  vector<int> p = {2, 3, 5, 7, 11};
  vector<vector<int>> ofMask(1 << 5);
  for (int i = 2; i <= min(MAX, k * k * 2); i++)
  {
    int x = i, mask = 0;
    for (int j = 0; j < size(p); j++)
      if (x % p[j] == 0)
      {
        mask |= 1 << j;
        while (x % p[j] == 0)
          x /= p[j];
      }

    if (x == 1)
      ofMask[mask].push_back(i);
  }

  for (int use = 1; use <= 5; use++)
  {
    vector<int> cnt(use), allMasks;
    for (int mask = 1; mask < 1 << use; mask++)
      allMasks.push_back(mask);
    sort(begin(allMasks), end(allMasks), [](int u, int v) { return __builtin_popcount(u) > __builtin_popcount(v); });
    int rem = k;
    vector<int> ans;
    for (int mask : allMasks)
    {
      int pick = min(rem, int(size(ofMask[mask])));
      rem -= pick;
      for (int i = 0; i < pick; i++)
        ans.push_back(ofMask[mask][i]);
      for (int i = 0; i < use; i++)
        if (mask >> i & 1)
          cnt[i] += pick;
    }

    int isGood = rem <= 0;
    for (int i = 0; i < use; i++)
      if (cnt[i] * 2 < k)
        isGood = 0;

    if (isGood)
    {
      for (int x : ans)
        cout << x << ' ';
      return 0;
    }
  }
}