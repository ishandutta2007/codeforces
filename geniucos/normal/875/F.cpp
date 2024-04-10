#include<bits/stdc++.h>

using namespace std;

int ans, N, M, t[200009], vol[200009], rk[200009];
pair < int, pair < int, int > > e[200009];

int tata (int x)
{
    if (t[x] == x) return x;
    return t[x] = tata (t[x]);
}

void add (int x, int y, int z)
{
    x = tata (x), y = tata (y);
    if (x == y && vol[x] == 1)
        vol[x] --, ans += z;
    else
    if (x != y && vol[x] + vol[y] > 0)
    {
        if (rk[x] <= rk[y])
            t[x] = y, vol[y] += vol[x] - 1, rk[y] += (rk[x] == rk[y]), ans += z;
        else
            t[y] = x, vol[x] += vol[y] - 1, ans += z;
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    scanf ("%d %d %d", &e[i].second.first, &e[i].second.second, &e[i].first), e[i].first = -e[i].first;
sort (e + 1, e + M + 1);
for (int i=1; i<=N; i++)
    t[i] = i, vol[i] = 1;///nodes - edges
for (int i=1; i<=M; i++)
    add (e[i].second.first, e[i].second.second, -e[i].first);
printf ("%d\n", ans);
return 0;
}