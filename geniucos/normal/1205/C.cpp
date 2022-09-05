#include<bits/stdc++.h>

using namespace std;

int N, ans[2][53][53], r[53][53], fin[53][53], dp[2][53][53][53][53];

int query (int x1, int y1, int x2, int y2)
{
    printf ("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush (stdout);
    int ans;
    scanf ("%d", &ans);
    return ans;
}

void print (int fin[53][53])
{
    printf ("!\n");
    for (int i=1; i<=N; i++, printf ("\n"))
        for (int j=1; j<=N; j++)
            printf ("%d", fin[i][j]);
    fflush (stdout);
    exit (0);
}

void buildDp (int lin, int v[53][53])
{
    for (int i1=N; i1>=1; i1--)
        for (int j1=N; j1>=1; j1--)
            for (int i2=i1; i2<=N; i2++)
                for (int j2=j1; j2<=N; j2++)
                {
                    int &curr = dp[lin][i1][j1][i2][j2];
                    if (i1 + j1 == i2 + j2) curr = 1;
                    else
                    if (i1 + j1 == i2 + j2 - 1) curr = (v[i1][j1] == v[i2][j2]);
                    else
                    {
                        curr = 0;
                        if (v[i1][j1] == v[i2][j2])
                        {
                            curr |= dp[lin][i1][j1 + 1][i2][j2 - 1];
                            curr |= dp[lin][i1 + 1][j1][i2][j2 - 1];
                            curr |= dp[lin][i1][j1 + 1][i2 - 1][j2];
                            curr |= dp[lin][i1 + 1][j1][i2 - 1][j2];
                        }
                    }
                }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        ans[0][i][j] = ans[1][i][j] = -1;
ans[0][1][1] = 1, ans[0][N][N] = 0;
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        if ((i + j) % 2 == 0 && i + j > 2 && i + j < 2 * N)
        {
            int x = i, y = j - 2;
            if (j <= 2)
            {
                if (i <= 2) x = y = 1;
                else x = i - 2, y = j;
            }
            int v = query (x, y, i, j);
            if (v) ans[0][i][j] = ans[0][x][y];
            else ans[0][i][j] = ans[0][x][y] ^ 1;
        }
r[1][2] = 0;
r[2][3] = query (1, 2, 2, 3) ^ 1;
r[2][1] = query (2, 1, 2, 3) ^ r[2][3] ^ 1;
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        if ((i + j) % 2 == 1 && i + j > 3 && (i != 2 || j != 3))
        {
            int x = i, y = j - 2;
            if (j <= 2) x = i - 2, y = j;
            int v = query (x, y, i, j);
            if (v) r[i][j] = r[x][y];
            else r[i][j] = r[x][y] ^ 1;
        }
for (int x=0; x<2; x++)
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if ((i + j) & 1) ans[x][i][j] = r[i][j] ^ x;
            else
            if (x == 1) ans[x][i][j] = ans[x - 1][i][j];
buildDp (0, ans[0]), buildDp (1, ans[1]);
for (int i1=N; i1>=1; i1--)
    for (int j1=N; j1>=1; j1--)
        for (int i2=i1; i2<=N; i2++)
            for (int j2=j1; j2<=N; j2++)
                if (i1 + j1 + 2 <= i2 + j2 && dp[0][i1][j1][i2][j2] != dp[1][i1][j1][i2][j2])
                {
                    int curr = query (i1, j1, i2, j2);
                    if (curr == dp[0][i1][j1][i2][j2]) print (ans[0]);
                    else print (ans[1]);
                }
return 0;
}