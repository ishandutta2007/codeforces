#include<bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7, N, K;

int mul (int x, int y) {return 1LL * x * y % mod;}
int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

/*int comb (int N, int K)
{
    if (K > N || N < 0) return 0;
    int ans = mul (fac[N], invf[N - K]);
    ans = mul (ans, invf[K]);
    return ans;
}*/

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
int tot = (240 - K) / 5, sol = 0;
for (int i=1; i<=N; i++)
    if (tot < i) break;
    else tot -= i, sol ++;
printf ("%d\n", sol);
return 0;
}