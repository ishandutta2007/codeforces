#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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
    vector<long long> sumPrefix(n);
    for (int i = 0; i < n; i++)
    {
      long long prefix = 0;
      for (int j = 0; j < m; j++)
      {
        long long x;
        cin >> x;
        prefix += x;
        sumPrefix[i] += prefix;
      }
    }
    int ans = min_element(begin(sumPrefix), end(sumPrefix)) - begin(sumPrefix);
    long long maxSumPrefix = *max_element(begin(sumPrefix), end(sumPrefix));
    cout << ans + 1 << ' ' << maxSumPrefix - sumPrefix[ans] << '\n';
  }
}