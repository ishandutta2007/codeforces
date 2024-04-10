#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int oo = 27081993;
const int A = 1e5;
const int K = 100;

int solveSmallK(vector<int> &a, int n, int k)
{
  int high = a[n - 1] / k, low = high;
  vector<pair<int, int>> options;
  for (int i = n - 2, kk = k; i >= 0; i--)
  {
    while (kk > 1 && a[i] / (kk - 1) <= high)
      kk--;
    int x = a[i] / kk;
    if (kk > 1 && a[i] / (kk - 1) > high)
    {
      int y = a[i] / (kk - 1);
      options.push_back({x, y});
    }
    else low = min(low, x);
  }

  int sz = 0;
  for (int i = 0; i < size(options); i++)
    if (options[i].first < low)
      options[sz++] = options[i];

  if (!sz)
    return high - low;

  options.resize(sz);
  sort(begin(options), end(options));

  int res = oo;
  for (auto [x, y] : options)
  {
    res = min(res, high - x);
    high = max(high, y);
  }

  return res;
}

int solveMax(vector<int> &a, int n, int k, int maxVal)
{
  int minVal = maxVal;
  for (int x : a)
  {
    if (x / k > maxVal)
      return oo;
    int q = max(x / maxVal, 1);
    if (x / q > maxVal)
      q++;
    minVal = min(minVal, x / q);
  }
  return maxVal - minVal;
}

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
    for (int &x : a)
      cin >> x;

    int ans = oo;
    for (int i = 1; i <= A / K; i++)
      ans = min(ans, solveMax(a, n, k, i));
    for (int i = 1; i <= min(k, K); i++)
      ans = min(ans, solveSmallK(a, n, i));
    cout << ans << endl;
  }
}