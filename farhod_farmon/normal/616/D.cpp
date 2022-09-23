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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )

using namespace std;

int n, k;
pair < int, int > t[4000000];

void pl( int x, int l, int r, int y )
{
    if( l == r ){
        t[x].fi = 1;
        t[x].se++;
        return;
    }
    int m = (l + r) / 2;
    if( y <= m )pl( x * 2, l, m, y );
    else pl( x * 2 + 1, m + 1, r, y );
    t[x].fi = t[x * 2].fi + t[x * 2 + 1].fi;
}

void mn( int x, int l, int r, int y )
{
    if( l == r ){
        t[x].se--;
        if( !t[x].se )t[x].fi = 0;
        return ;
    }
    int m = (l + r) / 2;
    if( y <= m )mn( x * 2, l, m, y );
    else mn( x * 2 + 1, m + 1, r, y );
    t[x].fi = t[x * 2].fi + t[x * 2 + 1].fi;
}

int main()
{
    int i, j, x[500005], l, ar = -1, al;
    sc( "%d%d", &n, &k );
    for( i = 1; i <= n; i++ )sc( "%d", &x[i] );
    for( i = l = 1; i <= n; i++ ){
        pl( 1, 0, 1000000, x[i] );
        while( t[1].fi > k )mn( 1, 0, 1000000, x[l++] );
        if( i - l > ar - al ){
            ar = i;
            al = l;
        }
    }
    pr( "%d %d\n", al, ar );
}