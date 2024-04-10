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

const int N = 100001;

using namespace std;

int n, k, ans[N], p[N][20], dep[N], tin[N], tout[N], tim, d[N], lem = 0;
vector < pair < int, int > > v[N];
vector < int > g[N];
pair < int, int > li[N];

void dfs( int x, int pre = 0, int gg = 0 )
{
    if( !pre )pre = x;
    tin[x] = ++tim;
    dep[x] = dep[pre] + 1;
    g[dep[x]].pb(x);
    li[x] = mp(pre, gg);
    p[x][0] = pre;
    for( int j = 1; j < 20; j++ ){
        p[x][j] = p[p[x][j - 1]][j - 1];
    }
    for( int i = 0; i < v[x].size(); i++ ){
        if( v[x][i].fi == pre )continue;
        dfs(v[x][i].fi, x, v[x][i].se);
    }
    tout[x] = ++tim;
}

bool isp( int x, int y )
{
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int P( int x, int y )
{
    if( isp(x, y) )return x;
    if( isp(y, x) )return y;
    for( int i = 19; i >= 0; i-- ){
        if( !isp(p[x][i], y) ){
            x = p[x][i];
        }
    }
    return p[x][0];
}

int main()
{
    int x, y, i, j, h;
    sc( "%d", &n );
    for( i = 1; i < n; i++ ){
        sc( "%d%d", &x, &y );
        v[x].pb(mp(y, i));
        v[y].pb(mp(x, i));
    }
    dfs(1);
    sc( "%d", &k );
    for( i = 1; i <= k; i++ ){
        sc( "%d%d", &x, &y );
        d[x]++;
        d[y]++;
        d[P(x, y)] -= 2;
    }
    for( i = n; i >= 1; i-- ){
        for( j = 0; j < g[i].size(); j++ ){
            d[li[g[i][j]].fi] += d[g[i][j]];
            ans[li[g[i][j]].se] += d[g[i][j]];
        }
    }
    for( i = 1; i < n; i++ )pr( "%d ", ans[i] );
}