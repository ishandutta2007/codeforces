// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789ll
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
#define N 200010
#define Z 30
char c[ 2 ][ N ];
int len , ans , a1 , a2;
int idx[ Z ][ Z ];
int idx2[ Z ] , idx3[ Z ];
void build(){
    
}
void init(){
    len = getint();
    for( int i = 0 ; i < 2 ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
    a1 = a2 = -1;
    for( int i = 1 ; i <= len ; i ++ )
        if( c[ 0 ][ i ] != c[ 1 ][ i ] ){
            ans ++;
            idx[ c[ 0 ][ i ] - 'a' ][ c[ 1 ][ i ] - 'a' ] = i;
            idx2[ c[ 0 ][ i ] - 'a' ] = i; 
            idx3[ c[ 1 ][ i ] - 'a' ] = i; 
        }
}
bool can2(){
    for( int i = 0 ; i < 26 ; i ++ )
        for( int j = 0 ; j < 26 ; j ++ )
            if( idx[ i ][ j ] && idx[ j ][ i ] ){
                a1 = idx[ i ][ j ];
                a2 = idx[ j ][ i ];
                ans -= 2;
                return true;
            }
    return false;
}
bool can1(){
    for( int i = 0 ; i < 26 ; i ++ )
       if( idx2[ i ] && idx3[ i ] ){
            a1 = idx2[ i ];
            a2 = idx3[ i ];
            ans --;
            return true;
       }
    return false;
}
void solve(){
    if( can2() );
    else if( can1() );
    printf( "%d\n%d %d\n" , ans , a1 , a2 );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}