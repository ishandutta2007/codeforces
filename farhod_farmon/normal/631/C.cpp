#include <bits/stdc++.h>

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

using namespace std;

int n, m, i, j, h, l, r, a[200002], cur, x, y, z, curtype, ans[200002], ansi;
pair < int, pair < int, int > > p[200002];

int main()
{
    sc( "%d%d", &n, &m );
    for( i = 1; i <= n; i++ )sc( "%d", &a[i] );
    for( i = 1; i <= m; i++ ){
        sc( "%d%d", &p[i].se.se, &p[i].fi );
        p[i].se.fi = -i;
    }
    sort( p + 1, p + m + 1 );
    cur = -p[m].se.fi;
    curtype = p[m].se.se;
    l = 1;
    r = p[m].fi;
    sort( a + 1, a + r + 1 );
    for( i = r + 1; i <= n; i++ )ans[i] = a[i];
    ansi = r;
    for( i = m - 1; i >= 1; i-- ){
        if( -p[i].se.fi < cur )continue;
        cur = -p[i].se.fi;
        x = p[i].fi;
        int type = p[i].se.se;
        if( curtype == 1 ){
            curtype = type;
            for( ; r >= l + x; r--, ansi-- )ans[ansi] = a[r];
        }
        else{
            curtype = type;
            for( ; l <= r - x; l++, ansi-- )ans[ansi] = a[l];
        }
    }
    while( l <= r && curtype == 2 )ans[ansi--] = a[l++];
    while( l <= r && curtype == 1 )ans[ansi--] = a[r--];
    for( i = 1; i <= n; i++ )pr( "%d ", ans[i] );
}