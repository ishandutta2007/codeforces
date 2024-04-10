#include<cstdio>
#include<bitset>
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

int maxl;
long long S, Xo, dp[100][3], bitX[100], bitS[100];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %I64d", &S, &Xo);
if (Xo > S)
{
    printf ("0\n");
    return 0;
}
for (int i=0; (1LL << i) <= S; i++) maxl = i;
for (int i=maxl; i>=0; i--)
    bitS[i + 1] = (S >> i) & 1, bitX[i + 1] = (Xo >> i) & 1;
dp[0][0] = 1;
for (int i=0; i<maxl + 1; i++)
    for (int j=0; j<2; j++)
        for (int k=0; k<2; k++)
            for (int p=0; p<2; p++)
                if ((k ^ p) == bitX[i + 1] && (j + k + p) % 2 == bitS[i + 1])
                    dp[i + 1][(j + k + p) / 2] += dp[i][j];
long long ans = dp[maxl + 1][0];
///0 val -> val = S
if (S == Xo) ans -= 2;
printf ("%I64d\n", ans);
return 0;
}