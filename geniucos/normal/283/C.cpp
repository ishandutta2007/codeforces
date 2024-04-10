#include<cstdio>
using namespace std;

int nr, n, Q, mod, dp[100009], nxt[100009], v[100009], ap[100009], prev[100009];
long long T, S[100009], a[100009];

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*printf ("280 279 97857\n");
for (int i=1; i<=280; i++)
    printf ("100000 ");
printf ("\n");
for (int i=1; i<=279; i++)
    printf ("%d %d\n", i, i+1);
return 0;*/

scanf ("%d %d %I64d", &n, &Q, &T);
for (int i=1; i<=n; i++)
    scanf ("%I64d", &a[i]);
for (int i=1; i<=Q; i++)
{
    int X, Y;
    scanf ("%d %d", &X, &Y);
    nxt[Y] = X;
    prev[X] = Y;
}

for (int i=1; i<=n; i++)
if (ap[i] == 0 && prev[i] == 0)
{
    int j = i;
    nr = 1;
    v[1] = i;
    ap[i] = 1;
    while (1)
    {
        j = nxt[j];
        if (j == 0) break;
        if (ap[j] == 1)
        {
            printf ("0\n");
            return 0;
        }
        ap[j] = 1;
        v [++ nr] = j;
    }
    S[nr+1] = 0;
    for (int i=nr; i>=1; i--)
        S[i] = S[i+1] + a[v[i]];
    for (int i=1; i<nr; i++)
    {
        T -= S[i+1];
        a[v[i]] += S[i+1];
    }
}

for (int i=1; i<=n; i++)
    if (ap[i] == 0)
    {
        printf ("0\n");
        return 0;
    }

if (T<0)
{
    printf ("0\n");
    return 0;
}

mod = 1000000007;
dp[0] = 1;
for (int i=1; i<=T; i++)
    dp[i] = 0;
for (int i=1; i<=n; i++)
    for (int j=a[i]; j<=T; j++)
    {
        dp[j] += dp[j-a[i]];
        if (dp[j] >= mod)
            dp[j] -= mod;
    }
printf ("%d\n", dp[T]);
return 0;
}