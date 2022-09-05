#include<bits/stdc++.h>

using namespace std;

int N, M, ans[2018], deg[2018], specialC[2018];
bitset < 2018 > gs[2018];
vector < int > v[2018];

int main ()
{
//freopen ("input", "r", stdin);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    for (int i=1; i<=N; i++)
        deg[i] = 0;
    for (int i=1; i<=N; i++)
        v[i].clear ();
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=M; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        deg[x] ++, deg[y] ++;
        v[x].push_back (y), v[y].push_back (x);
    }
    bool failed = 0;
    for (int i=1; i<=N; i++)
        if (deg[i] & 1)
        {
            failed = 1;
            break;
        }
    if (!failed)
    {
        printf ("1\n");
        for (int i=1; i<=N; i++)
            printf ("1%c", " \n"[i == N]);
        continue;
    }
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N + 1; j++)
            gs[i][j] = 0;
        for (auto j: v[i])
            gs[i][j] = gs[i][j] ^ 1;
        if (deg[i] & 1)
            gs[i][i] = gs[i][N + 1] = 1;
    }
    for (int i=1; i<=N; i++)
    {
        int p = -1;
        for (int j=1; j<=N + 1; j++)
            if (gs[i][j] == 1)
            {
                p = j;
                break;
            }
        if (p == N + 1)
            assert (0);
        specialC[i] = p;
        if (p == -1) continue;
        for (int j=1; j<=N; j++)
            if (j != i && gs[j][p])
                gs[j] ^= gs[i];
    }
    for (int i=1; i<=N; i++)
        ans[i] = 0;
    for (int i=1; i<=N; i++)
        if (specialC[i] != -1)
            ans[specialC[i]] = gs[i][N + 1];
    printf ("2\n");
    for (int i=1; i<=N; i++)
        printf ("%d%c", ans[i] + 1, " \n"[i == N]);
}
return 0;
}