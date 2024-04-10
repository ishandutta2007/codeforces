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

using namespace std;

lli n, k, a[100001], b[100001];

bool f( lli x )
{
    lli i, j, r;
    for( i = j = 1; i <= n && j <= k; i++ ){
        if( a[i] - b[j] > x )
            return false;
        if( b[j] > a[i] )
            r = a[i] + x;
        else
            r = a[i] + max((x - (a[i] - b[j])) / 2ll, x - 2ll * (a[i] - b[j]));
        while( j <= k && b[j] <= r )
            j++;
    }
    return j > k;
}

int main()
{
    lli i, j, l = 0, r = 1e11, m;
    sc( "%I64d%I64d", &n, &k );
    for( i = 1; i <= n; i++ )
        sc( "%I64d", &a[i] );
    for( i = 1; i <= k; i++ )
        sc( "%I64d", &b[i] );
    while( l < r ){
        m = (l + r) / 2ll;
        if( !f(m) )
            l = m + 1;
        else
            r = m;
    }
    pr( "%I64d", l );
}