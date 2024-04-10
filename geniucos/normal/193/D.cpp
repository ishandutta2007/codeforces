#include<cstdio>
#include<algorithm>

using namespace std;

int N, Pos[300009], A[300009], B[300009], add[1200009], mi1[1200009], mi2[1200009], cnt1[1200009], cnt2[1200009];
long long sol;

void build (int nod, int st, int dr)
{
    cnt1[nod] = dr - st + 1, cnt2[nod] = 0, mi2[nod] = N + 3;
    if (st == dr) return;
    int mij = (st + dr) >> 1;
    build (nod << 1, st, mij);
    build ((nod << 1) + 1, mij + 1, dr);
}

void split (int nod)
{
    if (add[nod] == 0) return;
    int f1 = nod << 1, f2 = (nod << 1) + 1;
    add[f1] += add[nod], add[f2] += add[nod];
    mi1[f1] += add[nod], mi1[f2] += add[nod];
    mi2[f1] += add[nod], mi2[f2] += add[nod];
    add[nod] = 0;
}

void recalc (int nod)
{
    int f1 = nod << 1, f2 = (nod << 1) + 1;
    mi1[nod] = min (mi1[f1], mi1[f2]), cnt1[nod] = 0;
    if (mi1[f1] == mi1[nod]) cnt1[nod] += cnt1[f1];
    if (mi1[f2] == mi1[nod]) cnt1[nod] += cnt1[f2];

    mi2[nod] = min (mi2[f1], mi2[f2]);
    if (mi1[f1] != mi1[nod]) mi2[nod] = min (mi1[f1], mi2[nod]);
    else
    if (mi1[f2] != mi1[nod]) mi2[nod] = min (mi1[f2], mi2[nod]);
    cnt2[nod] = 0;
    if (mi1[f1] == mi2[nod]) cnt2[nod] += cnt1[f1];
    else
    if (mi2[f1] == mi2[nod]) cnt2[nod] += cnt2[f1];
    if (mi1[f2] == mi2[nod]) cnt2[nod] += cnt1[f2];
    else
    if (mi2[f2] == mi2[nod]) cnt2[nod] += cnt2[f2];
}

void Update (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        add[nod] += val, mi1[nod] += val, mi2[nod] += val;
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (x <= mij) Update (nod << 1, st, mij, x, y, val);
    if (y > mij) Update ((nod << 1) + 1, mij + 1, dr, x, y, val);
    recalc (nod);
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (mi1[nod] <= 1) sol += cnt1[nod];
        if (mi2[nod] <= 1) sol += cnt2[nod];
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (x <= mij) Query (nod << 1, st, mij, x, y);
    if (y > mij) Query ((nod << 1) + 1, mij + 1, dr, x, y);
}

void baga (int st, int dr, int val)
{
    if (st > dr) return;
    Update (1, 1, N, st, dr, val);
}

int main ()
{
//freopen ("intervale.in", "r", stdin);
//freopen ("intervale.out", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &B[i]), A[B[i]] = i;
build (1, 1, N);
for (int R=2; R<=N; R++)
{
    Pos[A[R - 1]] = R - 1;
    int p1 = Pos[A[R] - 1], p2 = Pos[A[R] + 1];
    if (p1 > p2) swap (p1, p2);
    if (p1 == 0)
    {
        if (p2 == 0) baga (1, R - 1, 1);
        else baga (p2 + 1, R - 1, 1);
    }
    else
    {
        baga (p2 + 1, R - 1, 1);
        baga (1, p1, -1);
    }
    Query (1, 1, N, 1, R - 1);
}
printf ("%I64d\n", sol);
return 0;
}