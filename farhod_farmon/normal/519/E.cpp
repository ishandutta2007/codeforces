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

const int N = 100011;

using namespace std;

int n;
int tim;
int sz[N];
int dep[N];
int tin[N];
int tout[N];
int up[N][20];
vector < int > v[N];

void dfs( int x, int p )
{
    tin[x] = tim++;
    dep[x] = dep[p] + 1;
    up[x][0] = p;
    sz[x] = 1;
    for( int i = 1; i < 20; i++ )
        up[x][i] = up[up[x][i - 1]][i - 1];
    for( int i = 0; i < v[x].size(); i++ )
        if( v[x][i] != p )
            dfs(v[x][i], x),
            sz[x] += sz[v[x][i]];
    tout[x] = tim++;
}

bool isp( int a, int b )
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int get( int a, int b )
{
    if( isp(a, b) )
        return a;
    if( isp(b, a) )
        return b;
    for( int i = 19; i >= 0; i-- )
        if( !isp(up[a][i], b) )
            a = up[a][i];
    return up[a][0];
}

int getx( int a, int g )
{
    for( int i = 19; i >= 0; i-- )
        if( g >= (1 << i) )
            g -= (1 << i),
            a = up[a][i];
    return a;
}

int solve( int a, int b )
{
    if( a == b )
        return n;
    int p = get(a, b);
    int g = dep[a] - dep[p] + dep[b] - dep[p];
    if( g % 2 )
        return 0;
    if( dep[a] - g / 2 < dep[p] )
        swap(a, b);
    int x = getx(a, g / 2);
    int cnt = 0;
    if( !isp(x, a) )
        cnt += n - sz[x];
    else
        cnt += sz[getx(a, dep[a] - dep[x] - 1)];
    if( !isp(x, b) )
        cnt += n - sz[x];
    else
        cnt += sz[getx(b, dep[b] - dep[x] - 1)];
    return n - cnt;
}

int main()
{
    cin >> n;
    for( int i = 1; i < n; i++ ){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int t;
    dfs(1, 1);
    cin >> t;
    while( t-- ){
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
}