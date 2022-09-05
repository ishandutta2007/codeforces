#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int a, b, c, L;
long long dp[5][400009], sum[5][400009];

int mod (int x)
{
    if (x < 0) return -x;
    return x;
}

long long solveAegalBmaimicC (int a, int b, int c, int L)
{
    ////a + x = b + y < c + z
    ////x + y + z <= L
    long long sol = 0;
    for (int i=0; i<=L; i++)
    {
        if (c + i <= a || c + i <= b) continue;
        int limjk = min (c + i - a - b, L - i);
        if (limjk < 0) continue;
        sol += sum[2][limjk];
    }
    return sol;
}

/*long long solveAmaimicBmaimicC (int a, int b, int c, int L)
{
    long long sol = 0;
    for (int i=0; i<=L; i++)
    {
        if (b + i <= a) continue;
        int limj = b + i - a - 1, limk = max (0, b + i - c + 1);
        int nouL = L - i - limk;
        limk = 0;
        limj = min (limj, nouL);
        if (limj < 0) continue;
        sol += limj;
    }
    return sol;
}*/

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &a, &b, &c, &L);
dp[0][0] = 1LL;
for (int j=0; j<=L; j++)
    sum[0][j] = 1LL;
for (int i=1; i<=3; i++)
    for (int j=0; j<=L; j++)
    {
        dp[i][j] = sum[i-1][j];
        if (j == 0) sum[i][j] = dp[i][j];
        else sum[i][j] = sum[i][j-1] + dp[i][j];
    }
long long sub0 = solveAegalBmaimicC (a, b, c, L);
sub0 += solveAegalBmaimicC (b, c, a, L);
sub0 += solveAegalBmaimicC (c, a, b, L);
/*sub0 += solveAmaimicBmaimicC (a, b, c, L);
sub0 += solveAmaimicBmaimicC (a, c, b, L);
sub0 += solveAmaimicBmaimicC (b, a, c, L);
sub0 += solveAmaimicBmaimicC (b, c, a, L);
sub0 += solveAmaimicBmaimicC (c, a, b, L);
sub0 += solveAmaimicBmaimicC (c, b, a, L);*/
printf ("%I64d\n", (long long)sum[3][L] - sub0);

return 0;
}