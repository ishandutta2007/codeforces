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
lli n, m, d[N], p[N], ans[N], timer = 0, tin[N], tout[N], up[N][32], l, dep[N], maxn[N][32];
pair < pair < lli, lli >, pair < lli, lli > > g[N];
vector < pair < lli, lli > > v[N];

lli get( lli x )
{
    return x == p[x] ? x : (p[x] = get(p[x]));
}

void dfs( lli x, lli p = 1, lli cost = 0 )
{
    tin[x] = timer++;
    lli i, j;
    up[x][0] = p;
    maxn[x][0] = cost;
    for( i = 1; i <= 17; i++ ){
        up[x][i] = up[up[x][i - 1]][i - 1];
        maxn[x][i] = max(maxn[x][i - 1], maxn[up[x][i - 1]][i - 1]);
    }
    for( i = 0; i < v[x].size(); i++ ){
        if( v[x][i].fi == p )continue;
        dep[v[x][i].fi] = dep[x] + 1;
        dfs(v[x][i].fi, x, v[x][i].se);
    }
    tout[x] = timer++;
}

bool isp( lli a, lli b )
{
    return tin[a] < tin[b] && tout[a] > tout[b];
}

lli get_lca( lli a, lli b )
{
    if( isp(a, b) )return a;
    if( isp(b, a) )return b;
    for( lli i = 17; i >= 0; i-- ){
        if( !isp(up[a][i], b) ){
            a = up[a][i];
        }
    }
    return up[a][0];
}

lli get_max( lli a, lli h )
{
    lli i, cnt = 0;
    for( i = 17; i >= 0; i-- ){
        if( h >= (1 << i) ){
            h -= (1 << i);
            cnt = max(cnt, maxn[a][i]);
            a = up[a][i];
        }
    }
    return cnt;
}

int main()
{
    lli i, j, h, cnt = 0;
    sc( "%I64d%I64d", &n, &m );
    for( i = 1; i <= m; i++ ){
        sc( "%I64d%I64d%I64d", &g[i].se.fi, &g[i].se.se, &g[i].fi.fi );
        g[i].fi.se = i;
    }
    sort( g + 1, g + m + 1 );
    for( i = 1; i <= n; i++ )p[i] = i;
    for( i = 1; i <= m; i++ ){
        lli x = g[i].se.fi, y = g[i].se.se, cost = g[i].fi.fi;
        if( get(x) != get(y) ){
            p[get(x)] = get(y);
            cnt += cost;
            v[x].pb(mp(y, cost));
            v[y].pb(mp(x, cost));
        }
    }
    dfs(1);
    lli allcost = cnt;
    for( i = 1; i <= m; i++ ){
        lli x = g[i].se.fi, y = g[i].se.se, cost = g[i].fi.fi;
        lli P = get_lca(x, y);
        cnt = max(get_max(x, dep[x] - dep[P]), get_max(y, dep[y] - dep[P]));
        ans[g[i].fi.se] = allcost - cnt + cost;
    }
    for( i = 1; i <= m; i++ )pr( "%I64d\n", ans[i] );
}