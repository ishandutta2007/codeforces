#include<bits/stdc++.h>

using namespace std;

int N, K, ways[5009], c[5009][5009];
const int mod = 1e9 + 7;

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

int brute (int N, int K)
{
    int ans = 0, cmb = 1;
    for (int i=1; i<=N; i++)
    {
        cmb = mul (cmb, N - i + 1);
        cmb = mul (cmb, power (i, mod - 2));
        int curr = mul (cmb, power (i, K));
        adto (ans, curr);
    }
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
c[0][0] = 1;
for (int i=1; i<=K; i++)
{
    c[i][0] = 1;
    for (int j=1; j<=i; j++)
        c[i][j] = add (c[i - 1][j - 1], c[i - 1][j]);
}
ways[1] = 1;
for (int i=2; i<=K; i++)
{
    ways[i] = power (i, K);
    for (int j=1; j<i; j++)
        ways[i] = subtract (ways[i], mul (c[i][j], ways[j]));
}
int ans = 0, cmb = 1;
for (int dff = 1; dff <= K; dff ++)
{
    cmb = mul (cmb, N - dff + 1);
    cmb = mul (cmb, power (dff, mod - 2));
    int curr = mul (cmb, power (2, N - dff));
    curr = mul (curr, ways[dff]);
    adto (ans, curr);
}
printf ("%d\n", ans);
//printf ("%d\n", brute (N, K));
return 0;
}