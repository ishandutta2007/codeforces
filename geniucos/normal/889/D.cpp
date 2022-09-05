#include<bits/stdc++.h>

using namespace std;

int allSame, currCnt, N, M, nr, X[4002017], Y[4002017], inv[2017];
double PI = acos (-1.0);

struct point
{
    int x, y;
    point () {}
    point (int _x, int _y):
        x (_x), y (_y) {}
    bool operator < (const point &other) const
    {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
}A[2017], b[2017];

point operator + (point a, point b) {return point (a.x + b.x, a.y + b.y);}

bool det (point a, point b, point c)
{
    return (1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y -
            1LL * a.x * c.y - 1LL * b.x * a.y - 1LL * c.x * b.y == 0LL);
}

struct unghi
{
    long long sus, jos, side;

    unghi () {}

    unghi (long long x, long long y)
    {
        if (x > 0) side = -1;
        else side = (x != 0);
        sus = y, jos = x;
        if (jos < 0) sus = -y, jos = -x;
    }

    bool operator == (const unghi &other) const
    {
        return (side == other.side && 1LL * sus * other.jos == 1LL * jos * other.sus);
    }

    bool operator < (const unghi &other) const
    {
        if (side != other.side) return side < other.side;
        return 1LL * sus * other.jos < 1LL * other.sus * jos;
    }

    void print (string s)
    {
        printf ("(%I64d, %I64d, %I64d)  %.10f%s", sus, jos, side, atan ((double) sus / jos * side) * 180.0 / PI, s.c_str ());
    }
};

struct query
{
    unghi m;
    int where;

    bool operator < (const query &other) const
    {
        if (m == other.m)
        {
            if (1LL * where * other.where < 0) return (where > other.where);
            if (where < 0) return 0;
            int i = X[where], j = Y[where], k = X[other.where], p = Y[other.where];
            if (i != k) return i < k;
            return j < p;
        }
        return (m < other.m);
    }
}events[4202017];
vector < pair < pair < long long, long >, pair < long long, long > > > S;

int XX = 1, YY = 2;
void update (int pos, point newVal)
{
    if (pos == 1)
    {
        point old = b[pos];
        allSame = 0, b[pos] = newVal;
        for (int i=1; i<=(N + 1) / 2; i++)
            allSame += (b[i].x == b[1].x && b[i].y == b[1].y);
        b[pos] = old;
    }
    else
    allSame -= (b[pos].x == b[1].x && b[pos].y == b[1].y), allSame += (newVal.x == b[1].x && newVal.y == b[1].y);

    if (pos == XX || pos == YY)
    {
        b[pos] = newVal, currCnt = 0, XX = 1, YY = 1;
        for (int i=2; i<=(N + 1) / 2; i++)
            if (b[i].x != b[1].x || b[i].y != b[1].y)
                YY = i;
        for (int i=1; i<=(N + 1) / 2; i++)
            currCnt += det (b[XX], b[YY], b[i]);
    }
    else
    {
        currCnt -= det (b[XX], b[YY], b[pos]), currCnt += det (b[XX], b[YY], newVal);
        b[pos] = newVal;
    }
}

void refresh (int i)
{
    if (i > N + 1 - i) i = N + 1 - i;
    update (i, A[i] + A[N + 1 - i]);
}

long long gcd (long long a, long long b)
{
    long long r;
    while (b != 0)
        r = a % b, a = b, b = r;
    return a;
}

void tryToAdd ()
{
    if (allSame == (N + 1) / 2)
    {
        printf ("-1\n");
        exit (0);
    }
    if (currCnt == (N + 1) / 2)
    {
        int a1 = b[XX].x, b1 = b[XX].y, a2 = b[YY].x, b2 = b[YY].y;
        //printf ("%d %d %d %d\n", a1, b1, a2, b2);
        if (a1 != a2)
        {
            long long x = 1LL * a1 * b2 - 1LL * a2 * b1, y = a1 - a2, d = gcd (x, y), z = b1 - b2, t = a1 - a2, d2 = gcd (z, t);
            //S.insert (unghi (1LL * a2 * b1 - 1LL * a1 * b2, b1 - b2));
            x /= d, y /= d, z /= d2, t /= d2;
            if (y < 0) y = -y, x = -x;
            if (t < 0) z = -z, t = -t;
            S.push_back ({{x, y}, {z, t}});
        }
        else S.push_back ({{0, 0}, {0, 0}});
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N <= 2)
{
    printf ("-1\n");
    return 0;
}
for (int i=1; i<=N; i++)
    scanf ("%d %d", &A[i].x, &A[i].y), inv[i] = i;
sort (A + 1, A + N + 1);

for (int i=1; i<=N; i++)
    for (int j=i+1; j<=N; j++)
    {
        nr ++;
        X[nr] = i;
        Y[nr] = j;
        events[nr].where = nr;
        events[nr].m = unghi (A[j].y - A[i].y, A[j].x - A[i].x);
    }
sort (events + 1, events + nr + 1);

for (int i=1; i<=(N + 1) / 2; i++)
    b[i] = A[i] + A[N + 1 - i];
update (1, b[1]), tryToAdd ();
for (int currstp=1; currstp<=nr; currstp++)
{
    int stp = (currstp <= nr ? currstp : currstp - nr);
    int x = X[events[stp].where], y = Y[events[stp].where];
    swap (A[inv[x]], A[inv[y]]);
    swap (inv[x], inv[y]);
//    printf ("%d %d\n", inv[x], inv[y]);
    refresh (inv[x]), refresh (inv[y]);
    tryToAdd ();
}
sort (S.begin (), S.end ());
S.erase (unique (S.begin (), S.end ()), S.end ());
printf ("%d\n", S.size ());

return 0;
}