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
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
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
#define N 510
ll n , m , dp[ 2 ][ N ][ N ] , psum[ 2 ][ N ][ N ] , b , mod , a[ N ];
void build(){

}
void init(){
    n = getint(); m = getint(); b = getint(); mod = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
}
void solve(){
    dp[ 0 ][ 0 ][ 0 ] = 1;
    psum[ 0 ][ 0 ][ 0 ] = 1;
    for( int i = 1 ; i <= m ; i ++ )
        for( int j = a[ 1 ] ; j <= b ; j ++ )
            psum[ 0 ][ i ][ j ] = psum[ 0 ][ i - 1 ][ j - a[ 1 ] ];
    for( int i = 1 ; i <= n ; i ++ ){
        int now = i & 1 , pre = 1 - now;
        dp[ now ][ 0 ][ 0 ] = 1;
        for( int j = 1 ; j <= m ; j ++ )
            for( int k = 0 ; k <= b ; k ++ )
                dp[ now ][ j ][ k ] = psum[ pre ][ j ][ k ];
        if( i <= n ){
            for( int j = 0 ; j <= m ; j ++ )
                for( int k = 0 ; k <= b ; k ++ )
                    psum[ now ][ j ][ k ] = 0;
            int nxt = a[ i + 1 ];
            psum[ now ][ 0 ][ 0 ] = 1;
            for( int j = 1 ; j <= m ; j ++ )
                for( int k = 0 ; k <= b ; k ++ ){
                    psum[ now ][ j ][ k ] = dp[ now ][ j ][ k ];
                    if( k >= nxt )
                        psum[ now ][ j ][ k ] = ( psum[ now ][ j - 1 ][ k - nxt ] + psum[ now ][ j ][ k ] ) % mod;
                }
        }
    }
    ll ans = 0;
    for( int i = 0 ; i <= b ; i ++ ){
        ans += dp[ n & 1 ][ m ][ i ];
        ans %= mod;
    }
    cout << ans << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}