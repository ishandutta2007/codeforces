#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int N, M, p1[30009], p2[30009], NU[30009], p[10];
long long arb[3][3][120009];
pair < int , int > a[30009], b[30009];

void Read ()
{
    scanf ("%d %d", &N, &M);

    for (int i=1; i<=N; i++)
        scanf ("%d", &a[i].first), a[i].second = i;
    sort (a + 1, a + N + 1);
    for (int i=1; i<=N; i++)
        p1[a[i].second] = i;

    for (int i=1; i<=N; i++)
        scanf ("%d", &b[i].first), b[i].second = i;
    sort (b + 1, b + N + 1);
    for (int i=1; i<=N; i++)
        p2[b[i].second] = i;
}

long long get_best (int st, int dr)
{
    if (st > dr) return 0LL;
    /////atribui alora din [st, dr] altele din [st, dr]
    /////pot face un back
    int tot = 1;
    long long ans = -1LL<<40;
    for (int i=1; i<=dr - st + 1; i++)
        p[i] = i, tot *= i;
    while (tot --)
    {
        bool ok = 1;
        long long sum = 0;
        for (int i=st; i<=dr; i++)
        {
            sum += 1LL * a[i].first * b[st - 1 + p[i - st + 1]].first;
            if (NU[i] == st - 1 + p[i - st + 1]) ok = 0;
        }
        if (ok && sum > ans)
        {
            ans = sum;
            /*printf ("%I64d -> ", sum);
            for (int i=1; i<=dr - st + 1; i++)
                printf ("%d ", p[i]);
            printf ("\n");*/
        }
        next_permutation (p + 1, p + dr - st + 2);
    }
    return ans;
}

void recalc (int nod, int st, int dr)
{
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = (nod << 1) + 1;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
        {
            arb[i][j][nod] = arb[i][0][f1] + arb[0][j][f2];
            for (int p1 = 1; p1 < 3 && p1 + i <= mij - st + 1; p1 ++)
                for (int p2 = 1; p2 < 3 && p2 + j <= dr - mij && p1 + p2 <= 3; p2 ++)
                {
                    long long cost = get_best (mij - p1 + 1, mij + p2);
                    cost += arb[i][p1][f1] + arb[p2][j][f2];
                    if (cost > arb[i][j][nod])
                        arb[i][j][nod] = cost;
                }
        }
}

void refresh_small_piece (int nod, int st, int dr)
{
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
        {
            if (i + j > dr - st + 1) arb[i][j][nod] = -1LL << 40;
            else
            if (i + j == dr - st + 1) arb[i][j][nod] = 0;
            else arb[i][j][nod] = get_best (st + i, dr - j);
        }
}

void build (int nod, int st, int dr)
{
    if (dr - st + 1<= 4) refresh_small_piece (nod, st, dr);
    if (st == dr) return ;
    int mij = (st + dr) >> 1;
    build (nod << 1, st, mij);
    build ((nod << 1) + 1, mij + 1, dr);
    if (dr - st + 1 > 4) recalc (nod, st, dr);
}

void Update (int nod, int st, int dr, int pos)
{
    if (dr - st + 1<= 4) refresh_small_piece (nod, st, dr);
    if (st == dr) return ;
    int mij = (st + dr) >> 1;
    if (pos <= mij) Update (nod << 1, st, mij, pos);
    else Update ((nod << 1) + 1, mij + 1, dr, pos);
    if (dr - st + 1 > 4) recalc (nod, st, dr);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read ();
for (int i=1; i<=N; i++)
    NU[i] = p2[a[i].second];
build (1, 1, N);
while (M)
{
    M --;
    int x, y;
    scanf ("%d %d", &x, &y);
    swap (NU[p1[x]], NU[p1[y]]);
    Update (1, 1, N, p1[x]);
    Update (1, 1, N, p1[y]);
    printf ("%I64d\n", arb[0][0][1]);
}
return 0;
}