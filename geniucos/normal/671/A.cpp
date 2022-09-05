#include<bits/stdc++.h>

using namespace std;

int N;
double sol, d1[100009], d2[100009], d[100009];
pair < int, int > Pa, Pb, Pc, a[100009];

void Read (pair < int, int > &x)
{
    scanf ("%d %d", &x.first, &x.second);
}

double dist (pair < int, int > a, pair < int, int > b)
{
    return (double) sqrt ((double) 1.0 * (a.first - b.first) * (a.first - b.first) + 1.0 * (a.second - b.second) * (a.second - b.second));
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read (Pa), Read (Pb), Read (Pc), scanf ("%d", &N);
double min1 = 1e18, min2 = 1e18, Min = 1e18;
for (int i=1; i<=N; i++)
{
    Read (a[i]), d[i] = dist (Pc, a[i]), sol += 2.0 * d[i];
    d1[i] = dist (Pa, a[i]), d2[i] = dist (Pb, a[i]);
    double curr1 = d1[i] - d[i], curr2 = d2[i] - d[i];
    if (i > 1)
    {
        if (curr1 + min2 < Min) Min = curr1 + min2;
        if (curr2 + min1 < Min) Min = curr2 + min1;
    }
    if (curr1 < min1) min1 = curr1;
    if (curr2 < min2) min2 = curr2;
}
if (min1 < Min) Min = min1;
if (min2 < Min) Min = min2;
printf ("%.15f\n", sol + Min);

return 0;
}