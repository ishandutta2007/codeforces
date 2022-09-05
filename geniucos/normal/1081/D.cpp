#include<bits/stdc++.h>

using namespace std;

int N, M, K, t[100009], sz[100009];
pair < int, pair < int, int > > e[100009];

int tata (int x)
{
    if (t[x] == x) return x;
    return t[x] = tata (t[x]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &K);
for (int i=1; i<=N; i++)
    t[i] = i;
for (int i=1; i<=K; i++)
{
    int x;
    scanf ("%d", &x);
    sz[x] = 1;
}
for (int i=1; i<=M; i++)
    scanf ("%d %d %d", &e[i].second.first, &e[i].second.second, &e[i].first);
sort (e + 1, e + M + 1);
int ans = -1;
for (int i=1; i<=M; i++)
{
    int c = e[i].first, x = e[i].second.first, y = e[i].second.second;
    x = tata (x), y = tata (y);
    if (x != y)
    {
        t[x] = y;
        sz[y] += sz[x];
        if (sz[y] == K)
        {
            ans = c;
            break;
        }
    }
}
for (int i=1; i<=K; i++)
    printf ("%d%c", ans, " \n"[i == K]);
return 0;
}