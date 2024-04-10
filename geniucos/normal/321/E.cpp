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

int N, K, a[4009][4009], cost[4009][4009], dp[4009][809];
char sir[10009];

void solve (int j, int l, int r, int lo, int ro)
{
    int mo = 0, mij = (l + r) >> 1;
    dp[mij][j] = 1 << 28;
    for (int i=lo; i<=ro && i < mij; i++)
        if (dp[i][j - 1] + cost[i + 1][mij] < dp[mij][j])
            dp[mij][j] = dp[i][j - 1] + cost[i + 1][mij], mo = i;
    if (l < mij) solve (j, l, mij - 1, lo, mo);
    if (r > mij) solve (j, mij + 1, r, mo, ro);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &K);
for (int i=1; i<=N; i++)
{
    gets (sir + 2);
    for (int j=1; j<=N; j++)
        a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + sir[j << 1] - '0';
}
for (int i=1; i<=N; i++)
    for (int j=i; j<=N; j++)
        cost[i][j] = (a[j][j] - a[i - 1][j] - a[j][i - 1] + a[i - 1][i - 1]) / 2;
for (int i=1; i<=N; i++)
    dp[i][1] = cost[1][i];
for (int j=2; j<=K; j++)
    solve (j, 1, N, 0, N - 1);
printf ("%d\n", dp[N][K]);
return 0;
}