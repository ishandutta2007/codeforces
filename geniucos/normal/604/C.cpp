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

int N, dp[100009][2][3], A[100009];
char sir[100009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
gets (sir + 1);
for (int i=1; i<=N; i++)
    A[i] = sir[i] - '0';
///A[i][j][k] = din primele i, lungimea maxima a unui subsir alternant care se temrina in valoarea j, k fiind stadiul(0 inseamna ca n-am facut niciun swap,
///1 reprezinta ca sunt in interiorul secventei swapuite, 2 ca am facut deja odata swap
for (int i=1; i<=N; i++)
    for (int j=0; j<=1; j++)
    {
        dp[i][j][0] = dp[i - 1][j][0];
        if (j == A[i]) dp[i][j][0] = max (dp[i][j][0], dp[i - 1][j ^ 1][0] + 1);
        dp[i][j][2] = max (dp[i - 1][j][2], dp[i - 1][j][1]);
        if (j == A[i]) dp[i][j][2] = max (dp[i][j][2], max (dp[i - 1][j ^ 1][2], dp[i - 1][j ^ 1][1]) + 1);
        dp[i][j][1] = max (dp[i - 1][j][1], dp[i - 1][j][0]);
        if ((j ^ 1) == A[i]) dp[i][j][1] = max (dp[i][j][1], max (dp[i - 1][j ^ 1][0], dp[i - 1][j ^ 1][1]) + 1);
    }
int ans = 0;
for (int j=0; j<=1; j++)
    for (int k=0; k<3; k++)
        if (dp[N][j][k] > ans) ans = dp[N][j][k];
printf ("%d\n", ans);
return 0;
}