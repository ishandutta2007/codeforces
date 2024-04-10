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
const lli N = 200002;
using namespace std;

lli n, m, v[4 * N];
pair < pair < lli, lli >, lli > p[N];
set < pair < lli, lli > > s;
set < pair < lli, lli > > :: iterator it;
pair < lli, lli > ans[N];
map < pair < lli, lli >, lli > used;

void build( lli x, lli l, lli r )
{
    if( l == r ){
        v[x] = p[l].fi.se;
        return;
    }
    lli m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    v[x] = max(v[x * 2], v[x * 2 + 1]);
}

lli get( lli x, lli l, lli r, lli y )
{
    if( l == r )return l;
    lli m = (l + r) / 2;
    if( y <= v[x * 2] )return get(x * 2, l, m, y);
    else return get(x * 2 + 1, m + 1, r, y);
}

void doit( lli x, lli l, lli r, lli in )
{
    if( l == r ){
        v[x] = p[l].fi.se;
        return;
    }
    lli m = (l + r) / 2;
    if( in <= m )doit(x * 2, l, m, in);
    else doit(x * 2 + 1, m + 1, r, in);
    v[x] = max(v[x * 2], v[x * 2 + 1]);
}

int main()
{
    lli i, j, h, x, y;
    sc( "%I64d%I64d", &n, &m );
    for( i = 1; i <= n; i++ ){
        sc( "%I64d%I64d", &p[i].fi.fi, &p[i].fi.se );
        p[i].fi.se += p[i].fi.fi;
        p[i].se = i;
    }
    s.insert(mp(1e18, 1e18));
    sort( p + 1, p + n + 1 );
    build(1, 1, n);
    for( i = 1; i <= m; i++ ){
        sc( "%I64d%I64d", &x, &y );
        lli in = get(1, 1, n, x);
        if( p[in].fi.fi <= x && x <= p[in].fi.se ){
            ans[p[in].se].fi++;
            p[in].fi.se += y;
            doit(1, 1, n, in);
            while( s.size() > 1 ){
                it = s.lower_bound(mp(p[in].fi.se + 1, -1));
                if( it != s.begin() )it--;
                if( it->fi > p[in].fi.se )break;
                if( p[in].fi.fi <= it->fi ){
                    ans[p[in].se].fi += used[mp(it->fi, it->se)];
                    p[in].fi.se += it->se * used[mp(it->fi, it->se)];
                    used[mp(it->fi, it->se)] = 0;
                    doit(1, 1, n, in);
                    s.erase(it);
                }
                else break;
            }
        }
        else{
            s.insert(mp(x, y));
            used[mp(x, y)]++;
        }
    }
    for( i = 1; i <= n; i++ )ans[p[i].se].se = p[i].fi.se - p[i].fi.fi;
    for( i = 1; i <= n; i++ )pr( "%I64d %I64d\n", ans[i].fi, ans[i].se );
}