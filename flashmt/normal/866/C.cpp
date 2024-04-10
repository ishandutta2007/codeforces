#include <bits/stdc++.h>
using namespace std;
const double oo = 1e18;

int n, t, slow[55], fast[55];
double f[55][5555], prob[55];

double calc(double value)
{
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 5100; j++)
      f[i][j] = oo;
  
  for (int j = 0; j <= t; j++)
    f[n][j] = 0;

  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j <= t; j++)
    {
      f[i][j] = prob[i] * (f[i + 1][j + fast[i]] + fast[i]);
      f[i][j] += (1 - prob[i]) * min(f[i + 1][j + slow[i]] + slow[i], value + slow[i]);
    }

  return f[0][0];
}

int main()
{
  cin >> n >> t;
  for (int i = 0; i < n; i++)
  {
    cin >> fast[i] >> slow[i] >> prob[i];
    prob[i] /= 100;
  }

  double low = 0, high = 1e9;
  for (int turn = 0; turn < 1000; turn++)
  {
    double mid1 = (low * 2 + high) / 3, v1 = calc(mid1);
    double mid2 = (low + high * 2) / 3, v2 = calc(mid2);
    if (fabs(v1 - mid1) < fabs(v2 - mid2)) high = mid2;
    else low = mid1;
  }

  cout << fixed << setprecision(12) << low << endl;
}