#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int si, n, m, A[100009], arb[400009], L[400009], x[100009], y[100009], v[100009];

void U (int nod, int st, int dr, int x, int y, int val)
{
    if ( x <= st && dr <= y)
    {
        L[nod] |= val;
        return ;
    }
    if (L[nod])
    {
        L[nod<<1] |= L[nod];
        L[(nod<<1)+1] |= L[nod];
        L[nod] = 0;
    }
    int mij = (st + dr) >> 1;
    if (x<=mij) U(nod<<1, st, mij, x, y, val);
    if (y>mij) U((nod<<1)+1, mij+1, dr, x, y, val);
}

void Q (int nod, int st, int dr, int x, int y)
{
    if (x<=st && dr<=y)
    {
        if (si == -1) si = arb[nod];
        else si&=arb[nod];
        return ;
    }
    int mij = (st+dr)>>1;
    if (x<=mij) Q(nod<<1, st, mij, x, y);
    if (y>mij) Q((nod<<1)+1, mij+1, dr, x, y);
}

void build (int nod, int st, int dr)
{
    if (st==dr)
    {
        arb[nod] = L[nod];
        A[st] = arb[nod];
        return ;
    }
    if (L[nod])
    {
        L[nod<<1] |= L[nod];
        L[(nod<<1)+1] |= L[nod];
        L[nod] = 0;
    }
    int mij = (st+dr)>>1;
    build (nod<<1, st, mij);
    build ((nod<<1)+1, mij+1, dr);
    arb[nod] = (arb[nod<<1]&arb[(nod<<1)+1]);
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d",&n, &m);
for (int i=1; i<=m; i++)
{
    scanf ("%d %d %d", &x[i], &y[i], &v[i]);
    U (1, 1, n, x[i], y[i], v[i]);
}

build (1, 1, n);

for (int i=1; i<=m; i++)
{
    si = -1;
    Q (1, 1, n, x[i], y[i]);
    if (si != v[i])
    {
        printf ("NO\n");
        return 0;
    }
}
printf ("YES\n");
for (int i=1; i<=n; i++)
    printf ("%d ", A[i]);
printf ("\n");
return 0;
}