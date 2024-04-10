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
#define fin freopen( "cipher.in", "r", stdin );
#define fout freopen( "cipher.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int n, p[100001], i, j, h, f1, f2;
vector < pair < int, int > > v;
bool used[100001];

void dfs( int x, int y, int g )
{
    if( used[y] ){
        if( g % 2 == 1 ){
            pr( "NO\n" );
            exit(0);
        }
        return;
    }
    used[x] = used[y] = true;
    v.pb({x, y});
    dfs(p[x], p[y], g + 1);
}

int main()
{
    sc( "%d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &p[i] );
        if( p[i] == i )f1 = i;
        if( p[p[i]] == i )f2 = i;
    }
    if( f1 ){
        pr( "YES\n" );
        for( i = 1; i <= n; i++ ){
            if( i != f1 )pr( "%d %d\n", f1, i );
        }
    }
    else if( f2 ){
        v.pb({f2, p[f2]});
        used[f2] = used[p[f2]] = true;
        for( i = 1; i <= n; i++ ){
            if( !used[i] ){
                dfs( f2, i, 0 );
            }
        }
        pr( "YES\n" );
        for( i = 0; i < v.size(); i++ )pr( "%d %d\n", v[i].fi, v[i].se );
    }
    else pr( "NO\n" );
}