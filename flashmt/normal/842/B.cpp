#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int r, d, n, x, y, rSausage, ans = 0;
  cin >> r >> d >> n;
  while (n--)
  {
    cin >> x >> y >> rSausage;
    double dist = sqrt(x * x + y * y);
    ans += (r - d <= dist - rSausage && dist + rSausage <= r);
  }
  cout << ans << endl;
}