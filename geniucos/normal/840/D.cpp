#include<bits/stdc++.h>

using namespace std;

int N, M, *lst[300009], sz[300009], p[300009], ans[300009];
vector < pair < pair < int, int >, pair < int, int > > > qr[1200009];

int cntSmaller (int i, int j)
{
    int p = 1, u = sz[i], mij, ras = 0;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (lst[i][mij] < j) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    return ras;
}

int getFrequency (int st, int dr, int val)
{
    return cntSmaller (val, dr + 1) - cntSmaller (val, st);
}

int code (int nod, int st, int dr, int x, int y)
{
    int mij = (st + dr) >> 1;
    if (x <= mij && mij < y) return nod;
    if (y <= mij) return code (nod * 2, st, mij, x, y);
    return code (nod * 2 + 1, mij + 1, dr, x, y);
}

int ap[300009];
pair < int, int > bst[4];
void add (int val)
{
    ap[val] ++;
    bool fnd = 0;
    for (int i=0; i<4; i++)
        if (bst[i].first == val)
        {
            bst[i].second ++;
            while (i > 0 && bst[i].second > bst[i - 1].second)
                swap (bst[i], bst[i - 1]), i --;
            fnd = 1; break;
        }
    if (!fnd)
    {
        if (ap[val] > bst[3].second)
        {
            int i = 3;
            bst[3] = {val, ap[val]};
            while (i > 0 && bst[i].second > bst[i - 1].second)
                swap (bst[i], bst[i - 1]), i --;
        }
    }
}

int aux[300009][4];
void solve (int nod, int st, int dr)
{
    if (st == dr) return ;
    int mij = (st + dr) >> 1, f1 = nod * 2, f2 = f1 | 1;
    if (!qr[nod].empty ())
    {
        for (int i=0; i<4; i++)
            bst[i].first = bst[i].second = 0;
        for (int i=mij; i>=st; i--)
        {
            add (p[i]);
            for (int j=0; j<4; j++)
                aux[i][j] = bst[j].first;
        }
        for (int i=st; i<=mij; i++)
            ap[p[i]] = 0;
        for (int i=0; i<4; i++)
            bst[i].first = bst[i].second = 0;
        for (int i=mij + 1; i<=dr; i++)
        {
            add (p[i]);
            for (int j=0; j<4; j++)
                aux[i][j] = bst[j].first;
        }
        for (int i=mij + 1; i<=dr; i++)
            ap[p[i]] = 0;
        for (auto tp : qr[nod])
        {
            int ps = tp.first.first, K = tp.first.second, x = tp.second.first, y = tp.second.second;
            vector < int > v;
            for (int j=0; j<4; j++)
                v.push_back (aux[x][j]);
            for (int j=0; j<4; j++)
                v.push_back (aux[y][j]);
            sort (v.begin (), v.end ());
            v.erase (unique (v.begin (), v.end ()), v.end ());
            for (auto val : v)
            {
                int f = getFrequency (x, y, val);
                if (f * K <= y - x + 1) continue;
                ans[ps] = val; break;
            }
        }
    }
    solve (f1, st, mij);
    solve (f2, mij + 1, dr);
}

void Read (int &x);
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read (N), Read (M);
for (int i=1; i<=N; i++)
    Read (p[i]), sz[p[i]] ++;
for (int i=1; i<=N; i++)
    lst[i] = new int[sz[i] + 1], sz[i] = 0;
for (int i=1; i<=N; i++)
    lst[p[i]][++sz[p[i]]] = i;
for (int i=1; i<=M; i++)
{
    int x, y, k;
    Read (x), Read (y), Read (k);
    if (x == y) ans[i] = p[x];
    else qr[code (1, 1, N, x, y)].push_back ({{i, k}, {x, y}}), ans[i] = -1;
}
solve (1, 1, N);
for (int i=1; i<=M; i++)
    printf ("%d\n", ans[i]);
return 0;
}

#define maxl 100000
int pos = maxl - 1;
char sir[maxl];

void Next ()
{
    if (++pos == maxl)
        fread (sir, 1, maxl, stdin), pos = 0;
}


void Read (int &x)
{
    while (sir[pos] < '0' || sir[pos] > '9') Next ();
    for (x = 0; sir[pos] >= '0' && sir[pos] <= '9'; Next ()) x = x * 10 + sir[pos] - '0';
}