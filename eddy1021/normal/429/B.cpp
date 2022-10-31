#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 1010
#define ll long long
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll max( ll x , ll y ){ return x>y?x:y; }
ll n , m , a[ N ][ N ];
ll dp[ 4 ][ N ][ N ] , ans;
void init(){
    n = getint(); m = getint();
    for( ll i = 1 ; i <= n ; i ++ )
        for( ll j = 1 ; j <= m ; j ++ )
            a[ i ][ j ] = getint();
}
void DP(){
    for( ll i = 1 ; i <= n ; i ++ )
        for( ll j = 1 ; j <= m ; j ++ )
            dp[ 0 ][ i ][ j ] = max( dp[ 0 ][ i - 1 ][ j ] , dp[ 0 ][ i ][ j - 1 ] ) +
                                    a[ i ][ j ];
    for( ll i = 1 ; i <= n ; i ++ )
        for( ll j = m ; j >= 1 ; j -- )
            dp[ 1 ][ i ][ j ] = max( dp[ 1 ][ i - 1 ][ j ] , dp[ 1 ][ i ][ j + 1 ] ) +
                                    a[ i ][ j ];
    for( ll i = n ; i >= 1 ; i -- )
        for( ll j = 1 ; j <= m ; j ++ )
            dp[ 2 ][ i ][ j ] = max( dp[ 2 ][ i + 1 ][ j ] , dp[ 2 ][ i ][ j - 1 ] ) +
                                    a[ i ][ j ];
    for( ll i = n ; i >= 1 ; i -- )
        for( ll j = m ; j >= 1 ; j -- )
            dp[ 3 ][ i ][ j ] = max( dp[ 3 ][ i + 1 ][ j ] , dp[ 3 ][ i ][ j + 1 ] ) +
                                    a[ i ][ j ];
}
void solve(){
    for( ll i = 2 ; i < n ; i ++ )
        for( ll j = 2 ; j < m ; j ++ ){
            if( dp[ 0 ][ i - 1 ][ j ] + dp[ 1 ][ i ][ j + 1 ] +
                dp[ 2 ][ i ][ j - 1 ] + dp[ 3 ][ i + 1 ][ j ] > ans )
                ans = dp[ 0 ][ i - 1 ][ j ] + dp[ 1 ][ i ][ j + 1 ] +
                dp[ 2 ][ i ][ j - 1 ] + dp[ 3 ][ i + 1 ][ j ];
            if( dp[ 0 ][ i ][ j - 1 ] + dp[ 1 ][ i - 1 ][ j ] +
                dp[ 2 ][ i + 1 ][ j ] + dp[ 3 ][ i ][ j + 1 ] > ans )
                ans = dp[ 0 ][ i ][ j - 1 ] + dp[ 1 ][ i - 1 ][ j ] +
                dp[ 2 ][ i + 1 ][ j ] + dp[ 3 ][ i ][ j + 1 ];
        }
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    DP();
    solve();
}