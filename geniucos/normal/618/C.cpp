#include<cstdio>
#include<bitset>
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

int N, x[100009], y[100009];

long long mod (long long x)
{
    if (x < 0) return -x;
    return x;
}

long long det (int i, int j, int k)
{
    return (long long) mod ((long long) 1LL * x[i] * y[j] + 1LL * x[j] * y[k] + 1LL * x[k] * y[i] - 1LL * x[i] * y[k] - 1LL * x[j] * y[i] - 1LL * x[k] * y[j]);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &x[i], &y[i]);
int i = 1, j = 2, k;
for (int p=3; p<=N; p++)
    if (det (i, j, p) > 0)
    {
        k = p;
        break;
    }
for (int p=1; p<=N; p++)
    if (p != i && p != j && p != k && (long long) det (i, j, p) + det (i, k, p) + det (j, k, p) == det (i, j, k))
    {
        if (det (i, j, p) != 0) k = p;
        else
        if (det (i, k, p) != 0) j = p;
        else i = p;
    }
printf ("%d %d %d\n", i, j, k);
return 0;
}