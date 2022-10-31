
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
#define N 8
char c[ N + 2 ][ N + 2 ];
int vl( char x ){
    if( x == 'Q' ) return 9;
    if( x == 'R' ) return 5;
    if( x == 'B' ) return 3;
    if( x == 'N' ) return 3;
    if( x == 'P' ) return 1;
    if( x == 'K' ) return 0;
    assert( 1 == 0 );
    return -1;
}
char chg( char ctmp ){
    if( ctmp >= 'a' ) return ctmp - 'a' + 'A';
    return ctmp;
}
void build(){

}
void init(){
    for( int i = 0 ; i < N ; i ++ )
        scanf( "%s" , c[ i ] );
}
int sw , sb;
void solve(){
    for( int i = 0 ; i < N ; i ++ )
        for( int j = 0 ; j < N ; j ++ ){
            if( c[ i ][ j ] == '.' ) continue;
            if( c[ i ][ j ] >= 'a' )
                sb += vl( chg( c[ i ][ j ] ) );
            else sw += vl( chg( c[ i ][ j ] ) );
        }
    if( sb == sw ) puts( "Draw" );
    else if( sw > sb ) puts( "White" );
    else puts( "Black" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}