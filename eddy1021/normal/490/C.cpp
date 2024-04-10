#include <bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
char c[ N ];
ll a , b , ra[ N ] , rb[ N ];
int len;
void init(){
    scanf( "%s" , c + 1 );
    len = strlen( c + 1 );
    scanf( "%I64d%I64d" , &a , &b );
    for( int i = 1 ; i <= len ; i ++ )
        ra[ i ] = ( ra[ i - 1 ] * 10 + c[ i ] - '0' ) % a;
    ll bs = 1;
    for( int i = len ; i >= 1 ; i -- , bs = ( bs * 10 ) % b )
        rb[ i ] = ( rb[ i + 1 ] + bs * ( c[ i ] - '0' ) ) % b;
}
void print( int bdr ){
    puts( "YES" );
    for( int i = 1 ; i <= bdr ; i ++ ) putchar( c[ i ] ); puts( "" );
    for( int i = bdr + 1 ; i <= len ; i ++ ) putchar( c[ i ] ); puts( "" );
}
void solve(){
    for( int i = 1 ; i <= len - 1 ; i ++ )
        if( ra[ i ] == 0 && rb[ i + 1 ] == 0 ){
            if( c[ i + 1 ] == '0' ) continue;
            print( i );
            return;
        }
    puts( "NO" );
}
int main(){
    init();
    solve();
}