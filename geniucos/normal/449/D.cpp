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

int N, dp[21][1048580], nrb[1048580], p[1000009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int sol = 0, mod = 1000000007;
p[0] = 1;
scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int ai;
    scanf ("%d", &ai);
    dp[0][ai] ++;

    p[i] = p[i-1] << 1;
    if (p[i] >= mod)
        p[i] -= mod;
}

for (int bit = 1; bit <= 20; bit ++)
    for (int i = 0; i < (1<<20); i ++)
    {
        if (i & (1 << (bit - 1)))
            dp[bit][i] = dp[bit-1][i];
        else
        {
            dp[bit][i] = dp[bit-1][i] + dp[bit-1][i | (1 << (bit - 1))];
            if (dp[bit][i] >= mod)
                dp[bit][i] -= mod;
        }
    }

for (int i=0; i<(1<<20); i++)
{
    //if (dp[20][i])
      //  printf ("%d -> %d\n", i, dp[20][i]);
    nrb[i] = nrb[i>>1] ^ (i & 1);
    if (nrb[i])
    {
        sol -= p[dp[20][i]];
        if (sol < 0)
            sol += mod;
    }
    else
    {
        sol += p[dp[20][i]];
        if (sol >= mod)
            sol -= mod;
    }
}
//printf ("\n\n");
printf ("%d\n", sol);

return 0;
}