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
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, m, ans, d[100001];
int used[100001];
vector < int > v[100001], v1[100001];

void dfs( int x, int g )
{
    if( g > m )return;
    for( int i = 0; i < v[x].size(); i++ ){
        if( used[v[x][i]] )dfs( v[x][i], g + 1 );
        else dfs( v[x][i], 0 );
    }
    if( !v[x].size() )ans++;
}

void dfs1( int x, int g )
{
    if( g > d[x] )return;
    d[x] = g;
    v[x].clear();
    for( int i = 0; i < v1[x].size(); i++ ){
        dfs1(v1[x][i], g + 1);
        if( d[x] < d[v1[x][i]] )v[x].pb(v1[x][i]);
    }
}

int main()
{
    int x, y, i;
    sc( "%d%d", &a, &m );
    for( i = 1; i <= a; i++ ){
        sc( "%d", &used[i] );
        d[i] = 1e7;
    }
    for( i = 1; i <= a - 1; i++ ){
        sc( "%d%d", &x, &y );
        v1[x].pb(y);
        v1[y].pb(x);
    }
    dfs1(1, 0);
    dfs(1, used[1]);
    pr( "%d", ans );
}