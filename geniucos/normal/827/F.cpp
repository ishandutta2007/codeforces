#include<bits/stdc++.h>

using namespace std;

int N, M, dist[1000009][2], x[1000009], y[1000009], a[1000009], b[1000009];
set < pair < int, int > > s[1000009][2];
priority_queue < pair < int, pair < int, int > > > PQ;

void fixVal (int i, int parity, int d)
{
    dist[i][parity] = d;
    PQ.push ({-d, {i, parity}});
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
if (M == 0)
{
    printf ("%d\n", -1 + (N == 1));
    return 0;
}
for (int i=1; i<=M; i++)
    scanf ("%d %d %d %d", &x[i], &y[i], &a[i], &b[i]),
    x[M + i] = y[i], y[M + i] = x[i], a[M + i] = a[i], b[M + i] = b[i];
for (int i=1; i<=2 * M; i++)
    dist[i][0] = dist[i][1] = -1;
for (int i=1; i<=2 * M; i++)
{
    if (x[i] == 1 && a[i] == 0)
        dist[i][0] = 0, PQ.push ({0, {i, 0}});
    else
    {
        s[x[i]][0].insert ({a[i] + (a[i] % 2 == 1), i});
        s[x[i]][1].insert ({a[i] + (a[i] % 2 == 0), i});
    }
}
while (!PQ.empty ())
{
    pair < int, pair < int, int > > curr = PQ.top ();
    PQ.pop ();
    int i = curr.second.first, T = -curr.first, parity = curr.second.second, lastT;
    lastT = b[i] - 1;
    if (lastT % 2 != parity) lastT --;
    if (T > lastT) continue;
    while (!s[y[i]][parity ^ 1].empty ())
    {
        auto edge = *s[y[i]][parity ^ 1].begin ();
        if (a[edge.second] <= T + 1) fixVal (edge.second, parity ^ 1, T + 1);
        else
        if (a[edge.second] <= lastT + 1) fixVal (edge.second, parity ^ 1, edge.first);
        else break;
        s[y[i]][parity ^ 1].erase (s[y[i]][parity ^ 1].begin ());
    }
}
int ans = -1;
for (int i=1; i<=2 * M; i++)
    for (int j=0; j<2; j++)
        if (x[i] == N && dist[i][j] != -1 && (dist[i][j] < ans || ans == -1))
            ans = dist[i][j];
printf ("%d\n", ans);
return 0;
}