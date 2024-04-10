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
lli n, k, b[100001], d[400001][12];

void up( lli l, lli r, lli v, lli x, lli ind, lli cnt )
{
    if( l == r ){
        d[v][ind] = cnt;
        return;
    }
    lli m = (l + r) / 2;
    if( x <= m )up(l, m, v * 2, x, ind, cnt);
    else up(m + 1, r, v * 2 + 1, x, ind, cnt);
    d[v][ind] = d[v * 2][ind] + d[v * 2 + 1][ind];
}

lli get( lli l, lli r, lli v, lli l1, lli r1, lli ind )
{
    if( l1 > r1 )return 0;
    if( l == l1 && r == r1 )return d[v][ind];
    lli m = (l + r) / 2;
    return get(l, m, v * 2, l1, min(m, r1), ind) + get(m + 1, r, v * 2 + 1, max(m + 1, l1), r1, ind);
}

int main()
{
    lli i, j, h;
    sc( "%d%d", &n, &k );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &b[i] );
    }
    for( i = 1; i <= n; i++ ){
        for( j = 0; j <= k; j++ ){
            if( !j )up(1, n, 1, b[i], j, 1);
            else up(1, n, 1, b[i], j, get(1, n, 1, 1, b[i] - 1, j - 1));
        }
    }
    lli ans = get(1, n, 1, 1, n, k);
    cout << ans << endl;    
}