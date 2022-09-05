#include<bits/stdc++.h>

using namespace std;

int dp[2][2][2], oldDp[2][2][2], cnt[2][2][2], oldCnt[2][2][2];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int solve (int n, int m, int K)
{
    if (n < 0 || m < 0) return 0;
    n ++, m ++;///I want them to be strictly smaller now, strictly smaller than K too
    memset (dp, 0, sizeof (dp));
    memset (cnt, 0, sizeof (cnt));
    cnt[0][0][(K >> 30) & 1] = 1;
    for (int p=29; p>=0; p--)
    {
        int bN = (n >> p) & 1, bM = (m >> p) & 1, bK = (K >> p) & 1;
        memcpy (oldCnt, cnt, sizeof (cnt));
        memcpy (oldDp, dp, sizeof (dp));
        memset (dp, 0, sizeof (dp));
        memset (cnt, 0, sizeof (cnt));
        for (int i=0; i<2; i++)
            for (int j=0; j<2; j++)
                for (int k=0; k<2; k++)
                    if (oldCnt[i][j][k])
                        for (int b1 = 0; b1<2; b1++)
                            for (int b2 = 0; b2 < 2; b2++)
                            {
                                if (b1 > bN && i == 0) continue;
                                if (b2 > bM && j == 0) continue;
                                if ((b1 ^ b2) > bK && k == 0) continue;
                                int ni = i | (b1 < bN), nj = j | (b2 < bM), nk = k | ((b1 ^ b2) < bK);
                                adto (cnt[ni][nj][nk], oldCnt[i][j][k]);
                                if (b1 ^ b2) adto (dp[ni][nj][nk], add (oldDp[i][j][k], mul (oldCnt[i][j][k], 1 << p)));
                                else adto (dp[ni][nj][nk], oldDp[i][j][k]);
                            }
    }
    return add (dp[1][1][1], cnt[1][1][1]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int Tests;
scanf ("%d", &Tests);
while (Tests --)
{
    int a1, b1, a2, b2, k;
    scanf ("%d %d %d %d %d", &a1, &b1, &a2, &b2, &k), a1 --, b1 --, a2 --, b2 --;
    int ans = subtract (add (solve (a2, b2, k), solve (a1 - 1, b1 - 1, k)), add (solve (a1 - 1, b2, k), solve (a2, b1 - 1, k)));
    printf ("%d\n", ans);
}
return 0;
}