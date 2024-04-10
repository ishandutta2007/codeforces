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

int nr, N, mod, a[200009], p[200009], e[200009], fac[200009], inv[200009], suf[200009];

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int comb (int N, int K)
{
    if (K < 0 || K > N) return 0;
    int p = (1LL * fac[N] * inv[K]) % mod;
    p = (1LL * p * inv[N - K]) % mod;
    return p;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), mod = 1e9 + 7;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1);
for (int i=1; i<=N; i++)
{
    int j;
    for (j=i; j<=N; j++)
        if (a[j] != a[i]) break;
    j --;
    p[++nr] = a[i], e[nr] = j - i + 1;
    i = j;
}
int sol = 1;
suf[nr + 1] = 1;
for (int i=nr; i>=1; i--)
    suf[i] = (1LL * suf[i + 1] * (e[i] + 1)) % (mod - 1);
int curr = 1;
for (int i=1; i<=nr; i++)
{
    int curr2 = (1LL * curr * suf[i + 1]) % (mod - 1), curr3 = 1, sol2 = 1;
    for (int j=0; j<=e[i]; j++)
    {
        sol2 = (1LL * sol2 * curr3) % mod;
        curr3 = (1LL * curr3 * p[i]) % mod;
    }
    sol = (1LL * sol * pow (sol2, curr2)) % mod;
    curr = (1LL * curr * (e[i] + 1)) % (mod - 1);
}
printf ("%d\n", sol);
return 0;
}