#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100100];
  long long s[100100] = {0}, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];

  int low = 0, high = 1e9, ans = high;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    long long minCost = k + 1;
    for (int i = 1, j = 1; i <= n; i++)
    {
      while (j <= n && a[j] - a[i] <= mid)
        j++;
      long long cost = (i - 1LL) * a[i] - s[i - 1];
      cost += s[n] - s[j - 1] - (n - j + 1LL) * (a[i] + mid);
      minCost = min(minCost, cost);
    }
    for (int i = n, j = n; i; i--)
    {
      while (j && a[i] - a[j] <= mid)
        j--;
      long long cost = s[n] - s[i] - 1LL * (n - i) * a[i];
      cost += 1LL * j * (a[i] - mid) - s[j];
      minCost = min(minCost, cost);
    }

    if (minCost <= k)
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << ans << endl;
}