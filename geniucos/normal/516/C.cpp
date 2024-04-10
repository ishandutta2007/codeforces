#include<cstdio>
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

int N, M, d[200009], h[200009];
long long D[200009];

struct tip
{
    long long arb_min, arb_max, best;
}aint[800009], ans;

tip unite (tip a, tip b)
{
    tip ans;
    ans.best = max (a.best, b.best);
    ans.best = max (ans.best, b.arb_max - a.arb_min);
    ans.arb_max = max (a.arb_max, b.arb_max);
    ans.arb_min = min (a.arb_min, b.arb_min);
    return ans;
}

void build (int nod, int st, int dr)
{
    if (st == dr)
    {
        aint[nod].arb_min = (long long) D[st] - 1LL * 2 * h[st];
        aint[nod].arb_max = (long long) 1LL * 2 * h[st] + D[st];
        aint[nod].best = 0;
        return ;
    }

    int mij = (st + dr) >> 1;
    build (nod<<1, st, mij);
    build ((nod<<1) + 1, mij + 1, dr);
    aint[nod] = unite (aint[nod<<1], aint[(nod<<1) + 1]);
}

void Q (int nod, int st, int dr, int x, int y)
{
    if (x > y)
        return;

    if (x <= st && dr <= y)
    {
        if (ans.best == -1)
            ans = aint[nod];
        else
            ans = unite (ans, aint[nod]);
        return ;
    }

    int mij = (st + dr) >> 1;

    if (x <= mij)
        Q (nod<<1, st, mij, x, y);

    if (y > mij)
        Q ((nod<<1) + 1, mij + 1, dr, x, y);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);

for (int i=1; i<=N; i++)
    scanf ("%d", &d[i]);

for (int i=1; i<=N; i++)
    scanf ("%d", &h[i]);

for (int i = N + 1; i <= 2 * N; i++)
{
    d[i] = d[i - N];
    h[i] = h[i - N];
}

for (int i=2; i<=2 * N; i++)
    D[i] = (long long) D[i-1] + d[i - 1];

build (1, 1, 2 * N);

for (int i=1; i<=M; i++)
{
    int st, dr;
    scanf ("%d %d", &st, &dr);
    ans.best = -1;

    if (st <= dr)
        Q (1, 1, 2 * N, dr + 1, N + st - 1);
    else
    {
        dr += N;
        Q (1, 1, 2 * N, dr + 1, N + st - 1);
    }

    printf ("%I64d\n", ans.best);
}

return 0;
}