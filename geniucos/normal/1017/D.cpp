#include<bits/stdc++.h>

using namespace std;

int N, M, Q, ans[500009], cost[10000], w[100], mars[1009], ap[10000];
char sir[100];
vector < pair < int, int > > qr[10000];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &Q);
for (int i=0; i<N; i++)
    scanf ("%d", &w[i]);
scanf ("\n");
while (M --)
{
    scanf ("%s\n", sir);
    int msk = 0;
    for (int i=0; i<N; i++)
        if (sir[i] == '1')
            msk |= 1 << i;
    ap[msk] ++;
}
for (int j=1; j<=Q; j++)
{
    scanf ("%s", sir);
    int msk = 0;
    for (int i=0; i<N; i++)
        if (sir[i] == '1')
            msk |= 1 << i;
    int K;
    scanf ("%d\n", &K);
    qr[msk].push_back ({K, j});
}
for (int msk = 0; msk < (1 << N); msk ++)
{
    cost[msk] = 0;
    for (int i=0; i<N; i++)
        if (msk & (1 << i)) ;
        else cost[msk] += w[i];
    if (cost[msk] > 100) cost[msk] = 101;
}
for (int msk = 0; msk < (1 << N); msk ++)
    if (!qr[msk].empty ())
    {
        for (int j=0; j<=100; j++)
            mars[j] = 0;
        for (int j=0; j<(1 << N); j++)
            mars[cost[j ^ msk]] += ap[j];
        for (int j=1; j<=100; j++)
            mars[j] += mars[j - 1];
        for (auto q : qr[msk])
            ans[q.second] = mars[q.first];
    }
for (int i=1; i<=Q; i++)
    printf ("%d\n", ans[i]);
return 0;
}