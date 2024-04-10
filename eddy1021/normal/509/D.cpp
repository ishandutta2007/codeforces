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
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 110
ll n , m , mx , tg;
ll w[ N ][ N ] , a[ N ] , b[ N ];
void build(){
    
}
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ ){
            w[ i ][ j ] = getint();
            mx = max( mx , w[ i ][ j ] );
        }
    for( int i = 1 ; i <= m ; i ++ )
        b[ i ] = w[ 1 ][ i ];
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = w[ i ][ 1 ] - b[ 1 ];
}
ll amod;
void output(){
    puts( "YES" );
    printf( "%I64d\n" , amod );
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] %= amod;
        a[ i ] = ( a[ i ] + amod ) % amod;
        printf( "%I64d " , a[ i ] );
    }
    puts( "" );
    for( int i = 1 ; i <= m ; i ++ )
        printf( "%I64d " , b[ i ] );
    puts( "" );
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            tg = __gcd( tg , abs( w[ i ][ j ] - a[ i ] - b[ j ] ) );
    if( tg == 0 || tg > mx ){
        if( tg == 0 ) amod = mx + 1;
        else amod = tg;
        output();
    }else puts( "NO" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}