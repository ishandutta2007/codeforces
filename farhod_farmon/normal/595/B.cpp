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
lli n, k, i, j, h, ans = 1ll, x, y, a[100001], b[100001], inf = 1e9 + 7;

lli f1( lli d, lli g )
{
    while(g-->0)d *= 10;
    return d - 1;
}

int main()
{
    sc( "%I64d%I64d", &n, &k );
    for( i = 1; i <= n / k; i++ )sc( "%I64d", &a[i] );
    for( i = 1; i <= n / k; i++ )sc( "%I64d", &b[i] );
    for( i = 1; i <= n / k; i++ ){
        x = f1(1, k) / a[i] - f1(1, k - 1) / a[i];
        if( b[i] )y = f1(b[i] + 1, k - 1) / a[i] - f1(b[i], k - 1) / a[i];
        else y = 0;
        if( b[i] )x += f1(1, k - 1) / a[i] + 1;
        ans *= x - y;
        ans %= inf;
    }
    pr( "%I64d\n", ans );
}