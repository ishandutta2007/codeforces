#include<bits/stdc++.h>

using namespace std;

int K, pa, pb, dp[2017][2017][2];
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

scanf ("%d %d %d", &K, &pa, &pb);
int invAll = power (pa + pb, mod - 2);
pa = mul (pa, invAll), pb = mul (pb, invAll);
int E = mul (pa, power (pb, mod - 2));
dp[0][1][0] = 1;///pot presupune ca primu e a ca b-urile de la inceput nu conteaza
///ab-uri, a-uri, ultimu (0=a)
for (int i=0; i<K; i++)
    for (int j=0; j<K; j++)
        for (int k=0; k<2; k++)
        if (dp[i][j][k] > 0)
        {
            int curr = dp[i][j][k];
            adto (dp[i][j + 1][0], mul (curr, pa));
            adto (dp[i + j][j][1], mul (curr, pb));
        }
int ans = 0;
for (int i=K; i<=2 * K; i++)
    for (int j=0; j<K; j++)
        adto (ans, mul (i, dp[i][j][1]));
for (int i=0; i<K; i++)
if (dp[i][K][0])
{
    int curr = dp[i][K][0];
    adto (ans, mul (curr, add (E, i + K)));
}
printf ("%d\n", ans);
return 0;
}