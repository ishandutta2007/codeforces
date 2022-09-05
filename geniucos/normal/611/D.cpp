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

int N, mod, lcp[5009][5009], dp[5009][5009];
char sir[5009];

bool cmp (int x, int y, int a, int b)
{
    ///[x, y] < [a, b] ?
    ///[x, y] may not exist
/*    x = first[x];
    if (x == 0 || x > y) return 1;*/
    if (b - a + 1 > y - x + 1) return 1;
    if (b - a + 1 < y - x + 1) return 0;
    int com = lcp[x][a];
    if (com >= b - a + 1) return 0;///sunt egale
    return (sir[x + com] < sir[a + com]);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N), mod = 1e9 + 7;
gets (sir + 1);
for (int i=N; i>=1; i--)
    for (int j=N; j>=1; j--)
    {
        if (sir[i] != sir[j]) lcp[i][j] = 0;
        else lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }

/*for (int i=1; i<=N; i++)
    non0[i] = non0[i - 1] + (sir[i] != '0');
for (int i=1; i<=N; i++)
    if (sir[i] != '0') first[i] = i;
    else first[i] = first[i + 1];*/
for (int i=1; i<=N; i++)
    dp[1][i] = 1;
for (int i=2; i<=N; i++)
    if (sir[i] != '0')
    {
        int p = i - 1, curr = 0;
        for (int j=i; j<=N; j++)
        {
            ///vreau dp[i][j]
            while (cmp (p, i - 1, i, j) && p >= 1)
            {
                curr += dp[p][i - 1];
                if (curr >= mod) curr -= mod;
                p --;
            }
            dp[i][j] = curr;
        }
    }

int sol = 0;
for (int i=1; i<=N; i++)
{
    sol += dp[i][N];
    if (sol >= mod) sol -= mod;
}
printf ("%d\n", sol);

return 0;
}