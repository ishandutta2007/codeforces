#include<bits/stdc++.h>

using namespace std;

int nr, N, ap[100009], d[300];
vector < int > g[100], v[300];
queue < int > cc;

void addEdge (int i, int j)
{
    v[i].push_back (j);
    v[j].push_back (i);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    long long x;
    scanf ("%I64d", &x);
    for (int j=0; j<60; j++)
        if (x & (1LL << j))
        {
            g[j].push_back (i);
            if (g[j].size () >= 3)
            {
                printf ("3\n");
                return 0;
            }
        }
}
for (int i=0; i<60; i++)
    if (g[i].size () == 2)
    {
        int x = g[i][0], y = g[i][1];
        if (ap[x] == 0) ap[x] = ++nr;
        if (ap[y] == 0) ap[y] = ++nr;
        addEdge (ap[x], ap[y]);
    }
memset (ap, 0, sizeof (ap));
int mini = -1;
for (int i=1; i<=nr; i++)
    for (auto j : v[i])
    {
        for (int k=1; k<=nr; k++)
            d[k] = -1;
        cc.push (j), d[j] = 1;
        while (!cc.empty ())
        {
            int nod = cc.front ();
            cc.pop ();
            for (auto x : v[nod])
                if (d[x] == -1 && (nod != j || x != i))
                    d[x] = d[nod] + 1, cc.push (x);
        }
        if (d[i] != -1 && (d[i] < mini || mini == -1))
            mini = d[i];
    }
printf ("%d\n", mini);
return 0;
}