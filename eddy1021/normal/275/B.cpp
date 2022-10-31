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
#define N 52
void build(){

}
int n , m , lft[ N ][ N ] , up[ N ][ N ];
char c[ N ][ N ];
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            lft[ i ][ j ] = lft[ i ][ j - 1 ] + ( c[ i ][ j ] == 'B' ),
            up[ i ][ j ] = up[ i - 1 ][ j ] + ( c[ i ][ j ] == 'B' );
}
vector<PII> v;
bool okay( PII p1 , PII p2 ){
    if( p1.FI > p2.FI ) swap( p1 , p2 );
    if( p1.SE > p2.SE ){
        return ( ( lft[ p1.FI ][ p1.SE ] - lft[ p1.FI ][ p2.SE - 1 ] == ( p1.SE - p2.SE + 1 ) ) &&
                ( up[ p2.FI ][ p2.SE ] - up[ p1.FI - 1 ][ p2.SE ] == ( p2.FI - p1.FI + 1 ) ) ) ||
                ( ( lft[ p2.FI ][ p1.SE ] - lft[ p2.FI ][ p2.SE - 1 ] == ( p1.SE - p2.SE + 1 ) ) &&
                ( up[ p2.FI ][ p1.SE ] - up[ p1.FI - 1 ][ p1.SE ] == ( p2.FI - p1.FI + 1 ) ) );
    }else{
        return ( ( lft[ p1.FI ][ p2.SE ] - lft[ p1.FI ][ p1.SE - 1 ] == ( p2.SE - p1.SE + 1 ) ) &&
                ( up[ p2.FI ][ p2.SE ] - up[ p1.FI - 1 ][ p2.SE ] == ( p2.FI - p1.FI + 1 ) ) ) ||
                ( ( lft[ p2.FI ][ p2.SE ] - lft[ p2.FI ][ p1.SE - 1 ] == ( p2.SE - p1.SE + 1 ) ) &&
                ( up[ p2.FI ][ p1.SE ] - up[ p1.FI - 1 ][ p1.SE ] == ( p2.FI - p1.FI + 1 ) ) );
    }
}
bool good(){
    for( int i = 0 ; i < (int)v.size() ; i ++ )
        for( int j = i + 1 ; j < (int)v.size() ; j ++ )
            if( !okay( v[ i ] , v[ j ] ) )
                return false;
    return true;
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            if( c[ i ][ j ] == 'B' )
                v.PB( MP( i , j ) );
    puts( good() ? "YES" : "NO" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}