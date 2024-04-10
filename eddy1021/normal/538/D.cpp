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
void build(){}
#define N 1010
int n;
char c[ N ][ N ];
int ans[ N ][ N ];
bool tag[ N ][ N ];
vector<PII> o;
bool in( int x , int y ){
    return x >= 1 && y >= 1 && x <= n && y <= n;
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= n ; j ++ )
            if( c[ i ][ j ] == 'o' )
                o.PB( MP( i , j ) );
}
void ccheck( int ti , int tj ){
    int oi = o[ 0 ].FI , oj = o[ 0 ].SE;
    int di = ti - oi , dj = tj - oj;
    bool flag = true;
    for( int i = 1 ; i < (int)o.size() ; i ++ )
        if( in( o[ i ].FI + di , o[ i ].SE + dj ) &&
            c[ o[ i ].FI + di ][ o[ i ].SE + dj ] == '.' ){
            flag = false;
            break;
        }
    if( flag ){
        ans[ n + di ][ n + dj ] = true;
        for( int i = 0 ; i < (int)o.size() ; i ++ )
            if( in( o[ i ].FI + di , o[ i ].SE + dj ) )
                tag[ o[ i ].FI + di ][ o[ i ].SE + dj ] = true;
    }
}
void check( int ti , int tj ){
    for( int i = -n + 1 ; i <= n - 1 ; i ++ )
        for( int j = -n + 1 ; j <= n - 1 ; j ++ )
            if( in( ti + i , tj + j ) ){
                if( c[ ti + i ][ tj + j ] != '.' )
                    ans[ i + n ][ j + n ] ++;
            }else ans[ i + n ][ j + n ] ++;
}
void check2( int ti , int tj ){
    for( int i = -n + 1 ; i <= n - 1 ; i ++ )
        for( int j = -n + 1 ; j <= n - 1 ; j ++ )
            if( in( ti + i , tj + j ) && ans[ i + n ][ j + n ] == (int)o.size() )
                tag[ ti + i ][ tj + j ] = true;
}
void solve(){
    for( int i = 0 ; i < (int)o.size() ; i ++ )
        check( o[ i ].FI , o[ i ].SE );
    for( int i = 0 ; i < (int)o.size() ; i ++ )
        check2( o[ i ].FI , o[ i ].SE );
    /*
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= n ; j ++ )
            if( c[ i ][ j ] == 'x' )
                check( i , j );*/
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= n ; j ++ )
            if( c[ i ][ j ] == 'x' && !tag[ i ][ j ] ){
                puts( "NO" );
                return;
            }
    puts( "YES" );
    for( int i = 1 ; i <= 2 * n - 1 ; i ++ , puts( "" ) )
        for( int j = 1 ; j <= 2 * n - 1 ; j ++ )
            if( i == n && j == n ) putchar( 'o' );
            else if( ans[ i ][ j ] == (int)o.size() ) putchar( 'x' );
            else putchar( '.' );
}
int main(){
    build();  
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}