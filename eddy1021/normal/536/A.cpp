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
ll a , b , n;
ll l , t , m;
void build(){

}
ll A( ll idx ){
    return a + b * ( idx - 1 );
}
ll SUM( ll idx ){
    return ( 2ll * a + ( idx - 1 ) * b ) * idx / 2ll;
}
ll SUM( ll idx1 , ll idx2 ){
    return SUM( idx2 ) - SUM( idx1 - 1 );
}
void init(){
    a = getint(); b = getint(); n = getint();
}
ll BS(){
    ll tl = l , tr = t , tmid , ta = -1;
    while( tl <= tr ){
        tmid = ( tl + tr ) >> 1;
        if( A( tmid ) > t ){
            tr = tmid - 1;
            continue;
        }
        if( SUM( l , tmid ) <= t * m ) ta = tmid , tl = tmid + 1;
        else tr = tmid - 1;
    }
    return ta;
}
void solve(){
    while( n -- ){
        l = getint(); t = getint(); m = getint();
        if( A( l ) > t ) puts( "-1" );
        else printf( "%I64d\n" , BS() );
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