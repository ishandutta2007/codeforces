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

int n, k, i, j, h, a[300003], x = 0, y = 1;

int main()
{
    sc( "%d%d", &n, &k );
    for( i = 1; i <= n; i++ )
        sc( "%d", &a[i] );
    for( i = j = 1; i <= n; i++ ){
        if( !a[i] )
            k--;
        while( k < 0 ){
            if( !a[j] )
                k++;
            j++;
        }
        if( i - j + 1 >= x - y + 1 ){
            x = i;
            y = j;
        }
    }
    pr( "%d\n", x - y + 1 );
    for( i = 1; i < y; i++ )
        pr( "%d ", a[i] );
    for( i = y; i <= x; i++ )
        pr( "1 " );
    for( i = x + 1; i <= n; i++ )
        pr( "%d ", a[i] );
}