#include<bits/stdc++.h>

using namespace std;

int N, M, ans, mod, val[50009];
vector < pair < int, bool > > v[2][100009];

bool Fin (int ans)
{
    printf ("%d\n", ans);
    exit (0);
}

void add (int lin, int st, int dr, int val)
{
//    printf ("rest %d, [%d, %d] = %d\n", lin, st, dr, val);
    if (st % 2 != lin) st ++;
    if (dr % 2 != lin) dr --;
    st /= 2, dr /= 2, st ++, dr ++;
//    printf ("rest %d, [%d, %d] = %d\n\n", lin, st, dr, val);
    if (st > dr)
    {
        if (val) Fin (0);
        return ;
    }
    v[lin][st - 1].push_back (make_pair (dr, val));
    v[lin][dr].push_back (make_pair (st - 1, val));
}

void dfs (int lin, int nod, int x)
{
    if (val[nod] == -1) val[nod] = x;
    else
    {
        if (val[nod] != x) Fin (0);
        return ;
    }
    for (auto it = v[lin][nod].begin (); it != v[lin][nod].end (); it ++)
        dfs (lin, it->first, x ^ it->second);
}

void Solve (int rest)
{
    for (int i=0; (i - 1) * 2 + rest < N; i++)
        val[i] = -1;
    for (int i=0; (i - 1) * 2 + rest < N; i++)
        if (val[i] == -1)
        {
            dfs (rest, i, 1);
            if (i > 0) ans += ans;
            if (ans >= mod) ans -= mod;
        }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M), mod = 1e9 + 7, ans = 1;

while (M --)
{
    char c;
    int i, j, st = 0, dr = N - 1;
    scanf ("%d %d %c\n", &i, &j, &c), i --, j --;
    if (c == 'o') c = 1;
    else c = 0;
    dr = min (i + j, 2 * (N - 1) - i - j), st = max (i - j, j - i);
    add ((i + j) & 1, st, dr, c);
}
Solve (0), Solve (1);
printf ("%d\n", ans);

return 0;
}