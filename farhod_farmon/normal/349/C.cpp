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

lli n, a, l, r = 1e13, m, mx, sum;

bool f( lli x )
{
    lli cnt = n * x - sum;
    if( x < mx )
        return false;
    return cnt >= x;
}

int main()
{
    sc( "%I64d", &n );
    for( int i = 0; i < n; i++ ){
        sc( "%I64d", &a );
        mx = max(mx, a);
        sum += a;
    }
    while( l < r ){
        m = (l + r) / 2;
        if( !f(m) )
            l = m + 1;
        else
            r = m;
    }
    pr( "%I64d\n", l );
}