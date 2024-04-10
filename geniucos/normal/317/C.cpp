#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int max_v, tura, N, M, nr, q[309], ap[309], Ap[309], a[309], b[309];
long long suma, sumb;

vector < pair < pair < int , int > , int > > ans;
vector < int > fii[309], h[309], v[309];

void bfs_init (int nod)
{
    q[++nr] = nod, ap[nod] = tura;
    for (int i=1; i<=nr; i++)
    {
        nod = q[i];
        suma += a[nod], sumb += b[nod];
        for (vector < int > :: iterator it = h[nod].begin(); it != h[nod].end(); it ++)
            if (ap[*it] == 0)
                q[++nr] = *it, v[nod].push_back (*it), v[*it].push_back (nod), ap[*it] = tura;
    }
}

void baga (int x, int y, int d)
{
    if (d == 0)
        return;
    a[x] -= d, a[y] += d;
    if (d > 0)
        ans.push_back (make_pair (make_pair (x, y), d));
    else
        ans.push_back (make_pair (make_pair (y, x), -d));
}

void dfs (int nod)
{
    Ap[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (Ap[*it] == 0 && ap[*it] == tura)
            dfs (*it), fii[nod].push_back (*it);
}

void primeste (int nod)
{
    for (vector < int > :: iterator it = fii[nod].begin (); it != fii[nod].end (); it ++)
    {
        primeste (*it);
        if (a[nod] == max_v)
            continue;
        if (a[nod] + a[*it] >= max_v)
            baga (*it, nod, max_v - a[nod]);
        else
            baga (*it, nod, a[*it]);
    }
}

void pompeaza (int nod)
{
    for (vector < int > :: iterator it = fii[nod].begin (); it != fii[nod].end (); it ++)
    {
        pompeaza (*it);
        if (a[*it] == max_v)
            continue;
        if (a[*it] + a[nod] >= max_v)
            baga (nod, *it, max_v - a[*it]);
        else
            baga (nod, *it, a[nod]);
    }
}

void solve ()
{
    for (int iti = nr; iti > 1; iti --)
    {
        int nod = q[iti];
        ap[nod] = -1;
        if (a[nod] == b[nod])
            continue;

        dfs (nod);
        if (b[nod] > a[nod])
        {
            primeste (fii[nod][0]);/////fiind frunza are doar un vecin(in cazul asta fiu)
            baga (fii[nod][0], nod, b[nod] - a[nod]);
        }
        else
        {
            pompeaza (fii[nod][0]);/////fiind frunza are doar un vecin(in cazul asta fiu)
            baga (nod, fii[nod][0], a[nod] - b[nod]);
        }

        for (int i=1; i<=N; i++)
            fii[i].clear (), Ap[i] = 0;
    }
}

void Print_Answer ()
{
    printf ("%d\n", ans.size ());
    for (vector < pair < pair < int , int > , int > > :: iterator it = ans.begin (); it != ans.end (); it ++)
        printf ("%d %d %d\n", it->first.first, it->first.second, it->second);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &max_v, &M);

for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);

for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]);

while (M)
{
    M --;
    int x, y;
    scanf ("%d %d", &x, &y);
    h[x].push_back (y);
    h[y].push_back (x);
}

for (int i=1; i<=N; i++)
    if (ap[i] == 0)
    {
        tura ++;
        nr = 0;
        suma = sumb = 0;
        bfs_init (i);
        if (suma != sumb)
        {
            printf ("NO\n");
            return 0;
        }
        solve ();
    }
Print_Answer ();
return 0;
}