#include<bits/stdc++.h>

using namespace std;

int N, R, x[1009];
double y[1009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &R);
for (int i=1; i<=N; i++)
    scanf ("%d", &x[i]);
for (int i=1; i<=N; i++)
{
    y[i] = (double) R;
    for (int j=1; j<i; j++)
    {
        int dx = x[i] - x[j];
        if (dx < 0) dx = -dx;
        if (dx > 2 * R) continue;
        int pt = 4 * R * R - dx * dx;
        double currY = y[j] + (double) sqrt ((double) pt);
        if (currY > y[i]) y[i] = currY;
    }
    printf ("%.15f ", y[i]);
}
printf ("\n");

return 0;
}