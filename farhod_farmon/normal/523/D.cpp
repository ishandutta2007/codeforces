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
#define REP(x,y) for( x=1; x<=y; x++ )
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
pair < lli, lli > t[2000001];
lli a,b,c,d;

pair < lli, lli > min_( pair < lli, lli > x, pair < lli, lli > y )
{
    if( x.fi<y.fi ) return x;
    return y;
}

void build( lli v, lli tl, lli tr )
{
    if( tl==tr ) t[v].se=tl;
    else{
        lli tm=( tl+tr )/2;
        build( v*2, tl, tm );
        build( v*2+1, tm+1, tr );
        t[v]=min_( t[v*2], t[v*2+1] );
    }
}

void update( lli v, lli tl, lli tr, lli i, lli x )
{
    if( tl==tr ) t[v].fi=x;
    else{
        lli tm=( tl+tr )/2;
        if( i<=tm ) update( v*2, tl, tm, i, x );
        else update( v*2+1, tm+1, tr, i, x );
        t[v]=min_( t[v*2], t[v*2+1] );
    }
}

int main()
{
    sc( "%I64d%I64d", &a, &b );
    build( 1, 0, b-1 );
    for( lli i=1; i<=a; i++ ){
        sc( "%I64d%I64d", &c, &d );
        lli l=max( t[1].fi, c )+d;
        update( 1, 0, b-1, t[1].se, l );
        pr( "%I64d\n", l );
    }
}