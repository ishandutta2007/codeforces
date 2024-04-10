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

const int N = 100100;

using namespace std;

lli n, k, a[N], b[N];

bool f( lli x )
{
    lli q = k;
    for( lli i = 1; i <= n; i++ ){
        lli g = a[i] * x;
        if( g <= b[i] )
            continue;
        q -= g - b[i];
        if( q < 0 )
            return false;
    }
    return q >= 0;
}

int main()
{
    lli r = 0;
    sc( "%I64d%I64d", &n, &k );
    for( lli i = 1; i <= n; i++ )
        sc( "%I64d", &a[i] );
    for( lli i = 1; i <= n; i++ ){
        sc( "%I64d", &b[i] );
        r = max(r, (b[i] + k) / a[i]);
    }
    lli l = 0;
    while( l < r ){
        lli m = (l + r) / 2;
        if( f(m + 1) )
            l = m + 1;
        else
            r = m;
    }
    pr( "%I64d\n", l );
}