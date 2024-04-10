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

int N, a[200009];
double sum[200009], cum, mini, maxi, minp, maxp;

double Cost (double x)
{
    for (int i=1; i<=N; i++)
        sum[i] = (double) sum[i-1] + a[i] - x;
    mini = (double) a[1] - x, maxi = (double) a[1] - x, minp = 0.0, maxp = 0.0;
    for (int i=1; i<=N; i++)
    {
        if (sum[i] - minp > maxi) maxi = sum[i] - minp;
        if (sum[i] - maxp < mini) mini = sum[i] - maxp;
        if (sum[i] > maxp) maxp = sum[i];
        if (sum[i] < minp) minp = sum[i];
//        printf ("%d %d\n", (int)mini, maxi);
    }
    if (mini < 0) mini = -mini;
    if (maxi < 0) maxi = -maxi;
    if (mini > maxi) maxi = mini;
    return maxi;
//    return (double) x * x + x - 1.0;
}

double ternar_search (double st, double dr)
{
    if (dr - st <= 1e-11)
    {
        cum = (double) (dr + st) / 2.0;
        return Cost (cum);
    }
    double mid1, mid2, C1, C2;
    //printf ("[%.10lf %.10lf]\n", st, dr);
    mid1 = (double) st + (double) (dr - st) / 3.0;
    mid2 = (double) dr - (double) (dr - st) / 3.0;
    C1 = Cost (mid1), C2 = Cost (mid2);
    if (C1 > C2) return ternar_search (mid1, dr);
    return ternar_search (st, mid2);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
//for (double i = 0.0; i <= 10.0; i += 0.5)
  //  printf ("%.10lf\n", Cost (i));/
// printf ("%.10lf\n", Cost (-0.5));
//printf ("%.10lf\n", ternar_search (0.0, 30000.0));
printf ("%.10lf\n", ternar_search (-10000.0, 10000.0));
//printf ("%.10lf\n", cum);

return 0;
}