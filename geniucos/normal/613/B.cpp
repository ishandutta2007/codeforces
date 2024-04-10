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

int hi, hj, N, Cf, Cm, A, a[100009], pos[100009];
long long maxi, M, h_val, ans[100009], s[100009];
pair < int, int > b[100009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d %I64d\n", &N, &A, &Cf, &Cm, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), b[i].first = a[i], b[i].second = i;
sort (b + 1, b + N + 1);
for (int i=1; i<=N; i++)
    a[i] = b[i].first, pos[i] = b[i].second;
long long tot = 0;
for (int i=1; i<=N; i++)
    tot += A - a[i];
if (tot <= M)
{
    printf ("%I64d\n", 1LL * N * Cf + 1LL * A * Cm);
    for (int i=1; i<=N; i++)
        printf ("%d ", A);
    printf ("\n");
    return 0;
}
///cresc valorile ultimelor de la i la N
long long needed = 0, curr_s = 0;
for (int i=1; i<=N; i++)
    s[i] = s[i - 1] + a[i];
maxi = -1;
for (int i=N + 1; i>=1; i--)
{
    if (i <= N) needed += A - a[i];
    if (needed > M) break;
    ///[i, N] crescute
    int p = 1, u = i - 1, mij, ras;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (1LL * a[mij] * mij - s[mij] <= M - needed) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    int j = ras;
    long long curr_s = 1LL * a[j] * j - s[j];
    long long val = a[j] + (M - needed - curr_s) / j;
    if (val > A) val = A;
    if (1LL * (N - i + 1) * Cf + 1LL * val * Cm > maxi)
        maxi = 1LL * (N - i + 1) * Cf + 1LL * val * Cm, hi = i, hj = j, h_val = val;
}
printf ("%I64d\n", maxi);
for (int i=1; i<=N; i++)
{
    int p = pos[i];
    if (i <= hj) ans[p] = h_val;
    else
    if (i < hi) ans[p] = a[i];
    else ans[p] = A;
}
for (int i=1; i<=N; i++)
    printf ("%I64d ", ans[i]);
printf ("\n");
return 0;
}