#include<bits/stdc++.h>

using namespace std;

int N, K, dp[1009][1009];
char sir[1009];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int f (int val)
{
    int cnt = 0;
    while (val > 0)
        cnt ++, val &= val - 1;
    return cnt;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1), N = strlen (sir + 1);
scanf ("%d", &K);
int curr = 0;
for (int i=0; i<N; i++)
{
    int t = sir[i + 1] - '0';
    if (t == 1) adto (dp[i + 1][curr], +1);
    for (int j=0; j<=i; j++)
        if (dp[i][j] > 0)
        {
            for (int k=0; k<2; k++)
                adto (dp[i + 1][j + k], dp[i][j]);
        }
    curr += t;
}
dp[N][curr] ++;
int sum = 0;
if (K == 0)
{
    printf ("1\n");
    return 0;
}
for (int i=1; i<=N; i++)
{
    int j = i, ans = 1;
    while (j != 1)
        j = f (j), ans ++;
    if (ans == K)
        adto (sum, dp[N][i]);
}
if (K == 1) sum = subtract (sum, 1);
printf ("%d\n", sum);
return 0;
}