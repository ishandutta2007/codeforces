#include <bits/stdc++.h>
using namespace std;

int ans[1000100];

long long getMinK(int from, int to)
{
  if (from > to)
    return 0;
  return (to - from + 1LL) * (to + from) / 2;
}

long long getMaxK(int from, int to)
{
  if (from > to)
    return 0;
  int len = to - from + 1, mid = (to + from + 1) / 2;
  long long res = (mid + to) * (to - mid + 1LL);
  return len % 2 ? res - mid : res;
}

void solve(int l, int r, long long k)
{
  if (k == getMinK(l, r))
  {
    for (int i = l; i <= r; i++)
      ans[i] = i;
    return;
  }

  if (k >= getMaxK(l, r))
  {
    for (int i = l, j = r; i <= r; i++, j--)
      ans[i] = j;
    return;
  }

  if (getMinK(l + 1, r - 1) <= k - r * 2 && k - r * 2 <= getMaxK(l + 1, r - 1))
  {
    ans[l] = r;
    ans[r] = l;
    solve(l + 1, r - 1, k - r * 2);
    return;
  }

  if (getMinK(l + 1, r) <= k - l && k - l <= getMaxK(l + 1, r))
  {
    ans[l] = l;
    solve(l + 1, r, k - l);
    return;
  }

  if (getMinK(l, r - 1) <= k - r && k - r <= getMaxK(l, r - 1))
  {
    ans[r] = r;
    solve(l, r - 1, k - r);
    return;
  }

  assert(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long k;

  cin >> n >> k;
  if (k < getMinK(1, n))
  {
    cout << -1 << endl;
    return 0;
  }

  solve(1, n, k);

  long long s = 0;
  for (int i = 1; i <= n; i++)
    s += max(i, ans[i]);
  assert(s <= k);
  cout << s << endl;
  for (int i = 1; i <= n; i++)
    cout << i << " \n"[i == n];
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
}