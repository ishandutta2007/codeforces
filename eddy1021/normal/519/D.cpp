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
#define Z 27
#define N 100010
int v[ Z ] , len;
char c[ N ];
map<ll,int> M[ Z ];
int vl( char ctmp ){
    return v[ ctmp - 'a' ];
}
void build(){

}
ll ans;
void init(){
    for( int i = 0 ; i < Z - 1 ; i ++ )
        v[ i ] = getint();
    scanf( "%s" , c + 1 );
    len = strlen( c + 1 );
}
void solve(){
    ll psum = 0;
    for( int i = 1 ; i <= len ; i ++ ){
        if( M[ c[ i ] - 'a' ].count( psum ) )
            ans += (ll)M[ c[ i ] - 'a' ][ psum ];
        psum += vl( c[ i ] );
        M[ c[ i ] -'a' ][ psum ] ++;
    }
    printf( "%I64d\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}