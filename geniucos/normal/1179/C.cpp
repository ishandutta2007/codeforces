#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000000;
int N, M, Q, a[300009], b[300009], frq[maxN + 10], sum[4 * maxN + 10], mi[4 * maxN + 10];

void build (int nod, int st, int dr)
{
    if (st == dr)
    {
        sum[nod] = frq[st];
        mi[nod] = min (frq[st], 0);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    build (f1, st, mij);
    build (f2, mij + 1, dr);
    sum[nod] = sum[f1] + sum[f2];
    mi[nod] = min (mi[f2], sum[f2] + mi[f1]);
}

void update (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        sum[nod] += val;
        mi[nod] = min (sum[nod], 0);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (pos <= mij) update (f1, st, mij, pos, val);
    else update (f2, mij + 1, dr, pos, val);
    sum[nod] = sum[f1] + sum[f2];
    mi[nod] = min (mi[f2], sum[f2] + mi[f1]);
}

int query (int nod, int st, int dr, int toRight)
{
    if (st == dr) return st;
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (toRight + mi[f2] < 0) return query (f2, mij + 1, dr, toRight);
    return query (f1, st, mij, toRight + sum[f2]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), frq[a[i]] --;
for (int j=1; j<=M; j++)
    scanf ("%d", &b[j]), frq[b[j]] ++;
scanf ("%d", &Q);
build (1, 1, maxN);
while (Q --)
{
    int type, pos, val;
    scanf ("%d %d %d", &type, &pos, &val);
    if (type == 1)
    {
        update (1, 1, maxN, a[pos], +1);
        a[pos] = val;
        update (1, 1, maxN, a[pos], -1);
    }
    else
    {
        update (1, 1, maxN, b[pos], -1);
        b[pos] = val;
        update (1, 1, maxN, b[pos], +1);
    }
    if (mi[1] >= 0) printf ("-1\n");
    else printf ("%d\n", query (1, 1, maxN, 0));
}
return 0;
}