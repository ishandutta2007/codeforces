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

lli n, s[100001], mx;
pair < lli, lli > a[100001];

int main()
{
    sc( "%I64d", &n );
    for( int i = 1; i <= n; i++ )
        sc( "%I64d%I64d", &a[i].fi, &a[i].se );
    sort( a + 1, a + n + 1 );
    for( int i = 1; i <= n; i++ ){
        do{
            a[i].fi = a[i].fi + 1;
            a[i].se = (a[i].se - 1) / 4 + 1;
        }while( a[i].se > 1 );
        mx = max(mx, a[i].fi);
    }
    pr( "%I64d", mx );
}