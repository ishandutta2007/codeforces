// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000000007ll 
#define INF 1023456789ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1ll;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 1000010
#define BS 13131ll
#define mod 1000000007ll
int n , k;
char c[ N ];
ll hs[ N ] , p[ N ];
void Hash(){
    for( int i = 1 ; i <= n ; i ++ ){
        hs[ i ] = ( hs[ i - 1 ] * BS ) % mod;
        hs[ i ] = ( hs[ i ] + c[ i ] ) % mod;
    }
    p[ 0 ] = 1;
    for( int i = 1 ; i <= n ; i ++ )
        p[ i ] = ( p[ i - 1 ] * BS ) % mod;
}
ll hsvl( ll l , ll r ){
    ll vl1 = hs[ r ];
    ll vl2 = ( hs[ l - 1 ] * p[ r - l + 1 ] ) % mod;
//    cout << l <<  " " << r << " " <<  ( vl1 - vl2 + mod ) % mod << endl;
    return ( vl1 - vl2 + mod ) % mod;
}
void build(){

}
void init(){
    n = getint(); k = getint();
    scanf( "%s" , c + 1 );
    Hash();
}
bool can[ N ];
int flg[ N ];
bool check( int tn ){
//    printf( "%d\n" , tn );
    int len = tn / k;
    for( int i = 1 ; i < k ; i ++ ){
        if( hsvl( 1 , len ) != hsvl( i * len + 1 , ( i + 1 ) * len ) )
            return false;
    }
    int lst = k * len , l = 1 , r = len , mid , a = 0;
    while( l <= r ){
        mid = ( l + r ) >> 1;
        if( lst + mid > n ){
            r = mid - 1;
            continue;
        }
        if( hsvl( 1 , mid ) == hsvl( lst + 1 , lst + mid ) )
            a = mid , l = mid + 1;
        else r = mid - 1;
    }
    flg[ tn ] = lst + a;
    return true;
}
void solve(){
    for( int i = k ; i <= n ; i += k )
        if( check( i ) )
            can[ i ] = true;
    int ff = 0;
    for( int i = 1 ; i <= n ; i ++ ){
        if( can[ i ] || i <= ff ) putchar( '1' );
        else putchar( '0' );
        ff = max( ff , flg[ i ] );
    }
    puts( "" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}