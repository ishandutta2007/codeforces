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

int N, T, K, dp[4][109];
char mat[5][1009];

bool pot (int i, int j)
{
    return (mat[i][j * 3 - 2] == '.' && mat[i][j * 3 - 4] == '.');
}

bool pot2 (int i, int j)
{
    return (mat[i][j * 3 - 4] == '.');
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T);
while (T --)
{
    scanf ("%d %d\n", &N, &K);
    for (int i=1; i<=3; i++)
    {
        gets (mat[i] + 1);
        for (int j=N + 1; j<=3 * N; j++)
            mat[i][j] = '.';
    }

    for (int i=1; i<=3; i++)
        if (mat[i][1] == 's') dp[i][1] = 1;
        else dp[i][1] = 0;

    for (int j=1; j<N; j++)
        for (int i=1; i<=3; i++)
        if (dp[i][j])
        {
            for (int d=-1; d<=1; d++)
                if (i + d >= 1 && i + d <= 3 && pot (i + d, j + 1) && pot2 (i, j + 1))
                    dp[i + d][j + 1] = 1;
        }

    if (dp[1][N] || dp[2][N] || dp[3][N]) printf ("YES\n");
    else printf ("NO\n");

    for (int i=1; i<=3; i++)
        for (int j=1; j<=N; j++)
            dp[i][j] = 0;
}

return 0;
}