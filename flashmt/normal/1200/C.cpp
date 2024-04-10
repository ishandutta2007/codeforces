#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long m, n, sx, sy, ex, ey;
  int q;
  cin >> m >> n >> q;
  long long g = __gcd(m, n);
  m /= g;
  n /= g;
  while (q--)
  {
    cin >> sx >> sy >> ex >> ey;
    if (sx == 1) sy = (sy - 1) / m;
    else sy = (sy - 1) / n;
    if (ex == 1) ey = (ey - 1) / m;
    else ey = (ey - 1) / n;
    cout << (sy == ey ? "YES\n" : "NO\n");
  }
}