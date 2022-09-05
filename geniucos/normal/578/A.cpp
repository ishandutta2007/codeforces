#include<iomanip>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

long long A, B;

double Get (long long k2x, long long minx)
{
    long long p, u, mij, ras = -1;
    p = 1;
    u = k2x;
    while (p <= u)
    {
        mij = (p + u) >> 1LL;
        if (k2x >= 1LL * 2 * minx * mij) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    if (ras == -1) return -1;
    return (double) k2x / ((double)2.0 * ras);
}

double bun (double a, double b)
{
    if (a < -0.1) return b;
    if (b < -0.1) return a;
    if (a > b) return b;
    return a;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %I64d", &A, &B);
if (A == B)
{
    printf ("%I64d\n", A);
    return 0;
}
if (B > A)
{
    printf ("-1\n");
    return 0;
}
//printf ("%.10lf\n", Get (5, 2));
double ans = bun (Get (A + B, B), Get (A - B, B));
if (ans < -0.1) printf ("-1\n");
else printf ("%.10lf\n", ans);

return 0;
}