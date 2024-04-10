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

int nr, K, mod, ans[33], v[70];
long long N;

struct matrix
{
    int a[33][33];
    matrix () {memset (a, 0, sizeof (a));}
    matrix (bool type)
    {
        memset (a, 0, sizeof (a));
        if (type == 1)
            for (int i=0; i<=K; i++)
                a[i][i] = 1;
    }
}dp[70][33], pref[33], suf[33];

matrix operator * (matrix a, matrix b)
{
    matrix c;
    for (int i=0; i<=K; i++)
        for (int j=0; j<=K; j++)
        {
            c.a[i][j] = 0;
            for (int k=0; k<=K; k++)
                c.a[i][j] = ((long long)c.a[i][j] + 1LL * a.a[i][k] * b.a[k][j]) % mod;
        }
    return c;
}

void Prod (matrix a)
{
    int old[33];
    for (int i=0; i<=K; i++)
        old[i] = ans[i];
    for (int i=0; i<=K; i++)
    {
        ans[i] = 0;
        for (int j=0; j<=K; j++)
            ans[i] = ((long long) ans[i] + 1LL * old[j] * a.a[j][i]) % mod;
    }
}

void Finish ()
{
    int sum = 0;
    for (int i=0; i<=K; i++)
        sum = ((long long) sum + ans[i]) % mod;
    printf ("%d\n", sum);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %d", &N, &K), mod = 1e9 + 7;
long long aux = N;
while (aux) v[nr ++] = aux % K, aux /= K;
for (int i=0; i<K; i++)
{
    for (int j=0; j<=K; j++)
        if (j != i) dp[0][i].a[j][j] = 1;
    for (int j=0; j<=K; j++)
        dp[0][i].a[j][i] = 1;
}

for (int i=1; i<nr; i++)
{
    pref[0] = dp[i - 1][0];
    for (int j=1; j<K; j++)
        pref[j] = pref[j - 1] * dp[i - 1][j];
    suf[K] = matrix (1);
    for (int j=K - 1; j>=0; j--)
        suf[j] = dp[i - 1][j] * suf[j + 1];

    dp[i][0] = suf[0];
    for (int j=1; j<K; j++)
        dp[i][j] = suf[j] * pref[j - 1];
}

ans[K] = 1;
int curr = 0;
for (int i=nr - 1; i>=0; i--)
    while (v[i] --) Prod (dp[i][curr]), curr = (curr + 1) % K;
Finish ();
return 0;
}