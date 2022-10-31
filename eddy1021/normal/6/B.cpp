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
#define N 110
int n , m;
char c[ 3 ];
char mz[ N ][ N ];
#define Z 26
bool is[ Z ];
void build(){

}
void init(){
    n = getint(); m = getint();
    scanf( "%s" , c );
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , mz[ i ] + 1 );
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool in( int ti , int tj ){
    return 1 <= ti && ti <= n && 1 <= tj && tj <= m;
}
bool good( int ti , int tj ){
    for( int i = 0 ; i < 4 ; i ++ )
        if( in( ti + dx[ i ] , tj + dy[ i ] ) && 
            mz[ ti + dx[ i ] ][ tj + dy[ i ] ] == c[ 0 ] )
                return true;
    return false;
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            if( mz[ i ][ j ] != c[ 0 ] && 
                mz[ i ][ j ] >= 'A' &&
                mz[ i ][ j ] <= 'Z' && good( i , j ) )
                is[ mz[ i ][ j ] - 'A' ] = true;
    int ans = 0;
    for( int i = 0 ; i < Z ; i ++ )
        if( is[ i ] ) ans ++;
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