#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <iomanip>

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

const int N = 400004;

using namespace std;

int n, tin[N], tout[N], tim, pos[N];
vector < int > v[N];
lli col[N], t[4 * N], t1[4 * N];

void dfs( int x, int p = -1 )
{
    tin[x] = ++tim;
    pos[tim] = x;
    for( int i = 0; i < v[x].size(); i++ ){
        if( v[x][i] == p )continue;
        dfs(v[x][i], x);
    }
    tout[x] = tim;
}

void build( int x, int l, int r )
{
    if( l == r ){
        t[x] = (1ll << col[pos[l]]);
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x] = t[x * 2] | t[x * 2 + 1];
}

void up( int x, int l, int r, int tl, int tr, int c )
{
    if( tl > tr )return;
    if( l == tl && r == tr ){
        t[x] = (1ll << c);
        t1[x] = (1ll << c);
        return;
    }
    if( t1[x] ){
        t[x * 2] = t[x * 2 + 1] = t1[x * 2] = t1[x * 2 + 1] = t1[x];
        t1[x] = 0;
    }
    int m = (l + r) / 2;
    up(x * 2, l, m, tl, min(m, tr), c);
    up(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, c);
    t[x] = t[x * 2] | t[x * 2 + 1];
}

lli get( int x, int l, int r, int tl, int tr )
{
    if( tl > tr )return 0;
    if( l == tl && r == tr )return t[x];
    if( t1[x] ){
        t[x * 2] = t[x * 2 + 1] = t1[x * 2] = t1[x * 2 + 1] = t1[x];
        t1[x] = 0;
    }
    int m = (l + r) / 2;
    return get(x * 2, l, m, tl, min(m, tr)) | get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

int main()
{
    int i, h, x, y, m;
    sc( "%d%d", &n, &m );
    for( i = 1; i <= n; i++ )sc( "%d", &col[i] );
    for( i = 1; i < n; i++ ){
        sc( "%d%d", &x, &y );
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
    build(1, 1, n);
    for( i = 1; i <= m; i++ ){
        sc( "%d", &h );
        if( h == 1 ){
            sc( "%d%d", &x, &y );
            up(1, 1, n, tin[x], tout[x], y);
        }
        else{
            sc( "%d", &x );
            lli g = get(1, 1, n, tin[x], tout[x]), cnt = 0;
            while( g ){
                cnt += g % 2;
                g /= 2;
            }
            pr( "%d\n", cnt );
        }
    }
}