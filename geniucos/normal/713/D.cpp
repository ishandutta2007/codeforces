#include<bits/stdc++.h>

using namespace std;

int N, M, Q, lg[1009];
char sir[3009];
short dp[1002][1002][10][10];

int get_ma (int a1, int b1, int a2, int b2)
{
    int p = lg[a2 - a1 + 1], q = lg[b2 - b1 + 1], x = a2 - (1 << p) + 1, y = b2 - (1 << q) + 1;
    return max (dp[a1][b1][p][q], max (dp[a1][y][p][q], max (dp[x][b1][p][q], dp[x][y][p][q])));
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
{
    gets (sir + 1);
    for (int j=1; j<=M; j++)
    {
        bool curr = sir[2 * j - 1] - '0';
        if (curr) dp[i][j][0][0] = 1 + min (dp[i - 1][j][0][0], min (dp[i - 1][j - 1][0][0], dp[i][j - 1][0][0]));
        else dp[i][j][0][0] = 0;
    }
}
for (int i=2; i<=N || i<=M; i++)
    lg[i] = lg[i >> 1] + 1;
for (int i=0; (1 << i) <= N; i++)
    for (int j=0; (1 << j) <= M; j++)
        if (i + j > 0)
        {
            if (i > 0)
            {
                for (int x=1; x + (1 << i) - 1 <= N; x ++)
                    for (int y=1; y + (1 << j) - 1 <= M; y++)
                        dp[x][y][i][j] = max (dp[x][y][i - 1][j], dp[x + (1 << (i - 1))][y][i - 1][j]);
            }
            else
            {
                for (int x=1; x + (1 << i) - 1 <= N; x ++)
                    for (int y=1; y + (1 << j) - 1 <= M; y++)
                        dp[x][y][i][j] = max (dp[x][y][i][j - 1], dp[x][y + (1 << (j - 1))][i][j - 1]);
            }
        }
scanf ("%d", &Q);
while (Q --)
{
    int a1, b1, a2, b2, p = 1, u, ras = 0;
    scanf ("%d %d %d %d", &a1, &b1, &a2, &b2), u = min (a2 - a1 + 1, b2 - b1 + 1);
    while (p <= u)
    {
        int mij = (p + u) >> 1;
        if (get_ma (a1 + mij - 1, b1 + mij - 1, a2, b2) >= mij) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    printf ("%d\n", ras);
}
return 0;
}