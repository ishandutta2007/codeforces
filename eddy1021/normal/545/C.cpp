// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
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
#define N 100010
int n , x[ N ] , h[ N ];
int dp[ N ][ 3 ] , rgt[ N ][ 3 ];
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        x[ i ] = getint();
        h[ i ] = getint();
    }
}
// 0 L 1 N 2 R
void solve(){
    dp[ 1 ][ 0 ] = 1; rgt[ 1 ][ 0 ] = x[ 1 ];
    dp[ 1 ][ 1 ] = 0; rgt[ 1 ][ 1 ] = x[ 1 ];
    if( n > 1 && x[ 1 ] + h[ 1 ] >= x[ 2 ] ) dp[ 1 ][ 2 ] = -1;
    else dp[ 1 ][ 2 ] = 1 , rgt[ 1 ][ 2 ] = x[ 1 ] + h[ 1 ];
    for( int i = 2 ; i <= n ; i ++ ){
        dp[ i ][ 0 ] = -1;
        for( int j = 0 ; j < 3 ; j ++ )
            if( dp[ i - 1 ][ j ] != -1 ){
                if( x[ i ] - h[ i ] > rgt[ i - 1 ][ j ] ){
                    if( dp[ i - 1 ][ j ] + 1 > dp[ i ][ 0 ] )
                        dp[ i ][ 0 ] = dp[ i - 1 ][ j ] + 1 ,
                        rgt[ i ][ 0 ] = x[ i ];
                }
            }
        dp[ i ][ 1 ] = -1;
        for( int j = 0 ; j < 3 ; j ++ )
            if( dp[ i - 1 ][ j ] != -1 ){
                if( x[ i ] > rgt[ i - 1 ][ j ] ){
                    if( dp[ i - 1 ][ j ] > dp[ i ][ 1 ] )
                        dp[ i ][ 1 ] = dp[ i - 1 ][ j ] ,
                        rgt[ i ][ 1 ] = x[ i ];
                }
            }
        dp[ i ][ 2 ] = -1;
        for( int j = 0 ; j < 3 ; j ++ )
            if( dp[ i - 1 ][ j ] != -1 ){
                if( i == n || x[ i ] + h[ i ] < x[ i + 1 ] ){
                    if( dp[ i - 1 ][ j ] + 1 > dp[ i ][ 2 ] )
                        dp[ i ][ 2 ] = dp[ i - 1 ][ j ] + 1,
                        rgt[ i ][ 2 ] = x[ i ] + h[ i ];
                }
            }
    }
    int ans = 0;
    for( int i = 0 ; i < 3 ; i ++ )
        ans = max( ans , dp[ n ][ i ] );
    printf( "%d\n" , ans );
} 
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}