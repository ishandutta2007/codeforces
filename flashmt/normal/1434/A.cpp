#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a[6], b[100100], n;
  for (int i = 0; i < 6; i++)
    cin >> a[i];
  sort(a, a + 6);
  for (int i = 1; i < 6; i++)
    a[i] -= a[0];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    b[i] -= a[0];
  }
  sort(b, b + n);
  a[0] = 0;

  int ans = oo;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 6; j++)
    {
      int smallest = b[i] - a[j];
      if (b[0] < smallest)
        continue;

      int maxDiff = 0;
      for (int k = 1; k < 6; k++)
      {
        int ii = lower_bound(b, b + n, smallest + a[k]) - b;
        if (ii)
          maxDiff = max(maxDiff, b[ii - 1] - a[k - 1] - smallest);
        if (ii == n)
          break;
      }

      if (b[n - 1] - a[5] >= smallest)
        maxDiff = max(maxDiff, b[n - 1] - a[5] - smallest);

      ans = min(ans, maxDiff);
    }

  cout << ans << endl;
}