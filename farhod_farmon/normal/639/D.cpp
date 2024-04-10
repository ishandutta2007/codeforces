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

lli n, k, b, c, i, j, h, a[200002];
lli ans = 1e18;
pair < lli, lli  > t[200002];

lli take( lli x, lli y )
{
    while( (x % 5 + 5) % 5 != y )
        x++;
    return x;
}

int main()
{
    sc( "%I64d%I64d%I64d%I64d", &n, &k, &b, &c );
    for( i = 1; i <= n; i++ )
        sc( "%I64d", &a[i] );
    b = min(b, c * 5);
    sort( a + 1, a + n + 1 );
    for( h = 0; h < 5; h++ ){
        set < pair < lli, lli > > s;
        lli sum = 0;
        for( i = 1; i <= n; i++ ){
            t[i].fi = take(a[i], h);
            t[i].se = (t[i].fi - a[i]) * c;
        }
        for( i = 2; i <= n; i++ )
            t[i].fi = (t[i].fi - t[1].fi) / 5;
        t[1].fi = 0;
        for( i = 1; i <= k; i++ ){
            lli x = t[i].se - t[i].fi * b;
            sum += x;
            s.insert(mp(x, i));
        }
        for( i = k + 1; i <= n + 1; i++ ){
            ans = min(ans, sum + t[i - 1].fi * b * k);
            if( i == n + 1 )
                break;
            lli x = t[i].se - t[i].fi * b;
            sum += x;
            s.insert(mp(x, i));
            set < pair < lli, lli > > :: iterator it = (--s.end());
            sum -= it->fi;
            s.erase(it);
        }
    }
    pr( "%I64d\n", ans );
}