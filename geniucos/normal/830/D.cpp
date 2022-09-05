#include<bits/stdc++.h>

using namespace std;

int N, dp[409][809];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int main ()
{
scanf ("%d", &N);
dp[1][1] = dp[1][0] = 1;
for (int k=1; k<N; k++)
{
    for (int i=0; i<=N - k + 1; i++)
        for (int j=0; j<=N - k + 1; j++)
        if (dp[k][i] && dp[k][j])
        {
            int curr = mul (dp[k][i], dp[k][j]);
            adto (dp[k + 1][i + j], mul (2 * (i + j) + 1, curr));
            adto (dp[k + 1][i + j + 1], curr);
            if (i + j > 1) adto (dp[k + 1][i + j - 1], mul ((i + j) * (i + j - 1), curr));
        }
}
printf ("%d\n", dp[N][1]);
return 0;
}