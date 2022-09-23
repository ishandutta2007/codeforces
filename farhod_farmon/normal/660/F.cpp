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

const int N = 200002;

using namespace std;

lli s[N], f[N], n, ans, le;

pair < long double, long double > c[N];

long double per( pair < long double, long double > x, pair < long double, long double > y )
{
    return (y.se - x.se) / (x.fi - y.fi);
}

void add( pair < long double, long double > x )
{
    while( le > 1 && per(c[le], c[le - 1]) < per(x, c[le - 1]) )
        le--;
    c[++le] = x;
}

lli get( lli x )
{
    lli l = 1, r = le;
    while( l < r ){
        lli m = (l + r) / 2;
        if( per(c[m], c[m + 1]) > x )
            l = m + 1;
        else
            r = m;
    }
    return c[l].fi * x + c[l].se;
}

int main()
{
    lli i, j, x;
    sc( "%I64d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%I64d", &x );
        s[i] = s[i - 1] + x;
        f[i] = f[i - 1] + x * i;
        add(mp(1 - i, (i - 1) * s[i - 1] - f[i - 1]));
        ans = max(ans, get(s[i]) + f[i]);
        ans = max(ans, f[i]);
    }
    pr( "%I64d", ans );
}