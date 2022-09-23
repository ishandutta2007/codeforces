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
int ans[300001], n, m, v[2000000];
vector < int > g;

void build( int l, int r, int x )
{
    int m = (l + r) / 2;
    if( l == r ){
        v[x] = l;
        return;
    }
    build( l, m, x * 2 );
    build( m + 1, r, x * 2 + 1 );
}

void d( int l, int r, int ll, int rr, int x, int k )
{
    if( ll > rr )return;
    if( l == ll && r == rr ){
        if( v[x] ){
            g.pb(v[x]);
            v[x] = k;
            return;
        }
        v[x] = k;
    }
    int m = (l + r) / 2;
    d( l, m, ll, min(m, rr), x * 2, k );
    d( m + 1, r, max(ll, m + 1), rr, x * 2 + 1, k );
}

int main()
{
    int l, r, x, i, j;
    sc( "%d%d", &n, &m );
    build(1, n, 1);
    for( i = 1; i <= m; i++ ){
        sc( "%d%d%d", &l, &r, &x );
        g.clear();
        d( 1, n, l, r, 1, x );
        for( j = 0; j < g.size(); j++ )ans[g[j]] = !ans[g[j]] || ans[g[j]] == g[j] ? x : ans[g[j]];
    }
    for( i = 1; i <= n; i++ )pr( "%d ", ans[i] == i ? 0 : ans[i] );
}