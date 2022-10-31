// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000000007ll 
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
#define N 210
int n , m , p[ N ];
bool happy[ N ];
int find_p( int x ){
    return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
    x = find_p( x );
    y = find_p( y );
    p[ x ] = y;
}
void build(){

}
// 0 .. n - 1
// n ... n + m - 1;
void init(){
    n = getint(); m = getint();
    for( int i = 0 ; i < n + m ; i ++ )
        p[ i ] = i;
    for( int i = 0 ; i < n * m ; i ++ )
        Union( i % n , i % m + n );
    int x = getint();
    while( x -- ) happy[ find_p( getint() ) ] = true;
    x = getint();
    while( x -- ) happy[ find_p( n + getint() ) ] = true;
}
void solve(){
    for( int i = 0 ; i < n + m ; i ++ )
        if( i == find_p( i ) && !happy[ i ] ){
            puts( "No" );
            return;
        }
    puts( "Yes" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}