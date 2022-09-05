#include<bits/stdc++.h>

using namespace std;

int ans, ans2, F, W, H, mod = 1e9 + 7, dp2[100009], fac[250009], inv[250009];

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int substract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
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

void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = pow (fac[lim], mod - 2);for (int i=lim - 1; i>=1; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &F, &W, &H), Prec (250000);

if (H == 0 || W == 0) printf ("1\n");
else
if (F == 0) printf ("%d\n", (W > H));
else
{
    for (int n1 = 0; n1 <= F; n1 ++)
    {
        for (int n2 = max (n1 - 1, 0); n2 <= min (n1 + 1, W / (H + 1)); n2 ++)
        {
            int curr = mul (comb (W - n2 * H - 1, n2 - 1), comb (F - 1, n1 - 1));
            if (n1 == n2) curr = add (curr, curr);
            ans = add (ans, curr);
        }
        for (int n2 = max (n1 - 1, 0); n2 <= min (n1 + 1, W); n2 ++)
        {
            int curr = mul (comb (W - 1, n2 - 1), comb (F - 1, n1 - 1));
            if (n1 == n2) curr = add (curr, curr);
            ans2 = add (ans2, curr);
        }
    }
    ans = mul (ans, pow (ans2, mod - 2));
    printf ("%d\n", ans);
}
return 0;
}