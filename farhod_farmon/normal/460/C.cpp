#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 200200;

using namespace std;

lli n, m, w;
lli a[N], d[N];

bool f( lli x )
{
    lli g = 0, cnt = 0;
    for( int i = 1; i <= n; i++ )
        d[i] = 0;
    for( int i = 1; i <= n; i++ ){
        lli y = a[i] + cnt;
        if( y < x )
            d[i] = x - y;
        cnt += d[i];
        if( i >= w )
            cnt -= d[i - w + 1];
        g += d[i];
    }
    return g <= m;
}

int main()
{
    sc( "%I64d%I64d%I64d", &n, &m, &w );
    for( int i = 1; i <= n; i++ )
        sc( "%I64d", &a[i] );
    lli l = 1, r = 2e9;
    while( l < r ){
        lli tm = (l + r) / 2;
        if( f(tm + 1) )
            l = tm + 1;
        else
            r = tm;
    }
    pr( "%I64d\n", l );
}