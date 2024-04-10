#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int difx, N, M, best, min_dist[100009], a[100009], b[100009], x[100009], y[100009], order[100009];
int **aint = new int *[280009];
bool FoundIt;
pair < int, int > vect[100009];

int biggest_smaller_or_equal (int val)
{
    int p = 1, u = M, mij, ras = 0;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (a[order[mij]] <= val) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    return ras;
}

int smallest_bigger_or_equal (int val)
{
    int p = 1, u = M, mij, ras = 0;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (a[order[mij]] >= val) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
    return ras;
}

void WithoutStations ()
{
    int minx, miny, maxx, maxy;
    for (int i=1; i<=N; i++)
    {
        int xx = x[i], yy = y[i];
        if (i == 1) minx = maxx = xx, miny = maxy = yy;
        else
        {
            if (xx < minx) minx = xx;
            if (xx > maxx) maxx = xx;
            if (yy < miny) miny = yy;
            if (yy > maxy) maxy = yy;
        }
    }
    best = max ((maxx - minx + 1) / 2, (maxy - miny + 1) / 2);
}

void build (int nod, int st, int dr)
{
    aint[nod] = new int[dr - st + 2] ();
    for (int i=st; i<=dr; i++)
        aint[nod][++aint[nod][0]] = b[order[i]];
    sort (aint[nod] + 1, aint[nod] + aint[nod][0] + 1);
    if (st == dr) return ;
    int mij = (st + dr) >> 1;
    build (nod << 1, st, mij);
    build ((nod << 1) + 1, mij + 1, dr);
}

void Search (int nod, int st, int dr, int x, int y, int b_min, int b_max)
{
    if (FoundIt) return ;
    if (x <= st && dr <= y)
    {
        int p = 1, u = aint[nod][0], mij, ras = -1;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (aint[nod][mij] >= b_min) ras = mij, u = mij - 1;
            else p = mij + 1;
        }
        if (ras != -1 && aint[nod][ras] <= b_max)
        {
            FoundIt = 1;
            return ;
        }
        return ;
    }
    int mij = (st + dr) >> 1;
    if (x <= mij) Search (nod << 1, st, mij, x, y, b_min, b_max);
    if (y > mij) Search ((nod << 1) + 1, mij + 1, dr, x, y, b_min, b_max);
}

bool AnyPoint (int a1, int b1, int a2, int b2)
{
    a1 = smallest_bigger_or_equal (a1), a2 = biggest_smaller_or_equal (a2);
    if (a1 > a2 || a1 == 0 || a2 == 0) return 0;
    FoundIt = 0, Search (1, 1, M, a1, a2, b1, b2);
    return FoundIt;
}

void GetMinDist ()
{
    for (int i=1; i<=N; i++)
    {
        int p = 0, u = 200000010, mij, ras = 200000010;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (AnyPoint (x[i] - mij, y[i] - mij, x[i] + mij, y[i] + mij)) ras = mij, u = mij - 1;
            else p = mij + 1;
        }
        min_dist[i] = ras;
    }
}

bool ok (int T)
{
    int ii = vect[N].second, minx = x[ii] - T, maxx = x[ii] + T, miny = y[ii] - T, maxy = y[ii] + T;
    for (int j=N - 1; j>=1; j--)
    {
        int i = vect[j].second;
        if (vect[j].first <= T)
        {
            int R = T - vect[j].first;
            if (AnyPoint (minx - R, miny - R, maxx + R, maxy + R)) return 1;
        }
        minx = max (minx, x[i] - T);
        maxx = min (maxx, x[i] + T);
        miny = max (miny, y[i] - T);
        maxy = min (maxy, y[i] + T);
        if (minx > maxx || miny > maxy) return 0;
    }
    return 0;
}

bool cmp (int p1, int p2)
{
    return a[p1] < a[p2];
}

void cit (int &a, int &b)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    a = x + y, b = x - y;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++) cit (x[i], y[i]);
for (int i=1; i<=M; i++) cit (a[i], b[i]), order[i] = i;
sort (order + 1, order + M + 1, cmp);
WithoutStations ();
if (M == 0)
{
    printf ("%d\n", best);
    return 0;
}
build (1, 1, M);
GetMinDist ();
for (int i=1; i<=N; i++) vect[i] = make_pair (min_dist[i], i);
sort (vect + 1, vect + N + 1);
int p = 0, u = best, mij, ras = best + 1;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
if (ras < best) best = ras;
printf ("%d\n", best);

return 0;
}