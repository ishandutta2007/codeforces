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

int sol, mod, N, c[4009][4009], dp[4009], put[4009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), mod = 1e9 + 7;
c[0][0] = 1;
for (int i=1; i<=N; i++)
{
    c[i][0] = 1;
    for (int j=1; j<=i; j++)
    {
        c[i][j] = c[i-1][j] + c[i-1][j-1];
        if (c[i][j] >= mod) c[i][j] -= mod;
    }
}

put[0] = 1;
for (int i=1; i<=N; i++)
{
    put[i] = put[i-1] + put[i-1];
    if (put[i] >= mod) put[i] -= mod;
}

dp[0] = 1, dp[1] = 0, dp[2] = 1;
for (int i=3; i<=N; i++)
    for (int j=2; j<=i; j++)
        dp[i] = ((long long) 1LL * dp[i-j] * c[i-1][j-1] + dp[i]) % mod;////aleg celelalte j - 1 noduri(care sunt impreuna cu primul)

int sol = 0;
for (int i=1; i<=N; i++)
{
    int curr = (1LL * (put[i] + mod - 1) * dp[N - i]) % mod;
    curr = (1LL * curr * c[N][i]) % mod;
    sol += curr;
    if (sol >= mod) sol -= mod;
}
printf ("%d\n", sol);

return 0;
}