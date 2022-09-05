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

int ans, N, K, Q, V, mod, fac[200009], inv[200009], phi[1000009], ap[1000009];
vector < int > v[1000009];

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
    if (K > N) return 0;
    int ans = (1LL * fac[N] * inv[N - K]) % mod;
    ans = (1LL * ans * inv[K]) % mod;
    return ans;
}

void add_val (int x)
{
    for (vector < int > :: iterator it = v[x].begin (); it != v[x].end (); it ++)
    {
        int delta = comb (ap[*it] + 1, K) - comb (ap[*it], K);
        if (delta < 0) delta += mod;
        ans = ((long long) ans + 1LL * phi[*it] * delta) % mod;
        ap[*it] ++;
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

V = 1000000, mod = 1e9 + 7;
for (int i=1; i<=V; i++)
    for (int j=i; j<=V; j+=i)
        v[j].push_back (i);
for (int i=1; i<=V; i++)
    phi[i] = i;
for (int i=2; i<=V; i++)
    if (phi[i] == i)
        for (int j=i; j<=V; j+=i)
            phi[j] /= i, phi[j] *= i - 1;
fac[0] = 1;
for (int i=1; i<=200000; i++)
    fac[i] = (1LL * fac[i - 1] * i) % mod;
inv[200000] = pow (fac[200000], mod - 2);
for (int i=199999; i>=0; i--)
    inv[i] = (1LL * inv[i + 1] * (i + 1)) % mod;
scanf ("%d %d %d", &N, &K, &Q);
for (int i=1; i<=N; i++)
{
    int val;
    scanf ("%d", &val);
    add_val (val);
}
while (Q --)
{
    int val;
    scanf ("%d", &val);
    add_val (val);
    printf ("%d\n", ans);
}
return 0;
}