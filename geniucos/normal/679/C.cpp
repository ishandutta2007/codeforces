#include<bits/stdc++.h>

using namespace std;

int best, nr, curr, N, K, to_rem[2016], ap[509][509], sz[250009], ap2[250009], ap3[250009];
char sir[509][509];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool DEB = 0;

void dfs (int i, int j)
{
    ap[i][j] = nr, sz[nr] ++;
    for (int k=0; k<4; k++)
        if (sir[i + dx[k]][j + dy[k]] == 1 && ap[i + dx[k]][j + dy[k]] == 0)
            dfs (i + dx[k], j + dy[k]);
}

void Add (int i, int j)
{
    int id = ap[i][j];
    if (ap3[id] || sir[i][j] == 0) return ;
    ap3[id] = 1, to_rem[++nr] = id;
    curr += sz[id] - ap2[id];
    //if (DEB) printf ("+ %d\n", id);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &K);
for (int i=1; i<=N; i++)
    gets (sir[i] + 1);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        if (sir[i][j] == '.') sir[i][j] = 1;
        else sir[i][j] = 0;
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        if (ap[i][j] == 0 && sir[i][j] == 1)
        {
            nr ++, dfs (i, j);
            if (sz[nr] > best) best = sz[nr];
        }
/*for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=N; j++)
        printf ("%d", ap[i][j]);
printf ("\n");*/
for (int i2=K; i2<=N; i2++)
{
    for (int i=i2 - K + 1; i<=i2; i++)
        for (int j=1; j<K; j++)
            ap2[ap[i][j]] ++;
    for (int j2=K; j2<=N; j2++)
    {
        //DEB = (i2 == 3 && j2 == 2);
        for (int i=i2 - K + 1; i<=i2; i++)
            ap2[ap[i][j2]] ++;
        if (j2 > K)
        {
            for (int i=i2 - K + 1; i<=i2; i++)
                ap2[ap[i][j2 - K]] --;
        }
        curr = K * K, nr = 0;
        if (j2 < N)
        {
            for (int i=i2 - K + 1; i<=i2; i++)
                Add (i, j2 + 1);
        }
        if (j2 - K >= 1)
        {
            for (int i=i2 - K + 1; i<=i2; i++)
                Add (i, j2 - K);
        }
        if (i2 < N)
        {
            for (int j=j2 - K + 1; j<=j2; j++)
                Add (i2 + 1, j);
        }
        if (i2 > K)
        {
            for (int j=j2 - K + 1; j<=j2; j++)
                Add (i2 - K, j);
        }
        for (int j=1; j<=nr; j++)
            ap3[to_rem[j]] = 0;
        if (curr > best) best = curr;
    }
    for (int i=i2 - K + 1; i<=i2; i++)
        for (int j=1; j<=N; j++)
            ap2[ap[i][j]] = 0;
}
printf ("%d\n", best);
return 0;
}