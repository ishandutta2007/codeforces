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

lli n, m, i, j, h, cnt, x, p[400002];
vector < pair < lli, char > > va, vb;
char c;

bool M( pair < lli, char > a, pair < lli, char > b, lli y )
{
    if( !y || y == m - 1 )b.fi = min(a.fi, b.fi);
    return a == b;
}

int main()
{
    sc( "%I64d%I64d", &n, &m );
    for( i = 1; i <= n; i++ ){
        sc( "%I64d-%c", &x, &c );
        if( va.size() && va.back().se == c )va[va.size() - 1].fi += x;
        else va.pb(mp(x, c));
    }
    for( i = 1; i <= m; i++ ){
        sc( "%I64d-%c", &x, &c );
        if( vb.size() && vb.back().se == c )vb[vb.size() - 1].fi += x;
        else vb.pb(mp(x, c));
    }
    n = va.size();
    m = vb.size();
    if( m == 1 ){
        for( i = 0; i < n; i++ ){
            if( va[i].se != vb[0].se )continue;
            cnt += max(0ll, va[i].fi - vb[0].fi + 1);
        }
        pr( "%I64d\n", cnt );
        return 0;
    }
    vb.pb(mp(0, '#'));
    for( i = 0; i < n; i++ )vb.pb(va[i]);
    for( i = 1; i < vb.size(); i++ ){
        j = p[i - 1];
        while( j > 0 && !M(vb[j], vb[i], j) )j--;
        if( M(vb[j], vb[i], j) )j++;
        p[i] = j;
        if( p[i] == m )cnt++;
    }
    pr( "%I64d\n", cnt );
}