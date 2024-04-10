#include<bits/stdc++.h>

using namespace std;

int N, mod;
long long a[100009];

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

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), mod = 1e9 + 7;
bool even = 0;
for (int i=1; i<=N; i++)
{
    scanf ("%I64d", &a[i]);
    if (a[i] % 2 == 0) even = 1;
}
int E = 1;
for (int i=1; i<=N; i++)
    a[i] = a[i] % (mod - 1), E = (1LL * E * a[i]) % (mod - 1);
E --;
if (E < 0) E += mod - 1;
int n2_1 = pow (2, E), q, p;
q = n2_1, p = q;
if (!even)
{
    p --;
    if (p < 0) p += mod;
}
else
{
    p ++;
    if (p == mod) p = 0;
}
p = (1LL * p * pow (3, mod - 2)) % mod;
printf ("%d/%d\n", p, q);
return 0;


/*int N;
double dp[1000][4];
N = 10;
dp[0][2] = 1.0, dp[0][3] = dp[0][1] = 0.0;
for (int i=1; i<=N; i++)
{
    dp[i][1] = 0.5 * dp[i - 1][2] + 0.5 * dp[i - 1][1];
    dp[i][3] = 0.5 * dp[i - 1][2] + 0.5 * dp[i - 1][3];
    dp[i][2] = 0.5 * dp[i - 1][1] + 0.5 * dp[i - 1][3];
    printf ("%.5f %.5f %.5f\n", dp[i][1], dp[i][2], dp[i][3]);
}*/
return 0;
}