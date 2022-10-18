#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

const long double eps = 0;//1e-14;

bool good(long double a, long double b, long double x, long double y, long double m) {
  x *= -1; y *= - 1;
  if (fabs(x) < eps) {
    if (-m <= a + eps && a <= m + eps) {
      return fabs(y) > eps;   
    }
    return false;
  }
  if (fabs(y) < eps) {
    if (-m <= b + eps && b <= m + eps) {
      return fabs(x) > eps;   
    }
    return false;
  }
  long double la = min((-m - a) / x, (m - a) / x), ra = max((-m - a) / x, (m - a) / x);
  long double lb = min((-m - b) / y, (m - b) / y), rb = max((-m - b) / y, (m - b) / y);
  long double l = max(la, lb), r = min(ra, rb);
  return l <= r + eps;
  // if ((-m - a) * y <= (m - b) * x && (-m - b) * x <= (m - a) * y)
  //   return true;
  // double l = 0, r = 1e+9;
  // for (int it = 0; it < 100; ++it) {
  //   double m1 = l + (r - l) / 3;
  //   double nx = a + x * m1, ny = b + y * m1;
  //   double val1 = nx * nx + ny * ny;
  
  //   double m2 = r - (r - l) / 3;
  //   nx = a + x * m2, ny = b + y * m2;
  //   double val2 = nx * nx + ny * ny;

  //   if (val1 <= val2) r = m2;
  //   else l = m1;

  //   if (val1 <= m + 1e-11 || val2 <= m + 1e-11)
  //     return true;
  // }
  return false;
}

int main() {
  long double a, b, c, d;
  cin >> a >> b >> c >> d;
  // double A = b + d, B = a + c, C = 0;
  // cout << A << "  " << B << endl;
  // double g = sqrt(A * A + B * B); A /= g; B /= g;
  // cout << A << "  " << B << endl;
  // printf("%.10lf\n", fabs(A * a + B * b) + fabs(A * c + B * d));

  // double l = 0, r = 2e+9;
  // for (int it = 0; it < 100; ++it) {
  //   double m = (l + r) / 2;
  //   double xl = a - m, xr = a + m;
  //   double yl = b - m, yr = b + m;

  //   double kl = max((c - m) / xr, (d - m) / yr), kr = min((c + m) / xl, (d + m) / yl);

  //   if ((c - m) * yl <= (d + m) * xr && (d - m) * xl <= (c + m) * yr && 
  //     (c - m) * xl <= (c + m) * xr && (d - m) * yl <= (d + m) * yr) r = m;
  //   else l = m;  
  // }
  // printf("%.12lf\n", (l + r) / 2);
  // double l = 1.0 * (c * c - d * d) / (a + d - b - c), r = ;
  // printf("%.12lf\n", );

  long double l = 0, r = 2e+9; //max(max(a, b), max(c, d));
  for (int it = 0; it < 200; ++it) {
    long double m = (l + r) / 2;

    bool ok = false;
    long double x1 = m, y1 = m;
    long double x2 = m, y2 = -m;
    long double x3 = -m, y3 = m;
    long double x4 = -m, y4 = -m;
    if (good(a, b, x1 - c, y1 - d, m) ||
        good(a, b, x2 - c, y2 - d, m) ||
        good(a, b, x3 - c, y3 - d, m) ||
        good(a, b, x4 - c, y4 - d, m)) ok = true;

    if (good(c, d, x1 - a, y1 - b, m) ||
        good(c, d, x2 - a, y2 - b, m) ||
        good(c, d, x3 - a, y3 - b, m) ||
        good(c, d, x4 - a, y4 - b, m)) ok = true;

    // bool ok = false;
    // for (int mask = 0; mask < 16; ++mask) {
    //   int cur = mask;
    //   double mat[2][2] = {{m, m}, {m, m}};
    //   for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j < 2; ++j) {
    //       if (cur & 1) mat[i][j] *= -1;
    //       cur >>= 1;
    //     }
    //   }
    //   mat[0][0] -= a;
    //   mat[0][1] -= b;
    //   mat[1][0] -= c;
    //   mat[1][1] -= d;
    //   if (fabs(mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) < 1e-9) ok = true;
    // }
    if (ok) r = m;
    else l = m;
  }
  printf("%.12lf\n", (double) r);

  return 0;
}