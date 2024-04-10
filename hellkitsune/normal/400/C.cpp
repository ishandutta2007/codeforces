#include <iostream>

using namespace std;

int main()
{
  int n, m, x, y, z, p;
  cin >> n >> m >> x >> y >> z >> p;
  bool xx = false, yy = false, s = false;
  if (y % 2 == 1) {
    if (x % 2 == 0)
      yy ^= 1;
    else
      xx ^= 1;
  }
  x = (x - z + 1000000000) % 4;
  switch (x) {
    case 0: {break;}
    case 1: {xx ^= 1; s ^= 1; break;}
    case 2: {xx ^= 1; yy ^= 1; break;}
    case 3: {yy ^= 1; s ^= 1; break;}
  }
  for (int i = 0; i < p; ++i) {
    cin >> x >> y;
    if (xx)
      x = n - x + 1;
    if (yy)
      y = m - y + 1;
    if (s) {
      x ^= y;
      y ^= x;
      x ^= y;
    }
    cout << x << ' ' << y << endl;
  }
  return 0;
}