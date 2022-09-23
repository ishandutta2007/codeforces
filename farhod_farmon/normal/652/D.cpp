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

int n, l, r, i, j, h, t[400000], ans[200000];
pair < pair < int, int >, int > p[200000];
vector < pair < pair < int, int >, int > > v;

void put( int x )
{
    while( x <= n + n ){
        t[x]++;
        x = (x | (x + 1));
    }
}

int get( int x )
{
    if( x < 0 )
        return 0;
    return t[x] + get((x & (x + 1)) - 1);
}

int main()
{
    sc( "%d", &n );
    for( i = 0; i < n; i++ ){
        sc( "%d%d", &l, &r );
        v.pb(mp(mp(l, -1), i));
        v.pb(mp(mp(r, 1), i));
        p[i].se = i;
    }
    sort( v.begin(), v.end() );
    for( i = j = 0; i < v.size(); i++, j++ ){
        r = v[i].fi.se;
        h = v[i].se;
        if( r == 1 )
            p[h].fi.fi = j;
        else
            p[h].fi.se = j;
    }
    sort( p, p + n );
    for( i = 0; i < n; i++ ){
        l = p[i].fi.se;
        r = p[i].fi.fi;
        h = p[i].se;
        ans[h] = i - get(l - 1);
        put(l);
    }
    for( i = 0; i < n; i++ )
        pr( "%d\n", ans[i] );
}