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
#define N 100010
int n , k;
#define X 2147483647
vector<int> v[ N ];
void build(){

}
int trans(){
    char ctmp[ 20 ]; int tmp;
    scanf( "%s" , ctmp );
    if( sscanf( ctmp , "%d" , &tmp ) == 1 )
        return tmp;
    return X;
}
void init(){
    n = getint(); k = getint();
    for( int i = 0 ; i < n ; i ++ )
        v[ i % k ].PB( trans() );
}
void cal( int idx ){
    int sz = (int)v[ idx ].size() , tl = -1 , tr;
    for( int i = 0 ; i < sz ; i ++ ){
        if( v[ idx ][ i ] == X ){
            if( tl == -1 ) tl = i;
            tr = i;
            if( i == sz - 1 || v[ idx ][ i + 1 ] != X ){
                int len = tr - tl + 1;
                if( tl == 0 && tr == sz - 1 ){
                    int st = len / -2;
                    for( int j = tl ; j <= tr ; j ++ )
                        v[ idx ][ j ] = st ++;
                }else if( tr == sz - 1 ){
                    int st = max( len / -2 , v[ idx ][ tl - 1 ] + 1 );
                    for( int j = tl ; j <= tr ; j ++ )
                        v[ idx ][ j ] = st ++;
                }else if( tl == 0 ){
                    int st = min( len / 2 , v[ idx ][ tr + 1 ] - 1 );
                    for( int j = tr ; j >= tl ; j -- )
                        v[ idx ][ j ] = st --;
                }else{
                    int st = max( len / -2 , v[ idx ][ tl - 1 ] + 1 );
//                    printf( "%d\n" , st );
                    if( st + len - 1 >= v[ idx ][ tr + 1 ] )
                        st -= ( st + len - v[ idx ][ tr + 1 ] );
//                    printf( "%d\n" , st );
                    for( int j = tl ; j <= tr ; j ++ )
                        v[ idx ][ j ] = st ++;
                }
            }
        }else tl = -1;
    }
}
void solve(){
    for( int i = 0 ; i < k ; i ++ ){
        cal( i );
        int sz = (int)v[ i ].size();
        for( int j = 1 ; j < sz ; j ++ )
            if( v[ i ][ j ] <= v[ i ][ j - 1 ] ){
                puts( "Incorrect sequence" );
                return;
            }
    }
    int tsz = n / k + ( n % k != 0 );
    for( int i = 0 ; i < tsz ; i ++ )
        for( int j = 0 ; j < k ; j ++ )
            if( i < (int)v[ j ].size() )
                printf( "%d " , v[ j ][ i ] );
    puts( "" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}