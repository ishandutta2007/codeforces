#include<bits/stdc++.h>

using namespace std;

int N, A, B, K, pa[100009], pb[100009];
char s[100009];
const int mod = 1e9 + 9;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d\n", &N, &A, &B, &K);
scanf ("%s", s);
pa[0] = 1, pb[0] = 1;
for (int i=1; i<=K; i++)
    pa[i] = mul (pa[i - 1], A),
    pb[i] = mul (pb[i - 1], B);
int trm = 0;
for (int i=0; i<K; i++)
{
    int curr = mul (pa[K - i], pb[i]);
    if (s[i] == '+') adto (trm, curr);
    else trm = subtract (trm, curr);
}
int josA = power (A, mod - 2), bak = power (mul (B, josA), K);
int ans = 0, times = (N + 1) / K, strt = mul (power (A, N), power (josA, K));
if (bak == 1) ans = mul (strt, times);
else
{
    int sus = subtract (power (bak, times), 1), jos = subtract (bak, 1), gp = mul (sus, power (jos, mod - 2));
    ans = mul (strt, gp);
}
printf ("%d\n", mul (ans, trm));
return 0;
}