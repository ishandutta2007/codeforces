// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
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
#define N 2000010
ll n , lvl[ N ] , inv[ N ];
void build(){
    lvl[ 0 ] = 1; inv[ 0 ] = 1;
    for( int i = 1 ; i < N ; i ++ ){
        lvl[ i ] = ( lvl[ i - 1 ] * (ll)i ) % mod7;
        if( i < 1000010 )
            inv[ i ] = mypow( lvl[ i ] , mod7 - 2 , mod7 );
    }
}
ll C( ll a , ll b ){
    return ( ( ( lvl[ a ] * inv[ b ] ) % mod7 ) * inv[ a - b ] ) % mod7;
}
void init(){
    n = getint();
}
void solve(){
    ll ans = 0;
    for( ll i = 0 ; i <= n ; i ++ ){
        ll tans = ( 2ll * C( 2 * i + 1 , i + 1 ) ) % mod7;
        tans = ( tans - C( 2 * i , i ) + mod7 ) % mod7;
        ans = ( ans + tans ) % mod7;
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