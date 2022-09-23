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

using namespace std;

lli n, a, b, cnt, T, i, j, h, m, ans, x, cur, l, r;
lli suf[500005];
char c[500005];

int main()
{
    sc( "%d%d%d%d", &n, &a, &b, &T );
    for( i = 0; i <= n; i++ )sc( "%c", &c[i] );
    for( h = 1; h <= 2; h++ ){
        cur = 0;
        suf[n] = 1;
        if( c[n] == 'w' )suf[n] += b;
        for( i = n - 1; i >= 1; i-- ){
            suf[i] = suf[i + 1] + a + 1;
            if( c[i] == 'w' )suf[i] += b;
        }
        for( i = 1; i <= n; i++ ){
            cur = cur + 1;
            if( i > 1 )cur = cur + a;
            if( c[i] == 'w' )cur = cur + b;
            if( cur > T )break;
            x = T - cur - a * i;
            l = i + 1;
            r = n + 1;
            while( l < r ){
                m = (l + r) / 2;
                if( suf[m] > x )l = m + 1;
                else r = m;
            }
            ans = max(ans, i + n - l + 1);
        }
        for( i = 2; i <= n / 2 + 1; i++ )swap(c[i], c[n - i + 2]);
    }
    pr( "%d", ans );
}