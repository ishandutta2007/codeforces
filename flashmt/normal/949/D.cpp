#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d, b;
  cin >> n >> d >> b;
  vector<int> a(n + 1), sum(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  auto isGood = [&](int bad)
  {
    if (bad * 2 >= n)
      return 1;

    for (int i = bad + 1, j = 1, cur = 0; i <= n - bad; i++)
      if (i <= (n + 1) / 2)
      {
        while (j <= i)
          cur += a[j++];
        while (cur < b && j <= n && j - i <= 1LL * i * d)
          cur += a[j++];
        if (cur < b)
          return 0;
        cur -= b;
      }
      else
      {
        int bound = max(1LL, i - (n + 1LL - i) * d);
        cur = min(cur, sum[j - 1] - sum[bound - 1]);
        while (cur < b && j <= n)
          cur += a[j++];
        if (cur < b)
          return 0;
        cur -= b;
      }

    return 1;
  };

  int low = 0, high = n / 2, ans = n / 2 + 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (isGood(mid))
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << ans << endl;
}