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

const int N = (1 << 17) + 2;

using namespace std;

int t[4 * N], n, a[N];

int build( int x, int l, int r )
{
    if( l == r ){
        t[x] = a[l];
        return 0;
    }
    int m = (l + r) / 2;
    int cnt = build(x * 2, l, m) + 1;
    build(x * 2 + 1, m + 1, r);
    if( cnt % 2 )t[x] = t[x * 2] | t[x * 2 + 1];
    else t[x] = t[x * 2] ^ t[x * 2 + 1];
    return cnt;
}

int update( int x, int l, int r, int g, int y )
{
    if( l == r ){
        t[x] = y;
        return 0;
    }
    int m = (l + r) / 2;
    int cnt;
    if( g <= m )cnt = update(x * 2, l, m, g, y) + 1;
    else cnt = update(x * 2 + 1, m + 1, r, g, y) + 1;
    if( cnt % 2 )t[x] = t[x * 2] | t[x * 2 + 1];
    else t[x] = t[x * 2] ^ t[x * 2 + 1];
    return cnt;
}

int main()
{
    int i, x, y, m;
    sc( "%d%d", &n, &m );
    n = (1 << n);
    for( i = 1; i <= n; i++ )sc( "%d", &a[i] );
    build(1, 1, n);
    for( i = 1; i <= m; i++ ){
        sc( "%d%d", &x, &y );
        update(1, 1, n, x, y);
        pr( "%d\n", t[1] );
    }
}