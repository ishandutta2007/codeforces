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

lli x, y, n, cnt, i, j, h, a[200002];

int main()
{
    sc( "%I64d%I64d%I64d", &n, &x, &y );
    for( i = 1; i <= n; i++ )
        sc( "%I64d", &a[i] );
    sort( a + 1, a + n + 1 );
    for( i = 1; i <= n; i++ ){
        h = min(a[i] / 2, x);
        x -= h;
        a[i] -= 2 * h;
        h = min(a[i], y);
        y -= h;
        a[i] -= h;
        h = min((a[i] + 1) / 2, x);
        x -= h;
        a[i] -= 2 * h;
        a[i] = max(a[i], 0ll);
        if( a[i] )
            break;
        cnt++;
    }
    pr( "%I64d\n", cnt );
}