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
#define eps 1e-18
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
ll n , m , a[ N ] , sa[ N ] , total , lst;
void build(){

}
void init(){
    lst = n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        sa[ i ] = getint();
        total += sa[ i ];
    }
}
bool can( ll tmp ){
    for( int i = 1 ; i <= n ; i ++ ) a[ i ] = sa[ i ];
    lst = n;
    for( ll i = 1 ; i <= m ; i ++ ){
        while( a[ lst ] == 0 ){
            lst --;
            if( lst < 1 ) return true;
        }
        ll tk = tmp - lst;
        if( tk <= 0 ) return false;
        while( tk ){
            if( a[ lst ] > tk ){
                a[ lst ] -= tk;
                tk = 0;
            }else{
                tk -= a[ lst ];
                a[ lst ] = 0;
                lst --;
                if( lst < 1 ) return true;
            }
        }
    }
    while( a[ lst ] == 0 ){
        lst --;
        if( lst < 1 ) return true;
    }
    return false;
}
void solve(){
    while( sa[ lst ] == 0 ) lst --;
    if( m >= total ){
        cout << lst + 1 << endl;
        return;
    }
    ll tl = 1 , tr = 10000000000000000ll , tmid , tans = 0;
    while( tl <= tr ){
        tmid = ( tl + tr ) >> 1;
        if( can( tmid ) ){
            tans = tmid , tr = tmid - 1;
        }else tl = tmid + 1;
    }
    cout << tans << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}