#include<bits/stdc++.h>

using namespace std;

int N, M, in[200009], ap[2][200009], take[200009];
vector < int > v[2][200009];
queue < int > cc;

void dfs (int lin, int nod)
{
    if (ap[lin][nod])
        return ;
    ap[lin][nod] = 1;
    for (auto it : v[lin][nod])
        dfs (lin, it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y), in[y] ++;
    v[0][x].push_back (y);
    v[1][y].push_back (x);
}
for (int i=1; i<=N; i++)
    if (in[i] == 0)
        cc.push (i);
while (!cc.empty ())
{
    int nod = cc.front ();
    cc.pop ();
    for (auto it : v[0][nod])
        if (--in[it] == 0)
            cc.push (it);
}
for (int i=1; i<=N; i++)
    if (in[i] != 0)
    {
        printf ("-1\n");
        return 0;
    }
int ans = 0;
for (int i=1; i<=N; i++)
{
    if (ap[0][i] == 0 && ap[1][i] == 0)
        ans ++, take[i] = 1;
    dfs (0, i);
    dfs (1, i);
}
printf ("%d\n", ans);
for (int i=1; i<=N; i++)
    if (take[i]) printf ("A");
    else printf ("E");
printf ("\n");
return 0;
}