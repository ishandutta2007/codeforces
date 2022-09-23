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
#define fin freopen( "shield.in", "r", stdin );
#define fout freopen( "shield.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int n, m, k, d[1111][1111];
char c[1111][1111];
bool used[1111][1111], used1[1111][1111];

void dfs( int x, int y, int cnt )
{
    if( used[x][y] || x < 1 || y < 1 || x > n || y > m || c[x][y] == '*' )return;
    d[x][y] = cnt;
    used[x][y] = true;
    dfs( x + 1, y, cnt );
    dfs( x - 1, y, cnt );
    dfs( x, y - 1, cnt );
    dfs( x, y + 1, cnt );
}

int dfs1( int x, int y )
{
    if( used1[x][y] )return 0;
    if( c[x][y] == '*' )return 1;
    used1[x][y] = true;
    return dfs1( x + 1, y ) + dfs1( x - 1, y ) + dfs1( x, y - 1 ) + dfs1( x, y + 1 );
}

int main()
{
    int i, j, h, x, y;
    cin >> n >> m >> k;
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= m; j++ ){
            cin >> c[i][j];
        }
    }
    for( i = n; i >= 1; i-- ){
        for( j = m; j >= 1; j-- ){
            if( c[i][j] == '.' && !used1[i][j] ){
                dfs(i, j, dfs1(i, j));
            }
        }
    }
    for( i = 1; i <= k; i++ ){
        sc( "%d%d", &x, &y );
        pr( "%d\n", d[x][y] );
    }
}