#include<cstdio>

using namespace std;

int N, Pos[300009], A[300009], add[1200009], mi[1200009], cnt[1200009];
long long sol;

void build (int nod, int st, int dr)
{
    cnt[nod] = dr - st + 1;
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
    mi[f1] += add[nod], mi[f2] += add[nod];
    add[nod] = 0;
}

void recalc (int nod)
{
    int f1 = nod << 1, f2 = (nod << 1) + 1;
    mi[nod] = mi[f1], cnt[nod] = cnt[f1];
    if (mi[f2] < mi[nod]) mi[nod] = mi[f2], cnt[nod] = cnt[f2];
    else
    if (mi[f2] == mi[nod]) cnt[nod] += cnt[f2];
}

void Update (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        add[nod] += val, mi[nod] += val;
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (x <= mij) Update (nod << 1, st, mij, x, y, val);
    if (y > mij) Update ((nod << 1) + 1, mij + 1, dr, x, y, val);
    recalc (nod);
}

void baga (int st, int dr, int val)
{
    if (st > dr) return;
    Update (1, 1, N, st, dr, val);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    A[x] = y;
}
build (1, 1, N);
for (int R=2; R<=N; R++)
{
    Pos[A[R - 1]] = R - 1;
    int p1 = Pos[A[R] - 1], p2 = Pos[A[R] + 1];
    if (p1 > p2) p2 = p1, p1 = Pos[A[R] + 1];
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
    if (mi[1] == 0) sol += cnt[1] - (N - R + 1);
}
printf ("%I64d\n", sol + N);
return 0;
}