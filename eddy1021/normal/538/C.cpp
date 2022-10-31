// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009
#define mod7 1000000007 
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-10
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
/*********default*********/
#define N 100010
ll n , m , d[ N ] , h[ N ] , ans;
void init(){
    n = getint(); m = getint();
    for( int i = 0 ; i < m ; i ++ ){
        d[ i ] = getint();
        h[ i ] = getint();
        ans = max( ans , h[ i ] );
    }
}
void solve(){
    if( d[ 0 ] != 1 ) ans = max( ans , h[ 0 ] + ( d[ 0 ] - 1 ) );
    if( d[ m - 1 ] != n ) ans = max( ans , h[ m - 1 ] + ( n - d[ m - 1 ] ) );
    for( int i = 0 ; i < m - 1 ; i ++ ){
        ll dd = d[ i + 1 ] - d[ i ];
        ll dlt = h[ i + 1 ] - h[ i ];
        if( dlt < 0 ) dlt *= -1;
        if( dlt > dd ){
            puts( "IMPOSSIBLE" );
            return;
        }
        dd -= dlt;
        dd /= 2;
        ans = max( ans , max( h[ i ] , h[ i + 1 ] ) + dd );
    }
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}