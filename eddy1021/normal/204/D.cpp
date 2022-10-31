#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define N 1000010
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1ll;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll n , k , presb[ N ] , presw[ N ];
ll dpb[ N ] , dpw[ N ];
ll dpb2[ N ] , dpw2[ N ];
char c[ N ];
void init(){
//    n = getint(); k = getint();
    scanf( "%I64d%I64d" , &n , &k );
    scanf( "%s" , c + 1 );
    for( int i = 1 ; i <= n ; i ++ )
        presb[ i ] = presb[ i - 1 ] + ( c[ i ] == 'B' ) ,
        presw[ i ] = presw[ i - 1 ] + ( c[ i ] == 'W' );
}
void DP1(){
    ll prew = 0ll;
    ll presum = 1ll; dpw[ 0 ] = 1ll;
    for( int i = 1 ; i <= n ; i ++ )
        if( c[ i ] == 'B' ) dpw[ i ] = 0ll;
        else if( c[ i ] == 'W' ){
            while( i - prew > k ){
                presum -= dpw[ prew ] , prew ++;
                if( presum < 0 ) presum += mod7;
            }
            dpw[ i ] = presum;
            prew = i; presum = dpw[ i ];
            dpw[ i ] %= mod7;
            presum %= mod7;
        }else{
            while( i - prew > k ){
                presum -= dpw[ prew ] , prew ++;
                if( presum < 0 ) presum += mod7;
            }
            dpw[ i ] = presum;
            presum += dpw[ i ];
            dpw[ i ] %= mod7;
            presum %= mod7;
        }

    ll preb = n + 1;
    presum = 1; dpb[ n + 1 ] = 1;
    for( int i = n ; i >= 1 ; i -- )
        if( c[ i ] == 'W' ) dpb[ i ] = 0;
        else if( c[ i ] == 'B' ){
            while( preb - i > k ){
                presum -= dpb[ preb ] , preb --;
                if( presum < 0 ) presum += mod7;
            }
            dpb[ i ] = presum;
            preb = i; presum = dpb[ i ];
            dpb[ i ] %= mod7;
            presum %= mod7;
        }else{
            while( preb - i > k ){
                presum -= dpb[ preb ] , preb --;
                if( presum < 0 ) presum += mod7;
            }
            dpb[ i ] = presum;
            presum += dpb[ i ];
            dpb[ i ] %= mod7;
            presum %= mod7;
        }
}
void DP2(){
    for( int i = k ; i <= n ; i ++ )
        if( presw[ i ] - presw[ i - k ] == 0 ) dpb2[ i ] = dpw[ i - k ];
    for( int i = n - k + 1 ; i >= 1 ; i -- )
        if( presb[ i + k - 1 ] - presb[ i - 1 ] == 0 ) dpw2[ i ] = dpb[ i + k ];
}
void solve(){
    DP1();
    DP2();
    ll ans = 0ll , tmp = 0ll;
    for( int i = n ; i >= k ; i -- ){
        ans += ( dpb2[ i ] * tmp ) % mod7; ans %= mod7;
        if( c[ i ] == 'X' ) tmp = ( tmp * 2ll ) % mod7;
        tmp = ( tmp + dpw2[ i ] ) % mod7;
    }
    printf( "%I64d\n" , ans );
//    for( int i = 1 ; i <= n ; i ++ )
//        printf( "%I64d " , dpb[ i ] ); puts( "" );
//    for( int i = 1 ; i <= n ; i ++ )
//        printf( "%I64d " , dpw[ i ] ); puts( "" );
//    for( int i = 1 ; i <= n ; i ++ )
//        printf( "%I64d " , dpb2[ i ] ); puts( "" );
//    for( int i = 1 ; i <= n ; i ++ )
//        printf( "%I64d " , dpw2[ i ] ); puts( "" );
}
int main(){
    init();
    solve();
}