#include<bits/stdc++.h>

using namespace std;

int xp, yp, xv, yv;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &xp, &yp, &xv, &yv);
if (xp <= xv && yp <= yv)
{
    printf ("Polycarp\n");
    return 0;
}
int t1 = xp + yp, t2 = max (xv, yv);
if (t1 <= t2) printf ("Polycarp\n");
else printf ("Vasiliy\n");
return 0;
}