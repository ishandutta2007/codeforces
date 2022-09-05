#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<unordered_map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, K, a[30];
long long fac[30], S, sol;
unordered_map < long long , int > dp[30];

int mod (int x)
{
    if (x < 0) return -x;
    return x;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %I64d", &N, &K, &S);

for (int i=0; i<N; i++)
    scanf ("%d", &a[i]);

int juma = N / 2;

fac[0] = 1LL;
for (int i=1; i<=18; i++)
    fac[i] = 1LL * fac[i-1] * i;

for (int bigj = 0; bigj<(1<<juma); bigj++)
    for (int j=0; j<(1<<juma); j++)
    if ((j & bigj) == j)
    {
        bool ok = 1;
        int nr = 0;
        for (int p=0; p<juma; p++)
        if (bigj & (1<<p))
        {
            if ((j & (1<<p)) && a[p] > 20)
                ok = 0;
            if (j & (1<<p))
                nr ++;
        }

        if (ok == 0)
            continue;

        if (nr > K)
            continue;

        long long s1 = 0;
        for (int p=0; p<juma; p++)
        if (bigj&(1<<p))
        {
            if (j & (1<<p))
                s1 += fac[a[p]];
            else
                s1 += a[p];
        }

        if (s1 <= S)
            dp[nr][s1] ++;
    }

//printf ("%d %d\n %d %d\n", dp[0][0], dp[1][0], dp[0][1], dp[1][1]);

int restul = N - juma;
for (int bigj = 0; bigj<(1<<restul); bigj++)
    for (int msk = 0; msk < (1<<restul); msk ++)
    if ((msk & bigj) == msk)
    {
        long long s2 = 0;
        int nr = 0;
        bool ok = 1;
        for (int i=juma; i<N; i++)
        if (bigj & (1<<(i-juma)))
        {
            if (msk & (1 << (i - juma)))
            {
                if (a[i] > 20)
                {
                    ok = 0;
                    break;
                }
                nr ++, s2 += fac[a[i]];
            }
            else
                s2 += a[i];
        }

        if (ok && s2 <= S && nr <= K)
        {
            for (int p = 0; p + nr <= K; p++)
                if (dp[p][S-s2])
                    sol += dp[p][S - s2];
        }
    }

printf ("%I64d\n", sol);

return 0;
}