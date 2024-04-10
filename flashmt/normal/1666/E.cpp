#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 1 << 30;

vector<int> solve(vector<int> &a, int l, int minSeg, int maxSeg)
{
  int n = size(a);
  vector<int> low(n + 1), high(n + 1);
  for (int i = 0; i < n; i++)
  {
    int cur = a[i], next = i == n - 1 ? l : a[i + 1];
    low[i + 1] = max(low[i] + minSeg, cur);
    high[i + 1] = min(high[i] + maxSeg, next);
    if (low[i + 1] > next || high[i + 1] < cur)
      return {};
  }
  if (high[n] < l)
    return {};

  vector<int> res(n + 1);
  res[n] = l;
  for (int i = n - 1; i >= 0; i--)
    res[i] = max(low[i], res[i + 1] - maxSeg);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, l;
  cin >> l >> n;
  vector<int> a(n);
  for (int &x: a)
    cin >> x;

  int low = 1, high = oo, maxSeg = oo;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (empty(solve(a, l, 1, mid))) low = mid + 1;
    else
    {
      maxSeg = mid;
      high = mid - 1;
    }
  }

  int minSeg = 0;
  low = 1, high = oo;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (empty(solve(a, l, mid, oo))) high = mid - 1;
    else
    {
      minSeg = mid;
      low = mid + 1;
    }
  }

  auto ans = solve(a, l, minSeg, maxSeg);
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ' << ans[i + 1] << '\n';
}