// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009int
#define mod7 1000000007int 
#define INF 1023456789int
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
    if( _x == 0 ) return 1;
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
void build(){

}
int n , ans;
char c[ 10001 ] , c2[ 10001 ];
void init(){
    n = getint();
    scanf( "%s" , c );
    scanf( "%s" , c2 );
}
void solve(){
    for( int i = 0 ; i < n ; i ++ ){
        int dlt = abs( ( c[ i ] - '0' ) - ( c2[ i ] - '0' ) );
        ans += min( dlt , 10 - dlt );
    }
    printf( "%d\n" , ans );
}
int main(){
    build();  
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}