#include<bits/stdc++.h>

using namespace std;

int N, M, ap[300009], q[300009], ans[300009], luat[300009], out[300009];
vector < pair < int, int > > v[300009];
vector < int > qq;

void reformat ()
{
    int xo = 0, P = 0;
    for (int i=1; i<=N; i++)
        if (q[i] == -1) P = i;
        else xo ^= q[i];
    if (xo == 1 && P == 0)
    {
        printf ("-1\n");
        exit (0);
    }
    q[P] = xo;
    for (int i=1; i<=N; i++)
        if (q[i] == -1)
            q[i] = 0;
}

void dfs (int nod)
{
    ap[nod] = 1;
    for (auto it : v[nod])
        if (ap[it.first] == 0)
        {
            dfs (it.first);
            if (luat[it.first]) ans[it.second] = 0;
            out[nod] ^= luat[it.first];
        }
    if (out[nod] != q[nod])
        luat[nod] = 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &q[i]);
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back ({y, i});
    v[y].push_back ({x, i});
    out[x] ^= 1, out[y] ^= 1;
}
reformat ();
for (int i=1; i<=M; i++)
    ans[i] = 1;
dfs (1);
for (int i=1; i<=M; i++)
    if (ans[i])
        qq.push_back (i);
printf ("%d\n", qq.size ());
for (auto val : qq)
    printf ("%d\n", val);
return 0;
}