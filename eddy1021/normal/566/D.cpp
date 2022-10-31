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
#define N 200010
int n , q , p[ N ];
set<int> S;
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
void init(){
    n = getint(); q = getint();
    for( int i = 1 ; i <= n ; i ++ ) p[ i ] = i;
    for( int i = 1 ; i < n ; i ++ ) S.insert( i );
    S.insert( 2 * n );
}
void solve(){
    while( q -- ){
        int tp , x , y;
        tp = getint(); x = getint(); y = getint();
        if( tp == 1 ) Union( x , y );
        else if( tp == 3 ) puts( find_p( x ) == find_p( y ) ? "YES" : "NO" );
        else{
            while( true ){
                int tmp = *S.lower_bound( x );
                if( tmp >= y ) break;
                Union( tmp , tmp + 1 );
                S.erase( S.find( tmp ) );
            }
        }
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