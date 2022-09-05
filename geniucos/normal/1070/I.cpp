#include<bits/stdc++.h>

using namespace std;

int N, M, K, Source, Destination, t[2018], f[2018][2018], c[2018][2018], x[2018], y[2018], deg[2018], ans[2018];
vector < int > v[2018];

void addEdge (int x, int y, int cc)
{
    c[x][y] = cc;
    v[x].push_back (y);
    v[y].push_back (x);
}

bool bfs ()
{
    for (int i=1; i<=Destination; i++)
        t[i] = -1;
    t[Source] = 0;
    queue < int > cc;
    cc.push (Source);
    while (!cc.empty ())
    {
        int nod = cc.front ();
        cc.pop ();
        for (auto it : v[nod])
            if (f[nod][it] < c[nod][it] && t[it] == -1)
            {
                t[it] = nod;
                cc.push (it);
                if (it == Destination) return 1;
            }
    }
    return 0;
}

int maxFlow ()
{
    int ans = 0;
    while (bfs ())
    {
        for (auto j : v[Destination])
            if (t[j] != -1 && f[j][Destination] < c[j][Destination])
            {
                int curr = 1e9; t[Destination] = j;
                for (int i=Destination; i != Source; i = t[i])
                    curr = min (curr, c[t[i]][i] - f[t[i]][i]);
                for (int i=Destination; i != Source; i = t[i])
                    f[t[i]][i] += curr,
                    f[i][t[i]] -= curr;
                ans += curr;
            }
    }
    return ans;
}

int main ()
{
//freopen("I.in", "r", stdin);
//freopen("I.out", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    ///read
    int N, M;
    scanf ("%d %d %d", &N, &M, &K);
    for (int i=1; i<=M; i++)
        scanf ("%d %d", &x[i], &y[i]), deg[x[i]] ++, deg[y[i]] ++;
    Source = N + M + 1, Destination = N + M + 2;
    ///build
    int targetedFlow = 0;
    for (int i=1; i<=N; i++)
        addEdge (Source, i, max (0, 2 * (deg[i] - K))),
        targetedFlow += max (0, 2 * (deg[i] - K));
    for (int i=N + 1; i<=N + M; i++)
        addEdge (i, Destination, 1),
        addEdge (x[i - N], i, 1),
        addEdge (y[i - N], i, 1);
    ///finish
    if (maxFlow () != targetedFlow)
    {
        for (int i=1; i<=M; i++)
            printf ("0%c", " \n"[i == M]);
    }
    else
    {
        for (int i=1; i<=M; i++)
            ans[i] = i;
        for (int i=1; i<=N; i++)
        {
            vector < int > pr;
            for (auto j : v[i])
                if (f[i][j] > 0 && j > N && j <= N + M)
                    pr.push_back (j - N);
            for (int j=1; j<pr.size (); j+=2)
                ans[pr[j]] = ans[pr[j - 1]];
        }
        for (int i=1; i<=M; i++)
            printf ("%d%c", ans[i], " \n"[i == M]);
    }
    ///clear
    for (int i=1; i<=Destination; i++)
    {
        for (auto j : v[i])
            f[i][j] = c[i][j] = 0;
        v[i].clear (), deg[i] = 0;
    }
}

return 0;
}