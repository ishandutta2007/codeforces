#include <bits/stdc++.h>
using namespace std;
#define N 510
typedef long long ll;
int n , m , tmp[ N ] , cnt[ 3 ];
char c[ N ];
ll dp[ 2 ][ N ][ N ] , mod;
void init(){
    scanf( "%d%d%I64d" , &n , &m , &mod );
    for( int i = 1 ; i <= n ; i ++ ) tmp[ i ] = 2;
    for( int i = 0 ; i < m ; i ++ ){
        scanf( "%s" , c + 1 );
        for( int j = 1 ; j <= n ; j ++ )
            if( c[ j ] == '1' )
                tmp[ j ] --;
    }
    for( int i = 1 ; i <= n ; i ++ )
        cnt[ tmp[ i ] ] ++;
}
void solve(){
    dp[ 0 ][ cnt[ 2 ] ][ cnt[ 1 ] ] = 1ll;
    for( int i = 0 , idx = 0 ; i < n - m ; i ++ , idx = 1 - idx ){
        memset( dp[ idx ^ 1 ] , 0 , sizeof( dp[ idx ^ 1 ] ) );
        for( ll j = 0 ; j <= n ; j ++ )
            for( ll k = 0 ; k <= n - j ; k ++ ){
                ll tdp = dp[ idx ][ j ][ k ] % mod;
                if( tdp % mod == 0ll ) continue;
                if( j > 1 ){
                    dp[ idx ^ 1 ][ j - 2 ][ k + 2 ] += ( ( ( ( j * ( j - 1ll ) ) / 2ll ) % mod ) * tdp ) % mod;
                    dp[ idx ^ 1 ][ j - 2 ][ k + 2 ] %= mod;
                }
                if( k > 1 ){
                    dp[ idx ^ 1 ][ j ][ k - 2 ] += ( ( ( ( k * ( k - 1ll ) ) / 2ll ) % mod ) * tdp ) % mod;
                    dp[ idx ^ 1 ][ j ][ k - 2 ] %= mod;
                }
                if( j >= 1 && k >= 1 ){
                    dp[ idx ^ 1 ][ j - 1 ][ k ] += ( ( ( j * k ) % mod ) * tdp ) % mod;
                    dp[ idx ^ 1 ][ j - 1 ][ k ] %= mod;
                }
            }
    }
    printf( "%I64d\n" , dp[ ( n - m ) % 2 ][ 0 ][ 0 ] );
}
int main(){
    init();
    solve();
}