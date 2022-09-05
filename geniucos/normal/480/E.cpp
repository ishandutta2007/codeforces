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

int maxi, N, M, K, up[2015][2015], down[2015][2015], dp[2015][2015], x[2015], y[2015], ans[2015];
char sir[2015][2015];

deque < int > dq1, dq2;

void scoate (int x, int y)
{
    sir[x][y] = '.';
    for (int i=1; i<=N; i++)
    {
        if (sir[i][y] == '.') up[i][y] = up[i-1][y] + 1;
        else up[i][y] = 0;
    }
    for (int i=N; i>=1; i--)
    {
        if (sir[i][y] == '.') down[i][y] = down[i+1][y] + 1;
        else down[i][y] = 0;
    }
}
bool ok (int x, int L)
{
    if (L > N || L > M)
        return 0;
    dq1.clear (), dq2.clear ();
    for (int i=1; i<=M; i++)
    {
        while (!dq1.empty () && up[x][dq1.back ()] >= up[x][i]) dq1.pop_back ();
        dq1.push_back (i);
        if (dq1.front () <= i - L) dq1.pop_front ();

        while (!dq2.empty () && down[x][dq2.back ()] >= down[x][i]) dq2.pop_back ();
        dq2.push_back (i);
        if (dq2.front () <= i - L) dq2.pop_front ();

        int a = dq1.front (), b = dq2.front ();
        if (i >= L && up[x][dq1.front ()] + down[x][dq2.front ()] - 1 >= L)
            return 1;
    }
    return 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d\n", &N, &M, &K);
for (int i=1; i<=N; i++)
    gets (sir[i] + 1);
for (int i=1; i<=K; i++)
    scanf ("%d %d", &x[i], &y[i]), sir[x[i]][y[i]] = 'X';

for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
    {
        if (sir[i][j] == '.') up[i][j] = up[i-1][j] + 1;
        else up[i][j] = 0;
    }

for (int i=N; i>=1; i--)
    for (int j=1; j<=M; j++)
    {
        if (sir[i][j] == '.') down[i][j] = down[i+1][j] + 1;
        else down[i][j] = 0;
    }

for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
    {
        if (sir[i][j] == 'X') dp[i][j] = 0;
        else dp[i][j] = min (min (dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
        if (dp[i][j] > maxi)
            maxi = dp[i][j];
    }

ans[K] = maxi;
for (int i=K; i>=1; i--)
{
    scoate (x[i], y[i]);
    while (ok (x[i], maxi + 1))
        maxi ++;
    ans[i-1] = maxi;
}

for (int i=1; i<=K; i++)
    printf ("%d\n", ans[i]);

return 0;
}