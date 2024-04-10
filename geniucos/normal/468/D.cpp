#include<bits/stdc++.h>

using namespace std;

int All, minQ, N, currCol, CG, col[100009], vol[100009], max_vol[100009], Left[100009], Right[100009], criticalT[100009], used[100009], P[100009], aint[280009];
long long h[100009];
vector < pair < int, int > > v[100009];
vector < int > ids[100009];
set < pair < int, int > > S;

void dfs (int nod, int tata)
{
    vol[nod] = 1, max_vol[nod] = 0;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (it->first != tata)
            dfs (it->first, nod), vol[nod] += vol[it->first], max_vol[nod] = max (max_vol[nod], vol[it->first]);
}

void detCG ()
{
    int mini = -1;
    dfs (1, -1);
    for (int i=1; i<=N; i++)
    {
        int curr = max (max_vol[i], N - vol[i]);
        if (i == 1 || curr < mini)
            mini = curr, CG = i;
    }
}

void read ()
{
    scanf ("%d", &N);
    for (int i=1; i<N; i++)
    {
        int x, y, d;
        scanf ("%d %d %d", &x, &y, &d);
        v[x].push_back ({y, d});
        v[y].push_back ({x, d});
    }
}

void df (int nod, int tata)
{
    col[nod] = currCol, ids[currCol].push_back (nod);
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (it->first != tata)
            h[it->first] = h[nod] + it->second, df (it->first, nod);
}

void paintAndCalc ()
{
    for (auto it = v[CG].begin (); it != v[CG].end (); it ++)
        currCol ++, h[it->first] = it->second, df (it->first, CG), sort (ids[currCol].begin (), ids[currCol].end ());
    col[CG] = ++ currCol, ids[currCol].push_back (CG);
    long long ans = 0;
    for (int i=1; i<=N; i++)
        ans += h[i];
    printf ("%I64d\n", 2LL * ans);
}

void update (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        aint[nod] = val;
        return ;
    }
    int mij = (st + dr) / 2, f1 = nod << 1, f2 = f1 | 1;
    if (pos <= mij) update (f1, st, mij, pos, val);
    else update (f2, mij + 1, dr, pos, val);
    aint[nod] = min (aint[f1], aint[f2]);
}

void query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (aint[nod] < minQ)
            minQ = aint[nod];
        return ;
    }
    int mij = (st + dr) / 2, f1 = nod << 1, f2 = f1 | 1;
    if (x <= mij) query (f1, st, mij, x, y);
    if (mij < y) query (f2, mij + 1, dr, x, y);
}

void init ()
{
    All = N;
    for (int i=1; i<=currCol; i++)
    {
        update (1, 1, currCol, i, ids[i][0]), Left[i] = Right[i] = ids[i].size ();
        criticalT[i] = All - Right[i] - Left[i] + 1;
        if (i != currCol) S.insert ({criticalT[i], i});
    }
}

void refresh (int currI, int j)
{
    if (j == currCol) return ;
    S.erase ({criticalT[j], j});
    criticalT[j] = currI + All - Right[j] - Left[j] + 1;
    if (Right[j] != 0) S.insert ({criticalT[j], j});
}

void del (int currI, int nod)
{
    used[col[nod]] ++, Right[col[nod]] --;
    if (used[col[nod]] == ids[col[nod]].size ())
        update (1, 1, currCol, col[nod], N + 3);
    else
        update (1, 1, currCol, col[nod], ids[col[nod]][used[col[nod]]]);
    All --;
    refresh (currI, col[nod]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read ();
detCG ();
paintAndCalc ();
init ();
///Left[i] <= All - Right[i]
for (int i=1; i<=N; i++)
{
//    printf ("%d\n", P[i]);
//    printf ("%d->%d\n", i, S.size ());
/*    printf ("%d\n", All);
    for (int j=1; j<=currCol; j++)
        printf ("%d %d\n", Left[j], Right[j]);
    for (auto it = S.begin (); it != S.end (); it ++)
        printf ("(%d, %d) ", it->first, it->second);
    printf ("\n");
    if (i == N) break;*/
    int j = -1;
    auto it = S.begin ();
    if (it->second == col[i]) it ++;///nu cred ca se poate
    if (it != S.end () && it->first == i)
        j = it->second;
    if (j != -1)
        P[i] = ids[j][used[j]];
    if (P[i] == 0)
    {
        minQ = N + 2;
        if (i != CG)
        {
            if (col[i] > 1) query (1, 1, currCol, 1, col[i] - 1);
            if (col[i] < currCol) query (1, 1, currCol, col[i] + 1, currCol);
        }
        else minQ = aint[1];
        P[i] = minQ;
    }
    del (i, P[i]);
    Left[col[i]] --, refresh (i, col[i]);
}
for (int i=1; i<=N; i++)
    printf ("%d%c", P[i], (i == N ? '\n' : ' '));

return 0;
}