#include<bits/stdc++.h>

using namespace std;

int N = 30, Lim, bit[40], dp[40][40][2];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &Lim);
for (int i=0; i<N; i++)
    bit[i] = (Lim >> i) & 1;
dp[N][0][0] = 1;
for (int i=N; i>0; i--)
    for (int j=0; j<=N - i; j++)
        for (int k=0; k<2; k++)
            if (dp[i][j][k] > 0)
            {
                for (int p=0; p<2; p++)
                if (k == 1 || p <= bit[i - 1])
                {
                    if (j > 0) adto (dp[i - 1][j][k | (p < bit[i - 1])], mul (dp[i][j][k], 1 << (j - 1)));
                    else
                    if (p == 0) adto (dp[i - 1][j][k | (p < bit[i - 1])], dp[i][j][k]);
                    if (p == 1)
                        adto (dp[i - 1][j + 1][k], dp[i][j][k]);
                }
            }
int ans = 0;
for (int i=0; i<=N; i++)
    for (int j=0; j<2; j++)
        adto (ans, dp[0][i][j]);
printf ("%d\n", ans);
return 0;
}