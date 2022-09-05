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

int N, mod, ap[300], cnt, maxi, fac[100509], inv[100509];
char sir[100009];

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b&(1<<i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int comb (int n, int k)
{
    int p = (1LL * fac[n] * inv[k]) % mod;
    p = (1LL * p * inv[n-k]) % mod;
    return p;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
gets (sir + 1);
for (int i=1; i<=N; i++)
    ap[sir[i]-'A'] ++;
for (int i=0; i<26; i++)
{
    if (ap[i] > maxi)
        maxi = ap[i], cnt = 1;
    else
    if (ap[i] == maxi)
        cnt ++;
}
mod = 1000000007;
printf ("%d\n", pow (cnt, N));

return 0;
}