#include<bits/stdc++.h>

using namespace std;

int nr, N, K, a[1009], d[1009], col[10009], cod[109][109];
bool maybe[10009];
vector < int > v[2][10009];

int check (int lin)
{
    int ma = 0, x, y;
    for (int i=1; i<=N; i++)
    {
        queue < int > cc;
        for (int j=1; j<=N; j++)
            d[j] = -1;
        cc.push (i), d[i] = 0;
        while (!cc.empty ())
        {
            int nod = cc.front ();
            cc.pop ();
            for (auto it = v[lin][nod].begin (); it != v[lin][nod].end (); it ++)
                if (d[*it] == -1)
                {
                    d[*it] = d[nod] + 1;
                    cc.push (*it);
                }
        }
        for (int j=1; j<=N; j++)
            if (d[j] == -1) return -1;
        for (int j=1; j<=N; j++)
            if (d[j] > ma) ma = d[j], x = i, y = j;
    }
//    printf ("%d, %d -> %d %d\n", lin, ma, x, y);
    return ma;
}

void back (int pos)
{
    if (pos == nr + 1)
    {
        if (a[2] == 0 && a[3] == 1)
            a[3] = 1;
        for (int i=1; i<=N; i++)
            v[0][i].clear (), v[1][i].clear ();
        for (int i=1; i<=N; i++)
            for (int j=1; j<i; j++)
            {
                int curr = a[cod[i][j]];
                v[curr][i].push_back (j);
                v[curr][j].push_back (i);
            }
        int L = check (0), R = check (1), curr = min (L, R);
        if (curr == K)
        {
            int sz = 0;
            for (int i=1; i<=N; i++)
                sz += v[0][i].size ();
            printf ("%d\n", sz / 2);
            for (int i=1; i<=N; i++)
                for (auto it = v[0][i].begin (); it != v[0][i].end (); it ++)
                    if (i < *it) printf ("%d %d\n", i, *it);
            exit (0);
//            printf ("\n\n");
        }
        return ;
    }
    for (int i=0; i<2; i++)
        a[pos] = i, back (pos + 1);
}

void brute ()
{
    for (int i=1; i<=N; i++)
        for (int j=1; j<i; j++)
            cod[i][j] = ++nr;
    back (2);
    printf ("-1\n");
    exit (0);
}

void Ver ()
{
    bool E[109][109];
    int M;
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            E[i][j] = (i == j);
    while (M --)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        E[x][y] = E[y][x] = 1;
        v[0][x].push_back (y);
        v[0][y].push_back (x);
    }
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if (!E[i][j])
                v[1][i].push_back (j);
    printf ("%d\n", min (check (0), check (1)));
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

//Ver ();
//return 0;
scanf ("%d %d", &N, &K);
if (N <= 4) brute ();
if (K != 2 && K != 3)
{
    printf ("-1\n");
    return 0;
}
if (K == 2)
{
    printf ("%d\n", 6 + (N - 5) * 2);
    printf ("1 2\n1 3\n1 4\n2 3\n2 5\n4 5\n");
    for (int i=6; i<=N; i++)
        printf ("2 %d\n", i), printf ("4 %d\n", i);
    return 0;
}
if (K == 3)
{
    printf ("%d\n", N + 1);
    printf ("1 2\n");
    printf ("1 3\n");
    printf ("1 4\n");
    printf ("2 3\n");
    printf ("2 4\n");
    for (int i=5; i<=N; i++)
        printf ("3 %d\n", i);
    return 0;
}
return 0;
}