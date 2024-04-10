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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "pwgen.in", "r", stdin );
#define fout freopen( "pwgen.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
#define INF 1000000000000000000ll
using namespace std;
int a, y, b[100001], c[100001], d[100001], f[100001], ans;
vector < int > v;

int dfs( int x )
{
    if( d[x] != 1 || b[x] )return 0;
    if( f[x] )return f[x];
    if( x )f[x] = dfs(c[x]) + 1;
    return f[x];
}

int main()
{
    sc( "%d", &a );
    for( int i = 1; i <= a; i++ )sc( "%d", &b[i] );
    for( int i = 1; i <= a; i++ ){
        sc( "%d", &c[i] );
        d[c[i]]++;
    }
    for( int i = 1; i <= a; i++ ){
        if( b[i] ){
            f[i] = dfs(c[i]) + 1;
            if( f[i] > ans )ans = f[i], y = i;
        }
    }
    pr( "%d\n", ans );
    while( ans ){
        v.pb(y);
        y = c[y];
        ans--;
    }
    for( int i = v.size() - 1; i >= 0; i-- )pr( "%d ", v[i] );
}