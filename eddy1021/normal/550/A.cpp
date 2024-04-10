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
#define N 100010
char c[ N ];
int n;
void build(){

}
void init(){
    scanf( "%s" , c + 1 );
    n = strlen( c + 1 );
}
bool got(){
    bool gotab = false;
    bool gotba = false;
    for( int i = 2 ; i <= n ; i ++ )
        if( !gotab && c[ i ] == 'B' && c[ i - 1 ] == 'A' ){
            gotab = true;
            i ++;
        }else if( gotab && c[ i ] == 'A' && c[ i - 1 ] == 'B' )
            gotba = true;
    if( gotab && gotba ) return true;
    gotab = false; gotba = false;
    for( int i = 2 ; i <= n ; i ++ )
        if( !gotab && c[ i ] == 'A' && c[ i - 1 ] == 'B' ){
            gotab = true;
            i ++;
        }else if( gotab && c[ i ] == 'B' && c[ i - 1 ] == 'A' )
            gotba = true;
    return gotab && gotba;
}
void solve(){
    if( got() ) puts( "YES" );
    else puts( "NO" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}