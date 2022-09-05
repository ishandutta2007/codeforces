#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int mxlg, lgmax, N, Q, x[200009], l[200009], aib[200009], Next[200009][21], to[200009][21];
long long cost[200009][21];

void U(int poz, int val)
{
    while (poz <= N)
    {
        aib[poz] = max (aib[poz], val);
        poz += poz - (poz & (poz - 1));
    }
}

int Qry (int poz)
{
    int maxi = 0;
    while (poz)
    {
        maxi = max (maxi, aib[poz]);
        poz &= poz - 1;
    }
    return maxi;
}

int get_last_value_smaller (int val, int sure)
{
    int p, u, mij, ras;
    p = sure;
    u = N;
    while (p<=u)
    {
        mij = (p + u) >> 1;
        if (x[mij] <= val)
        {
            ras = mij;
            p = mij + 1;
        }
        else u = mij - 1;
    }
    return ras;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &x[i], &l[i]);

for (int i=N; i>=1; i--)
{
    int ras;
    ras = get_last_value_smaller (x[i] + l[i], i);
    Next[i][0] = Qry(ras);
    Next[i][0] = max ( Next[i][0], x[i] + l[i] );
    U (i, Next[i][0]);
    to[i][0] = get_last_value_smaller (Next[i][0], i);
}

for (int i=0; (1<<i) <= N; i++)
    mxlg = i;
mxlg ++;

for (int i=N; i>=1; i--)
    for (int j=1; j<=mxlg; j++)
    {
        /////de la to + 1 nu e acoperit
        if (to[i][j-1] == N)
        {
            to[i][j] = to[i][j-1];
            cost[i][j] = cost[i][j-1];
            Next[i][j] = Next[i][j-1];
            continue;
        }
        Next[i][j] = Next[to[i][j-1] + 1][j-1];
        cost[i][j] = cost[i][j-1] + cost[ to[i][j-1] +1][j-1] + x[to[i][j-1] + 1] - Next[i][j-1];
        to[i][j] = to[to[i][j-1] + 1][j-1];
    }
scanf ("%d", &Q);
while (Q)
{
    int X, Y;
    Q --;
    scanf ("%d %d", &X, &Y);
    long long ans = 0;
    while (1)
    {
        if (Next[X][0] >= x[Y]) break;
        for (int j=0;; j++)
        {
            if (Next[X][j] >= x[Y]) break;
            lgmax = j;
        }
        int j = lgmax;
        ans += cost[X][j];
        ans += x[to[X][j]+1] - Next[X][j];
        X = to[X][j] + 1;
    }
    //if (Next[X][0] >= x[Y]) ;//////atunci e ok
    //else printf ("nasol\n");
    printf ("%I64d\n", ans);
}

return 0;
}