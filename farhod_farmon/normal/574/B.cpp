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
int a, b, u[4001], ans = -1;
vector < int > v[4001], g;
bool d[4001][4001], used[4001][4001];

void dfs( int x )
{
    if( g.size() > 2 ){
        int gg = g.size() - 1;
        int x = g[gg], y = g[gg - 1], z = g[gg - 2];
        if( d[x][z] ){
            if( ans > u[x] + u[y] + u[z] - 6 || ans == -1 )ans = u[x] + u[y] + u[z] - 6;
        }
    }
    if( g.size() > 1 ){
        int gg = g.size() - 1;
        int x = g[gg], y = g[gg - 1];
        if( used[x][y] )return;
        used[x][y] = true;
    }
    int i;
    for( i = 0; i < v[x].size(); i++ ){
        g.pb(v[x][i]);
        dfs( v[x][i] );
        g.p_b();
    }
}

int main()
{
    int x, y, i, j;
    cin >> a >> b;
    for( i = 1; i <= b; i++ ){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
        u[x]++,u[y]++;
        d[x][y] = d[y][x] = true;
    }
    for( i = 1; i <= a; i++ ){
        g.pb(i);
        dfs(i);
        g.p_b();
    }
    cout << ans;
}