#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[200200], k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n, greater<int>());

  long long low = a[n / 2], high = 1LL << 60, ans = low;
  while (low <= high)
  {
    long long mid = (low + high) / 2, need = 0;
    for (int i = 0; i <= n / 2; i++)
    {
      need += max(0LL, mid - a[i]);
      if (need > k)
        break;
    }
    if (need <= k)
    {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }

  cout << ans << endl;
}