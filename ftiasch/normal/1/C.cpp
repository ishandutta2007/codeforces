// Codeforces Beta Round #1
// Problem C -- Ancient Berland Circus
#include <cmath>
#include <cstdio>

#define PI 3.14159265358979323846264
#define EPS 1e-6

using namespace std;

struct TPoint
{
  double x, y;
};

TPoint A, B, C;
double a, b, c, r, S, ans;

bool isint(int n, double x, double y)
{
  for(int i = 1; i < n; ++ i)
    if(fabs((2 * r * r - y * y) / (2 * r * r) - cos(x * i)) <= EPS)
      return true;
  return false;
}

int main()  
{
  scanf("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
  a = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y)),
  b = sqrt((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y)),
  c = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)),         
  S = 0.5 * fabs((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x)),
  r = 0.25 * a * b * c / S,
  ans = 1e10;
  for(int n = 3; n <= 100; ++ n)
  {
    double arc = 2 * PI / n;
    if(isint(n, arc, a) && isint(n, arc, b) && isint(n, arc, c))
    {
      double tmp = 0.5 * r * r * sin(arc) * n;
      if(tmp < ans)
        ans = tmp;
    }
  }
  printf("%.6lf\n", ans);
  return 0;
}