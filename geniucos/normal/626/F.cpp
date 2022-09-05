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

int S, mod, N, K, a[209], s[209], dp[209][1009], old[209][1009];

void add (int j, int k, long long v2)
{
    if (k > K || k < 0 || j < 0) return ;
    dp[j][k] = ((long long) dp[j][k] + v2) % mod;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1);
dp[0][0] = 1, mod = 1e9 + 7;
for (int i=1; i<=N; i++)
{
    for (int j=0; j<=i && j <= N - i + 1; j++)
        for (int k=0; k<=K; k++)
            old[j][k] = dp[j][k], dp[j][k] = 0;
    for (int j=0; j<=i && j <= N - i + 1; j++)
        for (int k=0; k<=K; k++)
        if (old[j][k])
        {
            add (j + 1, k + (a[i + 1] - a[i]) * (j + 1), old[j][k]);
            add (j, k + (a[i + 1] - a[i]) * j, 1LL * old[j][k] * (j + 1));
            add (j - 1, k + (a[i + 1] - a[i]) * (j - 1), 1LL * j * old[j][k]);
        }
}
int sol = 0;
for (int j=0; j<=K; j++)
{
    sol += dp[0][j];
    if (sol >= mod) sol -= mod;
}
printf ("%d\n", sol);
return 0;
}