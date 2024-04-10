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

int N, KK, dp[109][109][109][2], tr[10], compactdp[4][4][4][4][2][2][2];

void get_add (int a, int b, int c, int d)
{
    int val[10];
    pair < int, int > v[5];
    v[1].first = a, v[1].second = 1;
    v[2].first = b, v[2].second = 2;
    v[3].first = c, v[3].second = 3;
    v[4].first = d, v[4].second = 4;
    sort (v + 1, v + 5);
    val[0] = 0;
    for (int i=1; i<=4; i++)
    {
        if (i == 1 || v[i].first != v[i-1].first)
            val[i] = val[i-1] + 1;
        else
            val[i] = val[i-1];
    }
    for (int i=1; i<=4; i++)
        tr[v[i].second] = val[i];
}

void add (int a, int b, int c, int d, int vl)
{
    get_add (a, b, c, d);
    compactdp[tr[1]][tr[2]][tr[3]][tr[4]][a&1][b&1][c&1] = vl;
}

int get (int a, int b, int c, int d)
{
    get_add (a, b, c, d);
    return compactdp[tr[1]][tr[2]][tr[3]][tr[4]][a&1][b&1][c&1];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &KK);
if (N >= 20)
{
for (int K=0; K <= 60; K++)
    for (int i=0; i<=30; i++)
        for (int j=0; j<=30; j++)
        {
            if (i + j < K)
                continue;
            if (K == 0)
            {
                dp[i][j][0][j&1] = 1;
                dp[i][j][0][(j&1)^1] = 0;
                add (i, j, 0, 0, dp[i][j][K][1]);
            }
            else
            {
                //if (i == 0 && j == 2 && K == 1)
                  //  K = 1;
                for (int p=0; p<2; p++)
                {
                    dp[i][j][K][p] = 1;
                    if (i > 0 && dp[i-1][j][K-1][p^1] == 0)
                        dp[i][j][K][p] = 0;
                    if (j > 0 && dp[i][j-1][K-1][p^1] == 0)
                        dp[i][j][K][p] = 0;
                    dp[i][j][K][p] ^= 1;
                    //if (dp[i][j][K][p] && p == 1)
                      //  printf ("%d %d, %d -> %d\n", i, j, K, move[i][j][K][p]);
                }
                if (i >= 10 && j >= 10 && K >= 10)
                {
                    add (i, j, K, K/2, dp[i][j][K][1]);
                }
            }
        }
int I = 0, J = 0;
for (int i=1; i<=N; i++)
{
    int ai;
    scanf ("%d", &ai), J += (ai & 1), I += ((ai & 1) ^ 1);
}
if (get (I, J, N - KK, (N - KK)/2))
    printf ("Stannis\n");
else
    printf ("Daenerys\n");
}
else
{
    for (int K=0; K <= 60; K++)
    for (int i=0; i<=30; i++)
        for (int j=0; j<=30; j++)
        {
            if (i + j < K)
                continue;
            if (K == 0)
            {
                dp[i][j][0][j&1] = 1;
                dp[i][j][0][(j&1)^1] = 0;
            }
            else
            {
                //if (i == 0 && j == 2 && K == 1)
                  //  K = 1;
                for (int p=0; p<2; p++)
                {
                    dp[i][j][K][p] = 1;
                    if (i > 0 && dp[i-1][j][K-1][p^1] == 0)
                        dp[i][j][K][p] = 0;
                    if (j > 0 && dp[i][j-1][K-1][p^1] == 0)
                        dp[i][j][K][p] = 0;
                    dp[i][j][K][p] ^= 1;
                    //if (dp[i][j][K][p] && p == 1)
                      //  printf ("%d %d, %d -> %d\n", i, j, K, move[i][j][K][p]);
                }
            }
        }
int I = 0, J = 0;
for (int i=1; i<=N; i++)
{
    int ai;
    scanf ("%d", &ai), J += (ai & 1), I += ((ai & 1) ^ 1);
}
if (dp[I][J][N - KK][1])
    printf ("Stannis\n");
else
    printf ("Daenerys\n");
}
return 0;
}