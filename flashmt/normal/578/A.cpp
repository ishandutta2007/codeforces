#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  if (b > a) cout << -1 << endl;  
  else
  {
    int c = a / b;
    double ans = 1e18;
    if (a == b) ans = a;
    for (int i = max(2, c - 1000); i <= c + 1000; i++)
    {
      double x = -1;
      if (i % 2) x = (a - b) / (i - 1.);
      else x = 1. * (a + b) / i;
      if (x >= b) ans = min(ans, x);
    }

    if (ans > 1e10) ans = -1;
    cout << fixed << setprecision(9) << ans << endl;
  }
}