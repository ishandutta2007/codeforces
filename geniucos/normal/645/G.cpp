#include<cstdio>
#include<bitset>
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

int N, A;
double R[100009], Pi = acos (-1.0), eps = 1e-8;

struct point
{
    double x, y;
    void Read () {int aa, bb;scanf ("%d %d", &aa, &bb), x = (double) aa, y = (double) bb;}
    point () {x = y = 0.0;}
    point (double _x, double _y): x (_x), y (_y) {}
    point operator - (const point &other) {return point (x - other.x, y - other.y);}
    point operator + (const point &other) {return point (x + other.x, y + other.y);}
    point operator * (const double val) {return point ((double) x * val, (double) y * val);}
    double module () {return (double) sqrt ((double) x * x + y * y);}
    double get_angle () {return (double) atan2 (y, x);};
}a[100009], Lft, Rgt;

bool GetArcs (point O, double R, point o, double r, double &x, double &y)
{
    point o2 = o - O;
    double mid_angle = o2.get_angle (), D = o2.module ();
    double cosbeta = ((double)D * D + R * R - r * r) / (2.0 * R * D);
    if (cosbeta < -1.0 || cosbeta > 1.0) return 0;
    double beta = acos (cosbeta);
    if (beta < 0.0) beta += 2 * Pi;
    x = mid_angle - beta;
    y = mid_angle + beta;
    return 1;
}

bool ok (double bigR)
{
    double currL, currR;
    vector < pair < double, double > > ev;
    for (int i=1; i<=N; i++)
        if (GetArcs (Rgt, bigR, a[i], R[i], currL, currR))
        {
            if (currL < 0.0) currL += 2 * Pi;
            if (currR < 0.0) currR += 2 * Pi;
//            printf ("%d %.5f %.5f\n", i, currL, currR);
  //          if (currL <= currR) ev.push_back (make_pair (currL, currR)), ev.push_back (make_pair (currL + 2 * Pi, currR + 2 * Pi));
    //        else ev.push_back (make_pair (currL, currR + 2 * Pi));
            if (currL > currR) swap (currL, currR);
            ev.push_back (make_pair (currL, currR));
        }
    sort (ev.begin (), ev.end ());
    set < double > S;
    for (vector < pair < double, double > > :: iterator it = ev.begin (); it != ev.end (); it ++)
    {
        set < double > :: iterator it2 = S.lower_bound (it->first);
        if (it2 != S.end () && *it2 <= it->second) return 1;
        S.insert (it->second);
    }
    return 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &A), Lft = point (-A, 0), Rgt = point (A, 0);
for (int i=1; i<=N; i++)
    a[i].Read (), R[i] = (a[i] - Lft).module ();
double p = 0.0, u = 2.0 * A, ras = u, mij;
while (u - p > eps)
{
    mij = (p + u) / 2.0;
    if (ok (mij)) ras = mij, u = mij - eps;
    else p = mij + eps;
}
printf ("%.10f\n", ras);
return 0;
}