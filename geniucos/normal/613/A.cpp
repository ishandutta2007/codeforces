#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#define PI 3.14159265358979323846

using namespace std;

int N, xx, yy;
int last_x, last_y, fir_x, fir_y;
long double mini, maxi;

void Try (int x, int y)
{
    long double a, b;
    if (last_x != x)
    {
        a = (long double) (last_y - y) / (last_x - x);
        b = (long double) y - (long double) x * a;
        long double bst_x = (double) -a * b / ((long double) 1.0 + a * a);
        if (bst_x < min (x, last_x) || bst_x > max (x, last_x)) ;
        else
        {
            long double bst_y = a * bst_x + b, d;
            d = (long double) bst_x * bst_x + bst_y * bst_y;
            if (d < mini) mini = d;
        }
        return ;
    }
    if (min (y, last_y) <= 0 && max (y, last_y) >= 0 && 1LL * x * x < mini)
        mini = 1LL * x * x;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &xx, &yy);
for (int i=1; i<=N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    x -= xx, y -= yy;
    long long d = (long long) 1LL * x * x + 1LL * y * y;
    if (i == 1) mini = maxi = d, fir_x = x, fir_y = y;
    else
    {
        if (d < mini) mini = d;
        if (d > maxi) maxi = d;
    }
    if (i != 1) Try (x, y);
    last_x = x, last_y = y;
}
if (N != 1) Try (fir_x, fir_y);
///pi (maxi - mini)
//printf ("%.15f\n", (double) PI * ((double) maxi - mini));
long double val = (long double) PI * ((long double) ((long long) maxi - mini));
cout << setprecision (15) << val;
//cout << '\n' << setprecision (15) << mini;
return 0;
}