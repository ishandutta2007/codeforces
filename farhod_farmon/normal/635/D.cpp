#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <iomanip>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 200002;

using namespace std;

pair < int, pair < int, int > > t[3][4 * N];
int a[3], n, k, kol[4 * N];

pair < int, pair < int, int > > comb( pair < int, pair < int, int > > x, pair < int, pair < int, int > > y )
{
    return mp(x.fi + y.fi, mp(x.se.fi + y.se.fi, x.se.se + y.se.se));
}

void build( int g, int x, int l, int r )
{
    if( l == r ){
        t[g][x] = mp(0, mp(0, a[g]));
        return;
    }
    int m = (l + r) / 2;
    build(g, x * 2, l, m);
    build(g, x * 2 + 1, m + 1, r);
    t[g][x] = comb(t[g][x * 2], t[g][x * 2 + 1]);
}

void up( int g, int x, int l, int r, int f, int y )
{
    if( l == r ){
        t[g][x].fi += y;
        t[g][x].fi = min(t[g][x].fi, a[g]);
        return;
    }
    int m = (l + r) / 2;
    if( f <= m )up(g, x * 2, l, m, f, y);
    else up(g, x * 2 + 1, m + 1, r, f, y);
    t[g][x] = comb(t[g][x * 2], t[g][x * 2 + 1]);
}

pair < int, pair < int, int > > take( int g, int x, int l, int r, int tl, int tr )
{
    if( tl > tr )return mp(0, mp(0, 0));
    if( l == tl && r == tr )return t[g][x];
    int m = (l + r) / 2;
    return comb(take(g, x * 2, l, m, tl, min(tr, m)), take(g, x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
    int i, j, h, q, x, y, z;
    sc( "%d%d%d%d%d", &n, &k, &a[2], &a[1], &q );
    build(1, 1, 1, n);
    build(2, 1, 1, n);
    for( i = 1; i <= q; i++ ){
        sc( "%d", &z );
        if( z == 1 ){
            sc( "%d%d", &x, &y );
            up(1, 1, 1, n, x, y);
            up(2, 1, 1, n, x, y);
        }
        else{
            sc( "%d", &x );
            pair < int, pair < int, int > > p1 = take(1, 1, 1, n, 1, x - 1);
            pair < int, pair < int, int > > p3 = take(2, 1, 1, n, x + k, n);
            pr( "%d\n", p1.fi + p3.fi );
        }
    }
}