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

const int N = 300003;

using namespace std;

int n, mx;
int par[N], d[N], dep[N];
vector < int > v[N];

void dfs( int x, int p, int col )
{
    if( p != -1 )
        dep[x] = dep[p] + 1;
    par[x] = col;
    for( int i = 0; i < v[x].size(); i++ )
        if( v[x][i] != p )
            dfs(v[x][i], x, col);
    if( dep[x] > dep[mx] )
        mx = x;
}

int get( int x )
{
    if( par[x] == x )
        return par[x];
    return par[x] = get(par[x]);
}

void mg( int x, int y )
{
    x = get(x);
    y = get(y);
    if( x == y )
        return;
    par[y] = x;
    int f1 = d[x], f2 = d[y];
    d[x] = (d[x] + 1) / 2 + (d[y] + 1) / 2 + 1;
    d[x] = max(d[x], max(f1, f2));
}

int main()
{
    ios_base::sync_with_stdio(0);
    int m, q;
    sc( "%d%d%d", &n, &m, &q );
    for( int i = 1; i <= m; i++ ){
        int x, y;
        sc( "%d%d", &x, &y );
        v[x].pb(y);
        v[y].pb(x);
    }
    int col = 0;
    for( int i = 1; i <= n; i++ ){
        if( par[i] == 0 ){
            mx = 0;
            dfs(i, -1, i);
            dep[mx] = 0;
            dfs(mx, -1, i);
            d[i] = dep[mx];
        }
    }
    for( int i = 1; i <= q; i++ ){
        int x, y, t;
        sc( "%d", &t );
        if( t == 1 ){
            sc( "%d", &x );
            pr( "%d\n", d[get(x)] );
        }
        else{
            sc( "%d%d", &x, &y );
            mg(x, y);
        }
    }
}