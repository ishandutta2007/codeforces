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

pair < int, int > p[4 * N];
int a[N], n;

pair < int, int > M( pair < int, int > x, pair < int, int > y )
{
    pair < int, int > g;
    if( !x.fi )g.fi = y.fi;
    else if( !y.fi )g.fi = x.fi;
    else if( a[x.fi] < a[y.fi] )g.fi = x.fi;
    else g.fi = y.fi;
    if( !x.se )g.se = y.se;
    else if( !y.se )g.se = x.se;
    else if( a[x.se] > a[y.se] )g.se = x.se;
    else g.se = y.se;
    return g;
}

void build( int x, int l, int r )
{
    if( l == r ){
        p[x] = mp(l, l);
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    p[x] = M(p[x * 2], p[x * 2 + 1]);
}

pair < int, int > take( int x, int l, int r, int tl, int tr )
{
    if( l == tl && r == tr )return p[x];
    if( tl > tr )return mp(0, 0);
    int m = (l + r) / 2;
    return M(take(x * 2, l, m, tl, min(m, tr)), take(x * 2 + 1, m + 1, r, max(tl, m + 1), tr));
}

int main()
{
    int i, j, m, x, l, r;
    sc( "%d%d", &n, &m );
    for( i = 1; i <= n; i++ )sc( "%d", &a[i] );
    build(1, 1, n);
    for( i = 1; i <= m; i++ ){
        sc( "%d%d%d", &l, &r, &x );
        pair < int, int > g = take(1, 1, n, l, r);
        if( a[g.fi] != x )pr( "%d\n", g.fi );
        else if( a[g.se] != x )pr( "%d\n", g.se );
        else pr( "-1\n" );
    }
}