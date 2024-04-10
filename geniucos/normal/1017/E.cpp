#include<bits/stdc++.h>

using namespace std;

int nr, N, M, pi[200009], ap[200009], st[200009];
long long pat[200009];
vector < long long > v, g, h;

long long det (pair < int, int > a, pair < int, int > b, pair < int, int > c)
{
    return 1LL * a.first * b.second + 1LL * b.first * c.second + 1LL * c.first * a.second - 1LL * a.first * c.second - 1LL * b.first * a.second - 1LL * c.first * b.second;
}

void add (int i, vector < pair < int, int > > &p)
{
    while (nr >= 2 && det (p[st[nr - 1]], p[st[nr]], p[i]) >= 0)
        ap[st[nr]] = 0, nr --;
    ap[i] = 1, st[++nr] = i;
}

long long modul (long long x)
{
    if (x < 0) return -x;
    return x;
}

void takeConvexHull (vector < pair < int, int > > &points, vector < pair < int, int > > &hull)
{
    hull.clear ();
    sort (points.begin (), points.end ());
    for (int i=0; i<points.size (); i++)
        ap[i] = 0;
    nr = 2, st[1] = 0, st[2] = 1, ap[1] = 1;
    for (int i=2; i<points.size (); i++)
        if (ap[i] == 0)
            add (i, points);
    for (int i=points.size () - 1; i>0; i--)
        if (ap[i] == 0)
            add (i, points);
    add (0, points), nr --;
    for (int i=1; i<=nr; i++)
        hull.push_back (points[st[i]]);
    if (hull.size () == 1)
        hull.push_back (points.back ());
}

long long d2 (pair < int, int > a, pair < int, int > b)
{
    return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);
}

void build (vector < pair < int, int > > &hull, vector < long long > &v)
{
    v.clear ();
    int L = hull.size ();
    hull.push_back (hull[0]);
    hull.push_back (hull[1]);
    for (int i=0; i<L; i++)
        v.push_back (d2 (hull[i], hull[i + 1])),
        v.push_back (modul (det (hull[i], hull[i + 1], hull[i + 2])));
    hull.pop_back ();
    hull.pop_back ();
}

void solve (int N, vector < long long > &v, vector < long long > &v2)
{
    vector < pair < int, int > > points, hull;
    for (int i=1; i<=N; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        points.push_back ({x, y});
    }
    takeConvexHull (points, hull);
/*    for (auto p : hull)
        printf ("%d %d\n", p.first, p.second);
    printf ("\n");*/
    build (hull, v);
    reverse (hull.begin (), hull.end ());
    build (hull, v2);
}

void tryMatch (vector < long long > &h)
{
    N = v.size ();
    for (int i=1; i<=N; i++)
        pat[i] = h[i - 1];
    for (int i=0; i<N; i++)
        v.push_back (v[i]);
    int k = 0;
    for (int i=2; i<=N; i++)
    {
        while (k != 0 && pat[k + 1] != pat[i]) k = pi[k];
        k += (pat[k + 1] == pat[i]);
        pi[i] = k;
    }
    k = 0;
    int currPos = 0;
    for (auto e : v)
    {
        currPos ++;
        while (k != 0 && pat[k + 1] != e) k = pi[k];
        k += (pat[k + 1] == e);
        if (k == N && currPos % 2 == N % 2)
        {
            printf ("YES\n");
            exit (0);
        }
        if (k == N) k = pi[k];
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
solve (N, v, h);
solve (M, h, g);
if (v.size () != h.size ())
{
    printf ("NO\n");
    return 0;
}
tryMatch (h);
//tryMatch (g);
printf ("NO\n");
return 0;
}