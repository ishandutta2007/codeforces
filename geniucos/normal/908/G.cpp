#include<bits/stdc++.h>

using namespace std;

int prec[11], i9, N, p10[709], dp[709][709];
char sir[709];
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

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1), N = strlen (sir + 1);
p10[0] = 1, prec[10] = 0;
for (int i=1; i<=N; i++)
    p10[i] = mul (p10[i - 1], 10), sir[i] -= '0', prec[10] = add (mul (prec[10], 10), sir[i]);///prec[10] is the number itself
i9 = power (9, mod - 2);
for (int lim = 1; lim <= 9; lim ++)
{
    for (int i=0; i<=N; i++)
        for (int j=0; j<=i; j++)
            dp[i][j] = 0;
    for (int i=0; i<sir[1]; i++)
        dp[1][i >= lim] ++;
    int currF = (sir[1] >= lim);
    for (int i=1; i<N; i++)
    {
        int curr0 = 0, curr1 = 0;
        for (int j=0; j<sir[i + 1]; j++)
            if (j < lim) curr0 ++;
            else curr1 ++;
        adto (dp[i + 1][currF], curr0);
        adto (dp[i + 1][currF + 1], curr1);
        for (int j=0; j<=i; j++)
        if (dp[i][j] > 0)
        {
            int curr = dp[i][j];
            adto (dp[i + 1][j], mul (curr, lim));
            adto (dp[i + 1][j + 1], mul (curr, 10 - lim));
        }
        currF += (sir[i + 1] >= lim);
    }
    adto (dp[N][currF], 1);
    for (int i=0; i<=N; i++)
        adto (prec[lim], mul (p10[i], dp[N][i]));
}
int ans = 0;
for (int cif = 1; cif <= 9; cif ++)
{
    int curr = subtract (prec[cif], prec[cif + 1]);
    adto (ans, mul (curr, cif));
}
ans = mul (ans, i9), ans = subtract (ans, 1);
printf ("%d\n", ans);
return 0;
}