// Codeforces Beta Round #2
// Problem C -- Commentator problem
#include <cmath>
#include <cstdio>
#include <algorithm>

#define SQR(x) (x) * (x)
#define EPS 1e-6

using namespace std;

double x[3], y[3], r[3], g[3];

double f(double ax, double ay)
{
  for(int i = 0; i < 3; ++ i)
    g[i] = sqrt(SQR(ax - x[i]) + SQR(ay - y[i])) / r[i];
  double tmp = 0;
  for(int i = 0; i < 3; ++ i)
    tmp += SQR(g[i] - g[(i + 1) % 3]);
  return tmp;
}

int main()
{
  for(int i = 0; i < 3; ++ i)
    scanf("%lf%lf%lf", x + i, y + i, r + i);
  double dt = 1,
         ax = (x[0] + x[1] + x[2]) / 3,
         ay = (y[0] + y[1] + y[2]) / 3,
         dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
  while(dt > EPS)
  {
    int bs = -1; double nv = f(ax, ay);
    for(int i = 0; i < 4; ++ i)
    {
      double tv = f(ax + dx[i] * dt, ay + dy[i] * dt);
      if(tv < nv)
        nv = tv, bs = i;
    }
    if(bs == -1)
      dt *= 0.7;
    else
      ax += dx[bs] * dt, ay += dy[bs] * dt;
  }
  if(f(ax, ay) < EPS)
    printf("%.5lf %.5lf\n", ax, ay);
  return 0;
}