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

int N, K, mod, P, nr, inv[100009], fac[100009], dp[2015][2015], cnt[2015];
map < int , int > mp;

bool lucky (int val)
{
    while (val)
    {
        if (val % 10 != 4 && val % 10 != 7) return 0;
        val /= 10;
    }
    return 1;
}

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

int comb (int N, int K)
{
    if (K > N || K < 0) return 0;
    int p = (1LL * fac[N] * inv[N - K]) % mod;
    p = (1LL * p * inv[K]) % mod;
    return p;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K), mod = 1e9 + 7;

fac[0] = 1;
for (int i=1; i<=N; i++)
    fac[i] = (1LL * fac[i-1] * i) % mod;
inv[N] = pow (fac[N], mod - 2);
for (int i=N - 1; i>=0; i--)
    inv[i] = (1LL * inv[i+1] * (i + 1)) % mod;

for (int i=1; i<=N; i++)
{
    int curr;
    scanf ("%d", &curr);
    if (!lucky (curr)) nr ++;
    else mp[curr] ++;
}

for (map < int , int > :: iterator it = mp.begin (); it != mp.end (); it ++)
    cnt[++P] = it->second;

dp[0][0] = 1;
for (int i=1; i<=P; i++)
{
    dp[i][0] = 1;
    for (int j=1; j<=i; j++)
        dp[i][j] = ((long long)dp[i-1][j] + 1LL * dp[i-1][j-1] * cnt[i]) % mod;
}

int sol = 0;
for (int i=0; i<=P && i <= K; i++)
    sol = ((long long)sol + 1LL * dp[P][i] * comb (nr, K - i)) % mod;
printf ("%d\n", sol);
return 0;
}