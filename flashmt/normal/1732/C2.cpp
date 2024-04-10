#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int LG = 30;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<vector<int>> id(LG);
    vector<long long> s(n + 1), sx(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      s[i] = s[i - 1] + a[i];
      sx[i] = sx[i - 1] ^ a[i];
      for (int j = 0; j < LG; j++)
        if (a[i] >> j & 1)
          id[j].push_back(i);
    }

    while (q--)
    {
      int l, r;
      cin >> l >> r;
      long long ans = 0;
      int bestL = l - 1, bestR = l;
      vector<int> lCand, rCand;
      for (int i = 0; i < LG; i++)
      {
        int u = lower_bound(begin(id[i]), end(id[i]), l) - begin(id[i]);
        int v = upper_bound(begin(id[i]), end(id[i]), r) - begin(id[i]);
        if (u < v)
        {
          for (int j : {u, u + 1})
            if (j < size(id[i]) && id[i][j] <= r)
              lCand.push_back(id[i][j] - 1);
          for (int j : {v - 2, v - 1})
            if (j >= 0 && id[i][j] >= l)
              rCand.push_back(id[i][j]);
        }
      }

      for (int i : lCand)
        for (int j : rCand)
          if (i < j)
          {
            long long cur = s[j] - s[i] - (sx[j] ^ sx[i]);
            if (cur > ans || (cur == ans && j - i < bestR - bestL))
            {
              ans = cur;
              bestL = i;
              bestR = j;
            }
          }

      cout << bestL + 1 << ' ' << bestR << '\n';
    }
  }
}