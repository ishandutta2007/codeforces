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
#define N 200010
int n , w[ N ] , h[ N ];
int sumw , lh[ N ] , rh[ N ];
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        w[ i ] = getint();
        h[ i ] = getint();
        sumw += w[ i ];
        lh[ i ] = max( lh[ i - 1 ] , h[ i ] );
    }
    for( int i = n ; i >= 1 ; i -- )
        rh[ i ] = max( rh[ i + 1 ] , h[ i ] );
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        printf( "%d " , ( sumw - w[ i ] ) * max( lh[ i - 1 ] , rh[ i + 1 ] ) );
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