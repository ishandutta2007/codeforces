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
int a[ 4 ];
void build(){

}
void init(){
    for( int i = 0 ; i < 4 ; i ++ )
        a[ i ] = getint();
}
bool tri , de;
void cal( vector<int> vtmp ){
    sort( vtmp.begin() , vtmp.end() );
    if( vtmp[ 0 ] + vtmp[ 1 ] > vtmp[ 2 ] ) tri = true;
    else if( vtmp[ 0 ] + vtmp[ 1 ] == vtmp[ 2 ] ) de = true;
}
void solve(){
    for( int i = 0 ; i < 4 ; i ++ ){
        vector<int> vtmp;
        for( int j = 0 ; j < 4 ; j ++ )
            if( i != j ) vtmp.PB( a[ j ] );
        cal( vtmp );
    }
    if( tri ) puts( "TRIANGLE" );
    else if( de ) puts( "SEGMENT" );
    else puts( "IMPOSSIBLE" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}