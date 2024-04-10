#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int A = 400400;

int main()
{
  vector<vector<int>> d(A);
  for (int i = 1; i < A; i++)
  {
    for (int j = 1; j * j <= i; j++)
      if (i % j == 0)
        d[i].push_back(j);
    for (int j = size(d[i]) - 1; j >= 0; j--)
    {
      int x = d[i][j];
      if (x * x < i)
        d[i].push_back(i / x);
    }
  }

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int l, r;
    cin >> l >> r;
    long long ans = 0;
    for (int k = l; k <= r; k++)
    {
      int goodId = lower_bound(begin(d[k]), end(d[k]), l) - begin(d[k]);
      int good = int(size(d[k])) - 1 - goodId;
      if (good >= 2)
        ans += (good - 1LL) * good / 2;

      int low = lower_bound(begin(d[k * 2]), end(d[k * 2]), l) - begin(d[k * 2]);
      int high = size(d[k * 2]) - 2;
      for (int i = low, j = high - 1; i < high; i++)
      {
        while (j >= low && d[k * 2][i] + d[k * 2][j] > k)
          j--;
        ans += high - max(i, j) - 1;
      }
    }

    ans = (r - l + 1LL) * (r - l) * (r - l - 1) / 6 - ans;
    cout << ans << endl;
  }
}