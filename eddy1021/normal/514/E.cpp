// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
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
#define D 101
int n , x , cnt[ D ];
ll dp[ D ];
class mat{
    public:
        ll a[ D + 2 ][ D + 2 ];
        mat(){}
        mat operator*( const mat & m ) const{
            mat tmp;
            for( int i = 1 ; i < D + 1 ; i ++ )
                for( int j = 1 ; j < D + 1 ; j ++ ){
                    tmp.a[ i ][ j ] = 0;
                    for( int k = 1 ; k < D + 1 ; k ++ ){
                        ll dlt = ( a[ i ][ k ] * m.a[ k ][ j ] ) % mod7;
                        tmp.a[ i ][ j ] = ( tmp.a[ i ][ j ] + dlt ) % mod7;
                    }
                }
            return tmp;
        }
};
void build(){

}
void init(){
    n = getint(); x = getint();
    while( n -- ) cnt[ getint() ] ++;
    dp[ 0 ] = 1;
    for( int i = 1 ; i < D ; i ++ ){
        dp[ i ] = 1;
        for( int j = 1 ; j < D && i - j >= 0 ; j ++ ){
            ll dlt = ( cnt[ j ] * dp[ i - j ] ) % mod7;
            dp[ i ] = ( dp[ i ] + dlt ) % mod7;
        }
    }
}
void solve(){
    if( x < D ) printf( "%lld\n" , dp[ x ] );
    else{
        x -= 100;
        mat I , M;
        M.a[ 1 ][ 1 ] = 1;
        for( int j = 2 ; j <= D ; j ++ )
            M.a[ 1 ][ j ] = 0;
        for( int i = 2 ; i < D ; i ++ )
            for( int j = 1 ; j <= D ; j ++ )
                if( j == i + 1 ) M.a[ i ][ j ] = 1;
                else M.a[ i ][ j ] = 0;
        M.a[ D ][ 1 ] = 1;
        for( int j = 2 ; j <= D ; j ++ )
            M.a[ D ][ j ] = cnt[ D - j + 1 ];
        for( int i = 1 ; i <= D ; i ++ )
            for( int j = 1 ; j <= D ; j ++ )
                if( i == j ) I.a[ i ][ j ] = 1;
                else I.a[ i ][ j ] = 0;
//        int o = 1;
        while( x ){
            if( x & 1 ) I = I * M;
            M = M * M;
            x >>= 1;
        }
        ll ans = I.a[ D ][ 1 ];
        for( int j = 2 ; j <= D ; j ++ ){
            ll dlt = ( dp[ j - 1 ] * I.a[ D ][ j ] ) % mod7;
            ans = ( ans + dlt ) % mod7;
        }
        printf( "%lld\n" , ans );
    }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}