#include<bits/stdc++.h>

using namespace std;

int N, M, Q, nr, val[109][109], ans[10009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &Q);
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        val[i][j] = ++nr;
while (Q --)
{
    int type;
    scanf ("%d", &type);
    if (type == 1)
    {
        int i;
        scanf ("%d", &i);
        val[i][M + 1] = val[i][1];
        for (int j=1; j<=M; j++)
            val[i][j] = val[i][j + 1];
        val[i][M + 1] = 0;
        continue;
    }
    if (type == 2)
    {
        int j;
        scanf ("%d", &j);
        val[N + 1][j] = val[1][j];
        for (int i=1; i<=N; i++)
            val[i][j] = val[i + 1][j];
        val[N + 1][j] = 0;
        continue;
    }
    int x, y, v;
    scanf ("%d %d %d", &x, &y, &v);
    ans[val[x][y]] = v;
}
nr = 0;
for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=M; j++)
        printf ("%d ", ans[++nr]);
return 0;
}