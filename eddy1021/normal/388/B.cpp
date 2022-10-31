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
#define N 1010
int k , n;
bool con[ N ][ N ];
void add_edge( int a , int b ){
    con[ a ][ b ] = true;
    con[ b ][ a ] = true;
}
int x[ N ];
void fulf( int tx , int stp , int vv ){
    while( stp < 58 ){
        add_edge( tx , ++ n );
        tx = n;
        stp ++;
    }
    x[ vv ] = tx;
}
void build(){
    add_edge( 1 , 3 );
    add_edge( 1 , 4 );
    add_edge( 3 , 5 );
    add_edge( 4 , 5 );
    n = 5;
    fulf( 3 , 1 , 0 );
    fulf( 5 , 2 , 1 );
    int pre = 5 , tstp  = 2;
    for( int i = 2 ; i < 30 ; i ++ ){
        add_edge( pre , n + 1 );
        add_edge( pre , n + 2 );
        add_edge( n + 1 , n + 3 );
        add_edge( n + 2 , n + 3 );
        pre = n + 3;
        n = n + 3;
        tstp += 2;
        fulf( pre , tstp , i );
    }
}
void init(){
    k = getint();
}
void solve(){
    for( int i = 0 ; i < 30 ; i ++ )
        if( k & ( 1 << i ) )
            add_edge( 2 , x[ i ] );
    printf( "%d\n" , n );
    for( int i = 1 ; i <= n ; i ++ , puts( "" ) )
        for( int j = 1 ; j <= n ; j ++ )
            putchar( con[ i ][ j ] ? 'Y' : 'N' );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}