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
#define L 200010
#define N 60
char c1[ L ] , c2[ L ];
int cnt1[ N ] , cnt2[ N ];
void build(){

}
int chg( char ctmp ){
    if( ctmp >= 'a' ) return ctmp - 'a';
    return ctmp - 'A' + 26;
}
void init(){
    scanf( "%s%s" , c1 , c2 );
}
void solve(){
    int len = strlen( c1 );
    for( int i = 0 ; c1[ i ] ; i ++ )
        cnt1[ chg( c1[ i ] ) ] ++;
    for( int i = 0 ; c2[ i ] ; i ++ )
        cnt2[ chg( c2[ i ] ) ] ++;
    int got = 0 , got2 = 0;
    for( int i = 0 ; i < 52 ; i ++ ){
        int tmp = min( cnt1[ i ] , cnt2[ i ] );
        got += tmp;
        cnt1[ i ] -= tmp;
        cnt2[ i ] -= tmp;
    }
    for( int i = 0 ; i < 26 ; i ++ ){
        got2 += min( cnt1[ i ] , cnt2[ i + 26 ] );
        got2 += min( cnt2[ i ] , cnt1[ i + 26 ] );
    }
    printf( "%d %d\n" , got , got2 );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}