#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int g = __gcd(x, y);
  x /= g;
  y /= g;
  int r = min(a / x, b / y);
  cout << x * r << ' ' << y * r << endl;
}