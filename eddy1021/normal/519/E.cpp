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
#define K 20
#define N 100010
vector<int> vv[ N ];
int n;
int dt[ N ] , sz[ N ] , p[ K ][ N ];
void build(){

}
int DP( int now = 1 , int tp = 0 , int dpt = 0 ){
    dt[ now ] = dpt;
    sz[ now ] = 1;
    p[ 0 ][ now ] = tp;
    for( int i = 0 ; i < (int)vv[ now ].size() ; i ++ )
        if( vv[ now ][ i ] != tp )
            sz[ now ] += DP( vv[ now ][ i ] , now , dpt + 1 );
    return sz[ now ];
}
void init(){
    n = getint();
    for( int i = 1 ; i < n ; i ++ ){
        int tu , tv;
        tu = getint();
        tv = getint();
        vv[ tu ].PB( tv );
        vv[ tv ].PB( tu );
    }
    DP();
    for( int i = 1 ; i < K ; i ++ )
        for( int j = 1 ; j <= n ; j ++ )
            p[ i ][ j ] = p[ i - 1 ][ p[ i - 1 ][ j ] ];
}
int up( int u , int x ){
    for( int i = 0 ; i < K && x ; i ++ )
        if( x & ( 1 << i ) ){
            u = p[ i ][ u ];
            x ^= ( 1 << i );
        }
    return u;
}
int lca( int u , int v ){
    if( dt[ u ] > dt[ v ] ) u = up( u , dt[ u ] - dt[ v ] );
    if( dt[ v ] > dt[ u ] ) v = up( v , dt[ v ] - dt[ u ] );
    int l = 0 , r = dt[ u ] , mid , ta = u;
    while( l <= r ){
        mid = ( l + r ) >> 1;
        int tp1 = up( u , mid );
        int tp2 = up( v , mid );
        if( tp1 == tp2 ) ta = tp1 , r = mid - 1;
        else l = mid + 1;
    }
    return ta;
}
int dist( int u , int v ){
    return dt[ u ] + dt[ v ] - 2 * dt[ lca( u , v ) ];
}
void solve(){
    int q = getint(); while( q -- ){
        int qa , qb;
        qa = getint();
        qb = getint();
        if( qa == qb ) printf( "%d\n" , n );
        else if( dist( qa , qb ) % 2 ) puts( "0" );
        else if( dt[ qa ] == dt[ qb ] ){
            int tlca = lca( qa , qb );
            int dlt = dt[ qa ] - dt[ tlca ] - 1;
            qa = up( qa , dlt );
            qb = up( qb , dlt );
            printf( "%d\n" , n - sz[ qa ] - sz[ qb ] );
        }else{
            int tdist = dist( qa , qb ) / 2;
            if( dt[ qa ] < dt[ qb ] )
                swap( qa , qb );
            int tp1 = up( qa , tdist );
            int tp2 = up( qa , tdist - 1 );
            printf( "%d\n" , sz[ tp1 ] - sz[ tp2 ] );
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