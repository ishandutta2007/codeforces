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

int N, ans, T, A, B, a[500009], b[500009], cst[500009];
char sir[500009];

void Solve ()
{
    int j = N - 1;
    for (int i=0; i<N; i++)
    {
        ///b[i] + A * i + a[j]
        while ((long long) 1LL * A * i + b[i] + a[j] > T && j >= 0) j --;
        if (j == -1) break;
        if (i + j > ans) ans = i + j;
    }
    j = N - 1;
    for (int i=0; i<N; i++)
    {
        ///a[i] + A * i + b[j]
        while ((long long) 1LL * A * i + a[i] + b[j] > T && j >= 0) j --;
        if (j == -1) break;
        if (i + j > ans) ans = i + j;
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d\n", &N, &A, &B, &T);
gets (sir + 1);
long long tot = 1LL * A * (N - 1);
for (int i=1; i<=N; i++)
{
    tot ++;
    if (sir[i] == 'w') tot += B;
}
if (tot <= T)
{
    printf ("%d\n", N);
    return 0;
}
for (int i=1; i<=N; i++)
{
    cst[i] = 1;
    if (sir[i] == 'w') cst[i] += B;
}
if (cst[1] > T)
{
    printf ("0\n");
    return 0;
}
T -= cst[1];
for (int i=1; i<N; i++)
    a[i] = A + cst[i + 1] + a[i - 1];
for (int i=1; i<N; i++)
    b[i] = A + b[i - 1] + cst[N - i + 1];
Solve ();
printf ("%d\n", ans + 1);
return 0;
}