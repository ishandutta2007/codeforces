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

int n, q, a[150005], k;
vector < pair < int, int > > v;

bool cmp( pair < int, int > x, pair < int, int > y )
{
    return x.fi > y.fi;
}

void add( int x )
{
    v.pb(mp(a[x], x));
    sort( v.begin(), v.end(), cmp );
    if( v.size() > k )
        v.pop_back();
}

bool is( int x )
{
    for( int i = 0; i < v.size(); i++ ){
        if( v[i].se == x )
            return true;
    }
    return false;
}

int main()
{
    int i, j, h, x, m;
    sc( "%d%d%d", &n, &k, &q );
    for( i = 1; i <= n; i++ )
        sc( "%d", &a[i] );
    for( i = 1; i <= q; i++ ){
        sc( "%d%d", &h, &x );
        if( h == 1 )
            add(x);
        else{
            if( is(x) )
                pr( "YES\n" );
            else
                pr( "NO\n" );
        }
    }
}