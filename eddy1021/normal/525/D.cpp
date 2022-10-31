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
#define N 2010
int n , m;
char c[ N ][ N ];
bool inq[ N ][ N ];
bool in( int xn , int xm ){
    return 1 <= xn && xn <= n && 1 <= xm && xm <= m;
}
void build(){

}
int dn[]={-1,-1,1,1};
int dm[]={-1,1,-1,1};
bool notokay( int xn , int xm ){
    if( !in( xn , xm ) ) return false;
    if( c[ xn ][ xm ] == '.' ) return false;
    for( int i = 0 ; i < 4 ; i ++ )
        if( in( xn + dn[ i ] , xm + dm[ i ] ) ){
            if( c[ xn + dn[ i ] ][ xm + dm[ i ] ] == '.' &&
                c[ xn + dn[ i ] ][ xm ] == '.' &&
                c[ xn ][ xm + dm[ i ] ] == '.' )
                return true;
        }
    return false;
}
queue<PII> Q;
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            if( notokay( i , j ) ){
                inq[ i ][ j ] = true;
                Q.push( MP( i , j ) );
            }
}
int dn2[]={1,1,1,0,-1,-1,-1,0};
int dm2[]={-1,0,1,1,1,0,-1,-1};
void solve(){
    while( Q.size() ){
        PII tp = Q.front(); Q.pop();
        int xn = tp.FI , xm = tp.SE;
        c[ xn ][ xm ] = '.';
        for( int i = 0 ; i < 8 ; i ++ )
            if( !inq[ xn + dn2[ i ] ][ xm + dm2[ i ] ] ){
                if( notokay( xn + dn2[ i ] , xm + dm2[ i ] ) ){
                    inq[ xn + dn2[ i ] ][ xm + dm2[ i ] ] = true;
                    Q.push( MP( xn + dn2[ i ] , xm + dm2[ i ] ) );
                }
            }
    }
    for( int i = 1 ; i <= n ; i ++ )
        printf( "%s\n" , c[ i ] + 1 );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}