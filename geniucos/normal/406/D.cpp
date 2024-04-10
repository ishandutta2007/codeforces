#include<bits/stdc++.h>
#define x first
#define y second
#define pii pair < long long, long long >

using namespace std;

int root, lg = 16, N, M, nr, stk[100009], t[17][100009], lev[100009];
pii P[100009];

long long det (pii a, pii b, pii c)
{
    return 1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y -
           1LL * a.x * c.y - 1LL * b.x * a.y - 1LL * c.x * b.y;
}

int lca (int a, int b)
{
    if (lev[a] < lev[b]) swap (a, b);
    int aux = lev[a] - lev[b];
    for (int i=0; (1 << i) <= aux; i++)
        if (aux & (1 << i))
            a = t[i][a];
    if (a == b) return a;
    for (int i=lg; i>=0; i--)
        if (t[i][a] != 0 && t[i][b] != 0 && t[i][a] != t[i][b])
            a = t[i][a], b = t[i][b];
    return t[0][a];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%I64d %I64d", &P[i].x, &P[i].y);
for (int i=N; i>=1; i--)
{
    while (nr >= 2 && det (P[stk[nr - 1]], P[stk[nr]], P[i]) < 0) nr --;
    if (nr == 0) root = i;
    else
    {
        t[0][i] = stk[nr], lev[i] = lev[stk[nr]] + 1;
        for (int j=1; (1 << j) <= lev[i]; j++)
            t[j][i] = t[j - 1][t[j - 1][i]];
    }
    stk[++nr] = i;
}
scanf ("%d", &M);
while (M --)
{
    int a, b;
    scanf ("%d %d", &a, &b);
    printf ("%d%c", lca (a, b), (M == 0 ? '\n' : ' '));
}
return 0;
}