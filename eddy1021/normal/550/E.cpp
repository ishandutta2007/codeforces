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
int n , a[ N ] , l[ N ] , r[ N ];
void build(){
    
}
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ )
        a[ i ] = getint();
}
void print_ans(){
    if( n == 1 ){
        puts( "YES" );
        printf( "0\n" );
        return;
    }
    if( a[ n - 2 ] != 0 ){
        puts( "YES" );
        for( int i = 0 ; i < n ; i ++ ){
            printf( "%d" , a[ i ] );
            if( i < n - 1 ) printf( "->" );
        }
        return;
    }
    int cnt = 0;
    for( int i = 0 ; i < n ; i ++ )
        if( a[ i ] == 0 ) cnt ++;
    if( cnt == 2 ){
        puts( "NO" );
        return;
    }
    puts( "YES" );
    int pre1 = -1 , pre2 = n - 2;
    for( int i = n - 3 ; i >= 0 ; i -- )
        if( a[ i ] == 0 ){
            pre1 = i;
            break;
        }
    for( int i = 0 ; i < n - 1 ; i ++ ){
        if( i == pre1 || i == pre1 + 1 ) printf( "(" );
        printf( "%d" , a[ i ] );
        if( i != pre2 ) printf( "->" );
        if( i == pre2 ) printf( "))" );
    }
    puts( "->0" );
}
void solve(){
    if( a[ n - 1 ] == 1 ) puts( "NO" );
    else print_ans();
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}