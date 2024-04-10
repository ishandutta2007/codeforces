// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x , D _y ){
    return _x > _y - eps && _x < _y + eps;
}
D mypow( D _x , ll _a ){
    if( _a == 0 ) return 1.0;
    D _tmp = mypow( _x , _a / 2 );
    _tmp *= _tmp;
    if( _a & 1ll ) _tmp *= _x;
    return _tmp;
}
ll mypow( ll _x , ll _a , ll _mod ){
    if( _a == 0 ) return 1ll;
    ll _tmp = mypow( _x , _a / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _a & 1ll ) _tmp = ( _tmp * _x ) % _mod;
    return _tmp;
}
int __ = 1 , cs;
/***   default ***/
#define N 2010
int n , t;
D p;
D dp[ N ][ N ];
void build(){

}
void init(){
    n = getint();
    scanf( "%lf" , &p );
    t = getint();
}
void DP(){
    dp[ 0 ][ 0 ] = 1;
    for( int i = 1 ; i <= t ; i ++ )
        for( int j = 0 ; j <= n ; j ++ ){
            if( j ) dp[ i ][ j ] += dp[ i - 1 ][ j - 1 ] * p;
            if( j < n ) dp[ i ][ j ] += dp[ i - 1 ][ j ] * ( 1.0 - p );
            else dp[ i ][ j ] += dp[ i - 1 ][ j ];
        }
//    for( int i = 1 ; i <= t ; i ++ )
//        for( int j = 0 ; j <= n ; j ++ )
//            printf( "%d %d %.5f\n" , i , j , dp[ i ][ j ] );
}
void solve(){
    D ans = 0.0;
    DP();
    for( int i = 1 ; i <= n ; i ++ )
        ans += (D)i * dp[ t ][ i ];
    printf( "%.15f\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}