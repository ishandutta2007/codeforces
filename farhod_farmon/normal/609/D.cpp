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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
lli l, r, n, m, k, s, a, b, c[200002], d[200002];
pair < lli, lli > p, mn[3][200002];
vector < pair < lli, lli > > v[3];
vector < pair < lli, lli > > ans;

bool f( lli x )
{
    lli i = 0, j = 0, h = 0, g1 = k;
    while( g1 ){
        if( i < v[1].size() ){
            if( j < v[2].size() ){
                if( v[1][i].fi * mn[1][x].fi < v[2][j].fi * mn[2][x].fi ){
                    h += v[1][i++].fi * mn[1][x].fi;
                }
                else{
                    h += v[2][j++].fi * mn[2][x].fi;
                }
            }
            else{
                h += v[1][i++].fi * mn[1][x].fi;
            }
        }
        else{
            h += v[2][j++].fi * mn[2][x].fi;
        }
        g1--;
    }
    return h <= s;
}

int main()
{
    lli i, j, h;
    sc( "%I64d%I64d%I64d%I64d", &a, &b, &k, &s );
    for( i = 1; i <= a; i++ ){
        sc( "%I64d", &c[i] );
        if( i == 1 )mn[1][i] = mp(c[i], 1);
        else{
            if( c[i] < mn[1][i - 1].fi )mn[1][i] = mp(c[i], i);
            else mn[1][i] = mn[1][i - 1];
        }
    }
    for( i = 1; i <= a; i++ ){
        sc( "%I64d", &d[i] );
        if( i == 1 )mn[2][i] = mp(d[i], 1);
        else{
            if( d[i] < mn[2][i - 1].fi )mn[2][i] = mp(d[i], i);
            else mn[2][i] = mn[2][i - 1];
        }
    }
    for( i = 1; i <= b; i++ ){
        sc( "%I64d%I64d", &p.fi, &p.se );
        v[p.fi].pb(mp(p.se, i));
    }
    sort( v[1].begin(), v[1].end() );
    sort( v[2].begin(), v[2].end() );
    l = 1;
    r = a + 1;
    while( l < r ){
        m = (l + r) / 2;
        if( !f(m) )l = m + 1;
        else r = m;
    }
    if( l == a + 1 ){
        pr( "-1" );
        return 0;
    }
    pr( "%d\n", l );
    lli g1 = k, x = l;
    i = j = 0;
    while( g1 ){
        if( i < v[1].size() ){
            if( j < v[2].size() ){
                if( v[1][i].fi * mn[1][x].fi < v[2][j].fi * mn[2][x].fi )ans.pb(mp(v[1][i++].se, mn[1][x].se));
                else ans.pb(mp(v[2][j++].se, mn[2][x].se));
            }
            else ans.pb(mp(v[1][i++].se, mn[1][x].se));
        }
        else ans.pb(mp(v[2][j++].se, mn[2][x].se));
        g1--;
    }
    for( i = 0; i < ans.size(); i++ )pr( "%I64d %I64d\n", ans[i].fi, ans[i].se );

}