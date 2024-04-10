#include<bits/stdc++.h>

using namespace std;

int N, P, a[100009], b[100009];

bool ok (double T)
{
    double s = 0.0;
    for (int i=1; i<=N; i++)
        if ((double) b[i] / a[i] < T)
        {
            if ((double) b[i] / T < (a[i] - P)) return 0;
            double curr = (double) (T * a[i] - b[i]) / P;
            if (curr > T || curr + s > T) return 0;
            s += curr;
        }
    return (s <= T);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &P);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i], &b[i]);
int steps = 170;
double p = 0.0, u = 1e18, mij;
if (ok (u))
{
    printf ("-1\n");
    return 0;
}
while (steps --)
{
    double mij = (p + u) / 2.0;
    if (ok (mij)) p = mij;
    else u = mij;
}
printf ("%.10f\n", (p + u) / 2.0);

return 0;
}