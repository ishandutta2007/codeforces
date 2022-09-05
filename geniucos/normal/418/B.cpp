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

int lim, N, M, b;
long long dp[(1 << 20) + 3], INF = 1LL << 61;
pair < int , pair < int , int > > f[109];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &b);
for (int i=1; i<=N; i++)
{
    int l, x;
    scanf ("%d %d %d", &f[i].second.first, &f[i].first, &l);
    while (l --) scanf ("%d", &x), f[i].second.second |= 1 << (x - 1);
}
sort (f + 1, f + N + 1);
dp[0] = 0, lim = (1 << M) - 1;
for (int i=1; i<=lim; i++)
    dp[i] = INF;
long long mini = INF;
for (int i=1; i<=N; i++)
{
    for (int j=lim; j>=0; j--)
        if (dp[j | f[i].second.second] > dp[j] + f[i].second.first)
            dp[j | f[i].second.second] = dp[j] + f[i].second.first;
    if (dp[lim] + 1LL * b * f[i].first < mini)
        mini = dp[lim] + 1LL * b * f[i].first;
}
if (mini >= INF) printf ("-1\n");
else printf ("%I64d\n", mini);

return 0;
}