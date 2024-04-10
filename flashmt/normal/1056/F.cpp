#include <bits/stdc++.h>
using namespace std;
const double oo = 1e18;

int n, a[101], p[101];
double c, t, f[101][1010], pw[101];

double optimize(double t, double c)
{
  double low = 0, high = t;
  for (int i = 0; i < 1000; i++)
  {
    double mid1 = (low * 2 + high) / 3, v1 = (t - mid1) * (1 + c * mid1);
    double mid2 = (low + high * 2) / 3, v2 = (t - mid2) * (1 + c * mid2);
    if (v1 < v2) low = mid1;
    else high = mid2;
  }
  return (t - low) * (1 + c * low);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  pw[0] = 1;
  for (int i = 1; i <= 100; i++)
    pw[i] = pw[i - 1] * .9;

  int test;
  cin >> test;
  while (test--)
  {
    cin >> n >> c >> t;
    for (int i = 0; i < n; i++)
      cin >> a[i] >> p[i];

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[j] > a[i] || (a[j] == a[i] && p[j] > p[i]))
        {
          swap(a[i], a[j]);
          swap(p[i], p[j]);
        }

    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n * 10; k++)
        f[j][k] = oo;
    f[0][0] = 0;

    for (int i = 0; i < n; i++)
      for (int j = i; j >= 0; j--)
        for (int k = i * 10; k >= 0; k--)
          f[j + 1][k + p[i]] = min(f[j + 1][k + p[i]], f[j][k] + a[i] / pw[j + 1]);

    int ans = 0;
    for (int j = 1; j <= n && j * 10 < t; j++)
    {
      double tt = optimize(t - j * 10, c);
      for (int k = ans + 1; k <= n * 10; k++)
        if (f[j][k] <= tt)
          ans = k;
    }
    cout << ans << endl;
  }
}