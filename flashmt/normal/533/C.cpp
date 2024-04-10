#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, y, xx, yy;
  cin >> x >> y >> xx >> yy;
  if ((x <= xx && y <= yy) || x + y <= max(xx, yy)) cout << "Polycarp\n";
  else cout << "Vasiliy\n";
}