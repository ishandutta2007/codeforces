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

const int N = 500005;

using namespace std;

int n, ans;
vector < int > v[N], g;

void dfs( int x, int p, int d )
{
    for( int i = 0; i < v[x].size(); i++ ){
        int to = v[x][i];
        if( to != p )dfs(to, x, d + 1);
    }
    if( v[x].size() == 1 )g.pb(d);
}

int main()
{
    int i, j, x, y;
    sc( "%d", &n );
    for( i = 1; i < n; i++ ){
        sc( "%d%d", &x, &y );
        v[x].pb(y);
        v[y].pb(x);
    }
    for( i = 0; i < v[1].size(); i++ ){
        x = v[1][i];
        g.clear();
        dfs(x, 1, 1);
        sort( g.begin(), g.end() );
        for( j = 1; j < g.size(); j++ )g[j] = max(g[j], g[j - 1] + 1);
        ans = max(ans, g[j - 1]);
    }
    pr( "%d\n", ans );
}