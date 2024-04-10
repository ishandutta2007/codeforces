#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n;
vector < pair < int, int > > v;

int main()
{
    int d, h, i;
    sc( "%d%d%d", &n, &d, &h );
    if( n == 2 ){
        pr( "1 2\n" );
        return 0;
    }
    if( d > h * 2 || d == 1 ){
        pr( "-1" );
        return 0;
    }
    int nw = 2;
    int lt = 1;
    for( i = 1; i <= h; i++ ){
        v.pb(mp(lt, nw));
        lt = nw;
        nw = nw + 1;
    }
    lt = 1;
    for( i = 1; i <= d - h; i++ ){
        v.pb(mp(lt, nw));
        lt = nw;
        nw = nw + 1;
    }
    while( nw <= n ){
        v.pb(mp(h, nw));
        nw = nw + 1;
    }
    for( i = 0; i < v.size(); i++ )pr( "%d %d\n", v[i].fi, v[i].se );
}