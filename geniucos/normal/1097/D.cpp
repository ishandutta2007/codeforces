#include<bits/stdc++.h>

using namespace std;

int K, dp[10009][109];
long long X;
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

int inv[100009], ans = 1;

void addPE (int p, int e)
{
    dp[0][0] = 1;
    for (int i=1; i<=e; i++)
        dp[0][i] = mul (dp[0][i - 1], p);
    for (int i=1; i<=K; i++)
    {
        int sum = 0;
        for (int j=0; j<=e; j++)
        {
            adto (sum, dp[i - 1][j]);
            dp[i][j] = mul (sum, inv[j + 1]);
        }
    }
    ans = mul (ans, dp[K][e]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %d", &X, &K);
for (int i=1; i<=500; i++)
    inv[i] = power (i, mod - 2);
for (int p=2; 1LL * p * p <= X; p++)
    if (X % p == 0)
    {
        int e = 0;
        while (X % p == 0)
            X /= p, e ++;
        addPE (p, e);
    }
if (X > 1)
    addPE (X % mod, 1);
printf ("%d\n", ans);
return 0;
}