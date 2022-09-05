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

int N, M, nr, x[3000], y[3000], lcp1[2109][2109], lcp2[2109][2109];
char A[2109], B[2109];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (A + 1), N = strlen (A + 1);
gets (B + 1), M = strlen (B + 1);
for (int i=N; i>=1; i--)
    for (int j=M; j>=1; j--)
    {
        if (A[i] != B[j]) lcp1[i][j] = 0;
        else lcp1[i][j] = lcp1[i + 1][j + 1] + 1;
    }
for (int i=1; i<=N; i++)
    for (int j=M; j>=1; j--)
    {
        if (A[i] != B[j]) lcp2[i][j] = 0;
        else lcp2[i][j] = lcp2[i - 1][j + 1] + 1;
    }
int i = 1, nr = 0;
while (1)
{
    int maxi = 0, how;
    for (int j=1; j<=N; j++)
        if (lcp1[j][i] > maxi) maxi = lcp1[j][i], how = j;
    for (int j=1; j<=N; j++)
        if (lcp2[j][i] > maxi) maxi = lcp2[j][i], how = -j;
    if (maxi == 0)
    {
        printf ("-1\n");
        return 0;
    }
    nr ++;
    if (how > 0) x[nr] = how, y[nr] = how + maxi - 1;
    else x[nr] = -how, y[nr] = -how - maxi + 1;
    i += maxi;
    if (i > M) break;
}
printf ("%d\n", nr);
for (int i=1; i<=nr; i++)
    printf ("%d %d\n", x[i], y[i]);
return 0;
}