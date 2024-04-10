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
#define N 4010
#define K 810
int n , k , u[ N ][ N ];
int cst[ N ][ N ] , dp[ K ][ N ];
bool got[ N ][ K ];
void build(){

}
void init(){
    n = getint(); k = getint();
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= n ; j ++ )
            u[ i ][ j ] = u[ i ][ j - 1 ] + getint();
    for( int i = 1 ; i <= n ; i ++ ){
        int tcst = 0;
        for( int j = i ; j <= n ; j ++ ){
            tcst += u[ j ][ j ] - u[ j ][ i - 1 ];
            cst[ i ][ j ] = tcst;
        }
    }
}
void cal( int tk , int l , int r , int al , int ar ){
    if( l > r ) return;
    int tans = INF, pos = al;
    if( l == r ){
        for( int i = al ; i <= ar ; i ++ )
            tans = min( tans , cst[ i ][ l ] + dp[ tk - 1 ][ i - 1 ] );
        dp[ tk ][ l ] = tans;
        return;
    }
    int mid = ( l + r ) >> 1;
    for( int i = al ; i <= ar ; i ++ )
        if( cst[ i ][ mid ] + dp[ tk - 1 ][ i - 1 ] < tans )
            tans = cst[ i ][ mid ] + dp[ tk - 1 ][ i - 1 ], pos = i;
    dp[ tk ][ mid ] = tans;
    cal( tk , l , mid - 1 , al , pos );
    cal( tk , mid + 1 , r , pos , ar );
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        dp[ 1 ][ i ] = cst[ 1 ][ i ];
    for( int i = 2 ; i <= k ; i ++ )
        cal( i , 1 , n , i , n );
    printf( "%d\n" , dp[ k ][ n ] );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}