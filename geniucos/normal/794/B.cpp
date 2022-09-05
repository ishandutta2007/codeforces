#include<bits/stdc++.h>

using namespace std;

int N, H;
double ans[2017];

double getB (double h2)
{
    return (double) 1.0 * (H - h2) / (1.0 * H);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &H);
double area = (double) (H / 2.0) / N;
double currH = 0;
for (int i=1; i<N; i++)
{
    double p = currH, u = H, mij, ras;
    int steps = 200;
    while (steps --)
    {
        mij = (p + u) / 2.0;
        double currArea = (getB (currH) + getB (mij)) / 2.0 * (mij - currH);
        if (currArea <= area) ras = p = mij;
        else u = mij;
    }
    //printf ("%.10f\n", (getB (currH) + getB (ras)) / 2.0 * (ras - currH));
    ans[i] = ras;
    currH = ras;
}
for (int i=N - 1; i>=1; i--)
    printf ("%.10f ", H - ans[i]);
return 0;
}