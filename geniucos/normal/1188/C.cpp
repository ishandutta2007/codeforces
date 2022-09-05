#include<bits/stdc++.h>

using namespace std;

int N, K, s[1009], dp[1009], a[1009];
const int mod = 998244353;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1);
int ans = 0;
for (int minVal = 1; minVal <= (a[N] - a[1]) / (K - 1); minVal ++)
{
    for (int i=1; i<=N - K + 1; i++)
        dp[i] = 1;
    for (int i=2; i<=K; i++)
    {
        for (int i=1; i<=N; i++)
            s[i] = add (s[i - 1], dp[i]);
        int j = 0;
        for (int i=1; i<=N; i++)
        {
            while (a[i] - a[j + 1] >= minVal)
                j ++;
            dp[i] = s[j];
        }
    }
    for (int i=1; i<=N; i++)
        adto (ans, dp[i]);
}
printf ("%d\n", ans);
return 0;
}