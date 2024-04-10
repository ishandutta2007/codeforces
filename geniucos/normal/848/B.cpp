#include<bits/stdc++.h>

using namespace std;

int N, M, All, W, H;
int id[100009], typ[100009], t[100009], a[100009], b[100009], c[100009], d[100009];
//int x[100009], y[100009];
pair < int, int > ans[100009];

void slv (int N, int M)
{
    for (int i=1; i<=N + M; i++)
        id[i] = i;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=M; j++)
            swap (id[i], id[N + j]);
        for (int j=1; j<=N + M; j++)
        {
            printf ("%2d ", id[j]);
            if (j == N) printf (" | ");
        }
        printf ("\n");
    }
}

pair < pair < int, int >, int > x[100009], y[100009];

void solve (int lft, int rgt, int st, int dr)
{
    int n = 0, m = 0;
    for (int i=lft; i<=rgt; i++)
        a[++n] = x[i].second;
    for (int i=st; i<=dr; i++)
        b[++m] = y[i].second;
    /*for (int i=1; i<=n; i++)
        printf ("%d ", a[i]);
    printf (" | ");
    for (int i=1; i<=m; i++)
        printf ("%d ", b[i]);
    printf ("\n");*/
    if (n >= m)
    {
        for (int i=1; i<=m; i++)
            c[i] = b[m - i + 1];
        for (int i=1; i<=n - m; i++)
            c[i + m] = a[i];
        int q = n;
        for (int i=1; i<=m; i++)
            d[i] = a[q --];
    }
    else
    {
        int q = m;
        for (int i=1; i<=n; i++)
            c[i] = b[q --];
        for (int i=1; i<=n; i++)
            d[i] = a[n - i + 1];
        for (int i=1; i<=m; i++)
            d[i + n] = b[i];
    }
/*    for (int i=1; i<=n; i++)
        printf ("%d ", c[i]);
    printf (" | ");
    for (int i=1; i<=m; i++)
        printf ("%d ", d[i]);
    printf ("\n\n");*/
    n = 0, m = 0;
    for (int i=lft; i<=rgt; i++)
        x[i].second = c[++n];
    for (int i=st; i<=dr; i++)
        y[i].second = d[++m];
}

void solve ()
{
    scanf ("%d %d %d", &All, &W, &H);
    for (int i=1; i<=All; i++)
    {
        int type, val, t;
        scanf ("%d %d %d", &type, &val, &t);
        if (type == 1)
            x[++N] = {{val - t, val}, i};
        else
            y[++M] = {{val - t, val}, i};
    }
    sort (x + 1, x + N + 1);
    sort (y + 1, y + M + 1);
    int k = 1;
    for (int i=1; i<=N; i++)
    {
        int j;
        for (j=i; j<=N; j++)
            if (x[j].first.first != x[i].first.first)
                break;
        j --;
        ///
        while (y[k].first.first < x[i].first.first) k ++;
        if (y[k].first.first == x[i].first.first)
        {
            int st = k;
            while (y[k].first.first == x[i].first.first && k <= M)
                k ++;
            k --;
            solve (i, j, st, k);
        }
        ///
        i = j;
    }
    for (int i=1; i<=N; i++)
        ans[x[i].second] = {x[i].first.second, H};
    for (int i=1; i<=M; i++)
        ans[y[i].second] = {W, y[i].first.second};
    for (int i=1; i<=All; i++)
        printf ("%d %d\n", ans[i].first, ans[i].second);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

//slv (9, 4);
//slv (4, 9);
//return 0;

solve ();

/*scanf ("%d %d %d", &N, &W, &H);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &typ[i]), id[i] = i;
    if (typ[i] == 1)
        scanf ("%d %d", &x[i], &t[i]);
    else
        scanf ("%d %d", &y[i], &t[i]);
}

int cnt = 0;
for (int tmp = 0;; tmp++)
{
    for (int i=1; i<=N; i++)
        if (tmp >= t[i])
        {
            if (typ[i] == 1 && y[i] < H) y[i] ++;
            else
            if (typ[i] == 2 && x[i] < W) x[i] ++;
        }
    for (int i=1; i<=N; i++)
        for (int j=i + 1; j<=N; j++)
            if (x[i] == x[j] && y[i] == y[j])
                swap (id[i], id[j]), cnt ++, printf ("+ (%d, %d)\n", i, j);
    for (int i=1; i<=N; i++)
        printf ("%d%c", id[i], " \n"[i == N]);
    bool done = 1;
    for (int i=1; i<=N; i++)
        if (typ[i] == 1 && y[i] < H) done = 0;
        else
        if (typ[i] == 2 && x[i] < W) done = 0;
    if (done) break;
}*/
/*printf ("all encounters: %d\n", cnt);
for (int i=1; i<=N; i++)
    printf ("%d\n", id[i]);*/
/*for (int i=1; i<=N; i++)
    ans[id[i]] = {x[i], y[i]};*/
/*for (int i=1; i<=N; i++)
    printf ("%d %d\n", ans[i].first, ans[i].second);*/
return 0;
}