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
ll a , b , c , l , ans;
void build(){

}
ll C( ll xa , ll xb ){
    ll tmp = 1;
    for( ll i = 1 , j = xa ; i <= xb ; i ++ , j -- )
        tmp *= j;
    for( ll i = 1 ; i <= xb ; i ++ )
        tmp /= i;
//  printf( "%I64d %I64d %I64d\n" , xa , xb , tmp );
    return tmp;
}
void init(){
    a = getint(); b = getint(); c = getint();
    l = getint();
    ans = C( l + 3 , 3 );
}
ll cal( ll ta , ll tb , ll tc , ll tl ){
// ta max
    ll tans = 0;
    for( ll i = 0 ; i <= tl ; i ++ ){
        ll na = ta + i;
        if( na > tb && na > tc ){
            ll res = min( tl - i , na - tb - tc );
            if( res >= 0 )
                tans += C( res + 2 , 2 );
        }
    }
    return tans;
}
void solve(){
    ans -= cal( a , b , c , l );
    ans -= cal( b , a , c , l );
    ans -= cal( c , a , b , l );
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