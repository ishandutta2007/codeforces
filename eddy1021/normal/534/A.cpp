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
void build(){

}
#define N 5010
int n , ans[ N ];
void init(){
    n = getint();
}
void solve(){
    if( n <= 2 ){
        puts( "1" );
        puts( "1" );
        return;
    }else if( n == 3 ){
        puts( "2" );
        puts( "1 3" );   
    }else if( n == 4 ){
        puts( "4" );
        puts( "3 1 4 2" );
    }else{
        for( int i = 1 ; i <= ( n + 1 ) / 2 ; i ++ )
            ans[ i * 2 - 1 ] = i;
        for( int i = ( n + 1 ) / 2 + 1 , j = 1 ; i <= n ; i ++ , j ++ )
            ans[ j * 2 ] = i;
        printf( "%d\n" , n );
        for( int i = 1 ; i <= n ; i ++ )
            printf( "%d%c" , ans[ i ] , i == n ? '\n' : ' ' );
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