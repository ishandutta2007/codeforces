#include <bits/stdc++.h>
using namespace std;

int n, p, a[100100], b[100100];

int main()
{
  cin >> n >> p;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];

  double low = 0, high = 1e12;
  for (int turn = 0; turn <= 60; turn++)
  {
    double mid = (low + high) / 2, need = 0;
    for (int i = 0; i < n; i++)
      need += max(0., mid * a[i] - b[i]) / p;
    if (need <= mid) low = mid;
    else high = mid;
  }

  if (low > 1e11) cout << -1 << endl;
  else cout << fixed << setprecision(9) << low << endl;
}