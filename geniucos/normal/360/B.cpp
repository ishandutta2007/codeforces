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

int N, K, dp[2015], a[2015];

int mod (int a)
{
    if (a < 0)
        return -a;
    return a;
}

bool ok (int max_dif)
{
    for (int i=1; i<=N; i++)
        dp[i] = i - 1;

    for (int i=1; i<N; i++)
        for (int j=i+1; j<=N; j++)
            if (mod (a[i] - a[j]) <= 1LL * (j - i) * max_dif && dp[i] + j - i - 1 < dp[j])
                dp[j] = dp[i] + j - i - 1;

    for (int i=1; i<=N; i++)
        if (dp[i] + N - i <= K)
            return 1;

    return 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);

if (K == N)
{
    printf ("0\n");
    return 0;
}

for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);

int p, u, mij, ras;
p = 0;
u = 2000000009;
while (p <= u)
{
    mij = p + ((u - p) >> 1);
    if (ok (mij))
        ras = mij, u = mij - 1;
    else
        p = mij + 1;
}
printf ("%d\n", ras);

return 0;
}