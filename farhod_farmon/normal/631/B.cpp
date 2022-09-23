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

int n, m, i, j, h, x, y, q;
pair < int, int > a[5005], b[5005];

int main()
{
    sc( "%d%d%d", &n, &m, &q );
    for( i = 1; i <= q; i++ ){
        sc( "%d%d%d", &h, &x, &y );
        if( h == 1 )a[x] = mp(i, y);
        else b[x] = mp(i, y);
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            if( a[i].fi > b[j].fi )pr( "%d ", a[i].se );
            else pr( "%d ", b[j].se );
        }
        pr( "\n" );
    }
}