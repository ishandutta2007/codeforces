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

int N, mod, unu, dp[1000009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), mod = 1e9 + 7;
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x);
    if (x == 1) unu ++;
}

dp[0] = 1, dp[1] = 1;
for (int i=2; i<=unu; i++)
    dp[i] = ((long long) dp[i - 1] + 1LL * (i - 1) * dp[i - 2]) % mod;
int ans = dp[unu];
for (int i=unu + 1; i<=N; i++)
    ans = (1LL * ans * i) % mod;
printf ("%d\n", ans);
return 0;
}