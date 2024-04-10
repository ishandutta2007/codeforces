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

long long maxi, N, M, K, a[109][109], x[109], y[109];
vector < long long > difx[109], dify[109];

long long gcd (long long a, long long b)
{
    long long r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %I64d", &N, &M);
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
    {
        scanf ("%I64d", &a[i][j]);
        if (a[i][j] > maxi)
            maxi = a[i][j];
    }

if (N == 1 && M == 1)
{
    printf ("YES\n");
    printf ("%I64d\n", a[1][1] + 1);
    printf ("%I64d\n0\n", a[1][1]);
    return 0;
}

if (N == 1)
{
    printf ("YES\n");
    printf ("%I64d\n", maxi + 1);
    printf ("0\n");
    for (int i=1; i<=M; i++)
        printf ("%I64d ", a[1][i]);
    printf ("\n");
    return 0;
}

if (M == 1)
{
    printf ("YES\n");
    printf ("%I64d\n", maxi + 1);
    for (int i=1; i<=N; i++)
        printf ("%I64d ", a[i][1]);
    printf ("\n0\n");
    return 0;
}

for (int i=1; i<=N; i++)
    for (int j=2; j<=M; j++)
        dify[j].push_back (a[i][j] - a[i][j-1]);

for (int i=2; i<=N; i++)
    for (int j=1; j<=M; j++)
        difx[i].push_back (a[i][j] - a[i-1][j]);

K = 0;

for (int j=2; j<=M; j++)
{
    sort (dify[j].begin(), dify[j].end());
    for (int k=1; k<dify[j].size(); k++)
        K = gcd (K, dify[j][k] - dify[j][k-1]);
}

for (int i=2; i<=N; i++)
{
    sort (difx[i].begin(), difx[i].end());
    for (int k=1; k<difx[i].size(); k++)
        K = gcd (K, difx[i][k] - difx[i][k-1]);
}

if (K == 0)
    K = maxi + 1;

for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (a[i][j] >= K)
        {
            printf ("NO\n");
            return 0;
        }

for (int i=1; i<=N; i++)
    x[i] = a[i][1];
y[1] = 0;
for (int j=2; j<=M; j++)
    y[j] = ((long long)((long long)y[j-1] + a[1][j] - a[1][j-1]) % K + K) % K;
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (a[i][j] != ((long long)x[i] + y[j]) % K)
        {
            printf ("NO\n");
            return 0;
        }
printf ("YES\n");
printf ("%I64d\n", K);
for (int i=1; i<=N; i++)
    printf ("%I64d ", x[i]);
printf ("\n");
for (int i=1; i<=M; i++)
    printf ("%I64d ", y[i]);
printf ("\n");
return 0;
}