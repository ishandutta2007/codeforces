#include <bits/stdc++.h>
using namespace std;

long long sum(int from, int to)
{
  from = max(from, 0);
  return (from + to) * (to - from + 1LL) / 2;
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  m -= n;
  k--;
  int low = 0, high = m, ans = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    long long need = sum(mid - k, mid) + sum(mid - n + 1 + k, mid) - mid;
    if (need <= m)
    {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }
  cout << ans + 1 << endl;
}