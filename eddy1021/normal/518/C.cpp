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
#define N 100010
int n , m , k , a[ N ] , pos[ N ] , v[ N ];
ll ans;
void build(){

}
void init(){
    n = getint(); m = getint(); k = getint();
    for( int i = 0 ; i < n ; i ++ ){
        a[ i ] = getint();
        v[ a[ i ] ] = i / k + 1;
        pos[ a[ i ] ] = i;
    }
}
void chg( int tmp ){
    if( pos[ tmp ] == 0 ) return;
    int pre = a[ pos[ tmp ] - 1 ];
    swap( a[ pos[ tmp ] ] , a[ pos[ pre ] ] );
    swap( pos[ tmp ] , pos[ pre ] );
    v[ a[ pos[ tmp ] ] ] = pos[ tmp ] / k + 1;
    v[ a[ pos[ pre ] ] ] = pos[ pre ] / k + 1;
}
void solve(){
    while( m -- ){
        int tmp = getint();
        ans += (ll)v[ tmp ];
        chg( tmp );
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