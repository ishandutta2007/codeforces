#include <iostream>
#include <cmath>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long double ld;

const ld pi = atan2(0, -1);
const ld eps = 1e-4;

ld ang(ld x1, ld y1, ld x2, ld y2) {
  ld sca = x1 * x2 + y1 * y2;
  ld cro = x1 * y2 - y1 * x2;
  return abs(atan2(cro, sca));
}

int main() {
  ld x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  ld a = ang(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
  ld b = ang(x3 - x2, y3 - y2, x1 - x2, y1 - y2);
  ld c = ang(x2 - x3, y2 - y3, x1 - x3, y1 - y3);
  for (int i = 3; i <= 100; i++) {
    ld x = pi / i;
    ld cnta = a / x;
    ld cntb = b / x;
    ld cntc = c / x;
    if (floor(cnta + eps) != ceil(cnta - eps))
      continue;
    if (floor(cntb + eps) != ceil(cntb - eps))
      continue;
    if (floor(cntc + eps) != ceil(cntc - eps))
      continue;
    ld r = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3)) / (2 * sin(a));
    cout << fsp(10) << i * r * r * sin(2 * x) * 1 / 2 << endl;
    return 0;
  }
  return 0;
}