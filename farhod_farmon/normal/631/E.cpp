#include <bits/stdc++.h>

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

const int N = 200002;

using namespace std;

lli sum[N], a[N], n, ans, mx = 0;

lli M( lli x, lli y )
{
    if( x < y )return (y - x + 1) * 1ll * a[x] - sum[y] + sum[x - 1];
    return (y - x) * 1ll * a[x] + sum[x - 1] - sum[y - 1];
}

lli take( lli l, lli r, lli x )
{
    lli i, h1, h2, m, cnt = 0;
    while( l + 2 < r ){
        m = (r - l) / 3ll;
        h1 = l + m;
        h2 = r - m;
        if( M(x, h1) >= M(x, h2) )r = h2;
        else l = h1;
    }
    for( i = l; i <= r; i++ ){
        cnt = max(cnt, M(x, i));
    }
    return cnt;
}

int main()
{
    lli i;
    sc( "%I64d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%I64d", &a[i] );
        sum[i] = sum[i - 1] + a[i];
        ans = ans + a[i] * i;
    }
    for( i = 1; i <= n; i++ ){
        mx = max(mx, take(1, i - 1, i));
        mx = max(mx, take(i + 1, n, i));
    }
    pr( "%I64d", ans + mx );
}