#include<bits/stdc++.h>

using namespace std;

int nr, best, N, M, a[410][410], rgt[410], realCode[409][409];
short nxt[81000][410], prv[81000][410], ap[160009];

void read ()
{
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            scanf ("%d", &a[i][j]);
    for (int i=1; i<=N; i++)
        for (int j=i + 1; j<=N; j++)
            realCode[i][j] = ++ nr;
}

int pp (int i, int j) {return realCode[i][j];}

void Clear (int i)
{
    for (int j=1; j<=M; j++)
        ap[a[i][j]] = 0;
/*    for (int i=1; i<=1000; i++)
        if (ap[i] != 0)
        {
            printf ("useless Clear\n");
            exit (0);
        }*/
}

void buildNxt ()
{
    for (int i1=N; i1>=1; i1--)
        for (int i2=i1 + 1; i2<=N; i2++)
        {
            for (int j=M; j>=1; j--)
            {
                ap[a[i1][j]] = j;
                if (ap[a[i2][j]]) nxt[pp (i1, i2)][j] = ap[a[i2][j]];
                else nxt[pp (i1, i2)][j] = M + 1;
            }
            Clear (i1);

            for (int j=1; j<=M; j++)
            {
                ap[a[i1][j]] = j;
                prv[pp (i1, i2)][j] = ap[a[i2][j]];
            }
            Clear (i1);

            if (i1 < i2 - 1)
                for (int j=1; j<=M; j++)
                    nxt[pp (i1, i2)][j] = min (nxt[pp (i1 + 1, i2)][j], nxt[pp (i1, i2)][j]),
                    prv[pp (i1, i2)][j] = max (prv[pp (i1, i2)][j], prv[pp (i1 + 1, i2)][j]);
        }
}

void update (int area)
{
    if (area > best)
        best = area;
}

void solve ()
{
    for (int i1=1; i1<=N; i1++)
    {
        ap[a[i1][M]] = M, rgt[M] = M;
        for (int j=M - 1; j>=1; j--)
        {
            if (ap[a[i1][j]] != 0) rgt[j] = min (rgt[j + 1], ap[a[i1][j]] - 1);
            else rgt[j] = rgt[j + 1];
            ap[a[i1][j]] = j;
        }
        Clear (i1);
        for (int j=1; j<=M; j++)
            update (rgt[j] - j + 1);
        for (int i2 = i1 + 1; i2 <= N; i2 ++)
        {
            for (int j=1; j<=M; j++)
            {
                int i = max ((int) prv[pp (i1, i2)][j], (int) ap[a[i2][j]]);
                if (i != 0)
                    rgt[i] = min (rgt[i], j - 1);
                ap[a[i2][j]] = j;
            }
            Clear (i2);
            for (int j=M; j>=1; j--)
            {
                int k = nxt[pp (i1, i2)][j];
                if (ap[a[i2][j]] != 0) k = min (k, (int) ap[a[i2][j]]);
                if (k != M + 1)
                    rgt[j] = min (rgt[j], k - 1);
                ap[a[i2][j]] = j;
            }
            Clear (i2);
            for (int j=M - 1; j>=1; j--)
                rgt[j] = min (rgt[j], rgt[j + 1]);
            for (int j=1; j<=M; j++)
                update ((i2 - i1 + 1) * (rgt[j] - j + 1));
            //printf ("(%d, %d)->%d\n", i1, i2, best);
        }
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read ();
buildNxt ();
solve ();
printf ("%d\n", best);

return 0;
}