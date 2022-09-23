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

const int N = 200002;

using namespace std;

lli n;
lli t[N * 4][2], tin[N], tout[N], tim, dip[N], a[N];
vector < lli > v[N];

void dfs( lli x, lli p = -1 )
{
    tin[x] = tout[x] = ++tim;
    for( lli i = 0; i < v[x].size(); i++ ){
        lli to = v[x][i];
        if( to == p )
            continue;
        dip[to] = dip[x] + 1;
        dfs(to, x);
        tout[x] = tout[to];
    }
}

void up( lli x, lli l, lli r, lli tl, lli tr, lli y, lli val )
{
    if( tl > tr )
        return;
    if( l == tl && r == tr ){
        t[x][y] += val;
        return;
    }
    lli tm = (l + r) / 2;
    up( x * 2, l, tm, tl, min(tm, tr), y, val );
    up( x * 2 + 1, tm + 1, r, max(tm + 1, tl), tr, y, val );
}

lli get( lli x, lli l, lli r, lli g, lli y )
{
    if( l == r )
        return t[x][y] - t[x][y ^ 1];
    lli tm = (l + r) / 2;
    if( g <= tm )
        return t[x][y] - t[x][y ^ 1] + get(x * 2, l, tm, g, y);
    else
        return t[x][y] - t[x][y ^ 1] + get(x * 2 + 1, tm + 1, r, g, y);
}

int main()
{
    lli x, y, val, i, m;
    sc( "%I64d%I64d", &n, &m );
    for( i = 1; i <= n; i++ )
        sc( "%I64d", &a[i] );
    for( i = 1; i < n; i++ ){
        sc( "%I64d%I64d", &x, &y );
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
    for( i = 1; i <= m; i++ ){
        sc( "%I64d", &y );
        if( y == 1 ){
            sc( "%I64d%I64d", &x, &val );
            up(1, 1, n, tin[x], tout[x], dip[x] % 2, val);
        }
        else{
            sc( "%I64d", &x );
            pr( "%I64d\n", a[x] + get(1, 1, n, tin[x], dip[x] % 2) );
        }
    }
}