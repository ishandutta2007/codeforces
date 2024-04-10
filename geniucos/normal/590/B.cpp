#include<cstdio>

using namespace std;

int a1, b1, a2, b2, T, ux, wx, uy, wy, v;
double vmax, x, y;

bool ok (double t)
{
    double t1, t2;
    if (t <= T) t1 = t, t2 = 0;
    else t1 = T, t2 = t - T;
    double A = (double) x - (ux * t1 + wx * t2);
    double B = (double) y - (uy * t1 + wy * t2);
    return ((double) A * A + B * B <= (double)vmax * vmax * t * t);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &a1, &b1, &a2, &b2), x = (double) a2 - a1, y = (double) b2 - b1;
scanf ("%d %d", &v, &T), vmax = (double) v;
scanf ("%d %d", &ux, &uy);
scanf ("%d %d", &wx, &wy);

double l = 0, r = 1e14;
int step = 2000000;
while (step --)
{
    double mid = (double) (l + r) / 2.0;
    if (ok (mid)) r = mid;
    else l = mid;
}
printf ("%.15lf\n", l);

return 0;
}