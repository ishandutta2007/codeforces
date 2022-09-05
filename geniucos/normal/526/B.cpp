#include<bits/stdc++.h>

using namespace std;

int M, N, maxH[100009], d[100009];
void dfs (int nod)
{
    if (nod >= (1 << N))
    {
        maxH[nod] = 0;
        return ;
    }
    int f1 = nod << 1, f2 = f1 | 1;
    dfs (f1), dfs (f2);
    maxH[nod] = max (maxH[f1] + d[f1], maxH[f2] + d[f2]);
}

int ans = 0;
void solve (int nod)
{
    if (nod >= (1 << N))
        return ;
    int f1 = nod << 1, f2 = f1 | 1;
    if (maxH[f1] + d[f1] < maxH[f2] + d[f2])
        swap (f1, f2);
    solve (f1);
    ans += maxH[nod] - (maxH[f2] + d[f2]);
    solve (f2);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), M = (1 << (N + 1)) - 1;
for (int i=2; i<=M; i++)
    scanf ("%d", &d[i]);
dfs (1);
solve (1);
printf ("%d\n", ans);
return 0;
}