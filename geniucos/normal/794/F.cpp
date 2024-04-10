#include<bits/stdc++.h>

using namespace std;

int N, M, a[100009];
long long aint[280009][10], oldF1[10], oldF2[10], sum[280009], ans;
char P[280009][11];
bool lzy[280009];

void Build (int nod, int st, int dr)
{
    for (int i=0; i<10; i++)
        P[nod][i] = i;
    if (st == dr)
    {
        int aux = a[st], p = 1;
        while (aux)
            aint[nod][aux % 10] += p, p *= 10, aux /= 10;
        sum[nod] = a[st];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    Build (f1, st, mij);
    Build (f2, mij + 1, dr);
    for (int i=0; i<10; i++)
        aint[nod][i] = aint[f1][i] + aint[f2][i];
}

void do_move (int nod, int x, int y)
{
    for (int j=0; j<10; j++)
        if (P[nod][j] == x)
            P[nod][j] = y, lzy[nod] = 1;
    aint[nod][y] += aint[nod][x], aint[nod][x] = 0;
}

void split (int nod, int f1, int f2)
{
    if (lzy[nod] == 0) return ;
    lzy[nod] = 0, lzy[f1] = lzy[f2] = 1;
    memcpy (oldF1, aint[f1], sizeof (aint[f1]));
    memcpy (oldF2, aint[f2], sizeof (aint[f2]));
    memset (aint[f1], 0, sizeof (aint[f1]));
    memset (aint[f2], 0, sizeof (aint[f2]));
    for (int i=0; i<10; i++)
        P[f1][i] = P[nod][P[f1][i]], P[f2][i] = P[nod][P[f2][i]],
        aint[f1][P[nod][i]] += oldF1[i], aint[f2][P[nod][i]] += oldF2[i];
    for (int i=0; i<10; i++)
        P[nod][i] = i;
}

void U (int nod, int st, int dr, int x, int y, int c, int d)
{
    if (x <= st && dr <= y)
    {
        do_move (nod, c, d);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, f1, f2);
    if (x <= mij) U (f1, st, mij, x, y, c, d);
    if (mij < y) U (f2, mij + 1, dr, x, y, c, d);
    for (int i=0; i<10; i++)
        aint[nod][i] = aint[f1][i] + aint[f2][i];
}

void Q (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        for (int i=0; i<10; i++)
            ans += aint[nod][i] * i;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, f1, f2);
    if (x <= mij) Q (f1, st, mij, x, y);
    if (mij < y) Q (f2, mij + 1, dr, x, y);
}

void Read (int &x);
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read (N), Read (M);
for (int i=1; i<=N; i++)
    Read (a[i]);
Build (1, 1, N);
while (M --)
{
    int type;
    Read (type);
    if (type == 1)
    {
        int x, y, c, d;
        Read (x), Read (y), Read (c), Read (d);
        if (c == d) continue;
        U (1, 1, N, x, y, c, d);
        continue;
    }
    int x, y;
    Read (x), Read (y);
    ans = 0, Q (1, 1, N, x, y);
    printf ("%I64d\n", ans);
}

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