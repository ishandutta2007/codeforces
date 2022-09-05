#include<bits/stdc++.h>

using namespace std;

int nr, N, M, bg, code1[280009], code2[280009];
long long d[660009];
vector < pair < int, int > > v[660009];
priority_queue < pair < long long, int > > PQ;

void build (int nod, int st, int dr)
{
    code1[nod] = ++nr, code2[nod] = ++nr;
    for (int i=st; i<=dr; i++)
        v[i].push_back ({code1[nod], 0}), v[code2[nod]].push_back ({i, 0});
    if (st == dr) return ;
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    build (f1, st, mij);
    build (f2, mij + 1, dr);
}

void update (int type, int nod, int st, int dr, int x, int y, int to, int w)
{
    if (x <= st && dr <= y)
    {
        if (type == 2) v[to].push_back ({code2[nod], w});
        else v[code1[nod]].push_back ({to, w});
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (x <= mij) update (type, f1, st, mij, x, y, to, w);
    if (mij < y) update (type, f2, mij + 1, dr, x, y, to, w);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &bg);
nr = N, build (1, 1, N);
while (M --)
{
    int type;
    scanf ("%d", &type);
    if (type == 1)
    {
        int x, y, w;
        scanf ("%d %d %d", &x, &y, &w);
        v[x].push_back ({y, w});
        continue;
    }
    int x, l, r, w;
    scanf ("%d %d %d %d", &x, &l, &r, &w);
    update (type, 1, 1, N, l, r, x, w);
}
for (int i=1; i<=nr; i++)
    if (i != bg)
        d[i] = -1;
PQ.push ({0, bg});
while (!PQ.empty ())
{
    pair < long long, int > curr = PQ.top ();
    PQ.pop ();
    if (d[curr.second] != -curr.first) continue;
    int nod = curr.second;
    for (auto it : v[nod])
        if (d[it.first] == -1 || d[it.first] > d[nod] + it.second)
            d[it.first] = d[nod] + it.second, PQ.push ({-d[it.first], it.first});
}
for (int i=1; i<=N; i++)
    printf ("%I64d ", d[i]);
printf ("\n");
return 0;
}