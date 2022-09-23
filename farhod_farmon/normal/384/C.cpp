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

lli n, i, a[200002], s1, s2, l[200002], r[200002];

int main()
{
    sc( "%I64d", &n );
    for( i = 1; i <= n; i++ ){
        sc( "%I64d", &a[i] );
        l[i] = l[i - 1] + a[i];
    }
    for( i = n; i >= 1; i-- )
        r[i] = r[i + 1] + 1 - a[i];
    for( i = 1; i <= n; i++ ){
        if( a[i] )
            s1 += r[i + 1];
        else
            s2 += l[i - 1];
    }
    pr( "%I64d", min(s1, s2) );
}