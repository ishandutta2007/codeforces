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

int POT, N, K, x[109], y[109], L[109], R[109], tip[109], dp[109][109], how[109][109];
char sir[109];

int in (int st, int dr, int val)
{
    if (val >= st && val <= dr) return 1;
    return 0;
}

void afis (int st, int dr)
{
    if (st > dr)
        return;
    if (st != dr)
        afis (st+1, how[st][dr] - 1);
    printf ("%d ", st);
    if (st != dr)
        afis (how[st][dr], dr);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &K);
for (int i=1; i<=K; i++)
{
    scanf ("%d %d %s\n", &x[i], &y[i], sir + 1);
    if (sir[1] == 'L') tip[i] = 0;
    else tip[i] = 1;
    if (x[i] == y[i])
    {
        printf ("IMPOSSIBLE\n");
        return 0;
    }
}

POT = 1;

dp[N+1][N] = 1;
for (int st=N; st>=1; st--)
{
    dp[st][st] = 1;
    dp[st][st-1] = 1;
    for (int dr = st + 1; dr<=N; dr++)
    {
        for (int X=st+1; X<=dr+1; X++)
        {
            if (dp[st+1][X-1] && dp[X][dr]) ;
            else continue;
            bool ok = 1;
            for (int i=1; i<=K; i++)
            if (in(st, dr, x[i]) && in(st, dr, y[i]))
            {
                if (x[i] == st && y[i] != x[i])
                {
                    if (y[i] < X && tip[i] == 1)
                    {
                        ok = 0;
                        break;
                    }
                    if (y[i] >= X && tip[i] == 0)
                    {
                        ok = 0;
                        break;
                    }
                }
                if (y[i] == st && x[i] != y[i])
                {
                    ok = 0;
                    break;
                }
                if (x[i] != st && y[i] != st)
                {
                    if (x[i] < X && y[i] >= X)
                    {
                        ok = 0;
                        break;
                    }
                    if (x[i] >= X && y[i] < X)
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok)
            {
                dp[st][dr] = 1;
                how[st][dr] = X;
                break;
            }
        }
    }
}

if (dp[1][N] == 0)
{
    printf ("IMPOSSIBLE\n");
    return 0;
}

afis (1, N);

return 0;
}