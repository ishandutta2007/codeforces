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

int ans, N, mod;//, C[2009][2009], dp[1000009];

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1<<i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int fac (int N)
{
    int p = 1;
    for (int i=1; i<=N; i++)
        p = (1LL * p * i) % mod;
    return p;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), N ++;
/*C[0][0] = 1;
for (int i=1; i<=1000; i++)
{
    C[i][0] = 1;
    for (int j=1; j<=i; j++)
        C[i][j] = C[i-1][j-1] + C[i-1][j];
}

for (int i=0; i<=N; i++)
    for (int j=0; j<=N; j++)
        sol += C[i+j][j];
printf ("%d\n", sol);*/
/*dp[1] = 5, ;
for (int i=2; i<=N; i++)
    dp[i] = ((long long) 1LL * dp[i-1] * 4 + mod - 1) % mod;
printf ("%d\n", dp[N]);*/
mod = 1000000007;
int ans = (1LL * 2 * fac (2 * N - 1)) % mod;
ans = (1LL * ans * pow (fac (N - 1), mod - 2)) % mod;
ans = (1LL * ans * pow (fac (N), mod - 2)) % mod;
ans = ((long long) ans + mod - 1) % mod;
printf ("%d\n", ans);
return 0;
}