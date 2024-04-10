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
int k;
void build(){

}
void init(){
    k = getint();
}
void solve(){
    if( k % 2 == 0 ) puts( "NO" );
    else{
        puts( "YES" );
        if( k == 1 ){
            puts( "2 1" );
            puts( "1 2" );
            return;
        }
        int n = 2 * ( k + 2 );
        vector< PII > v;
        v.PB( MP( k + 2 , 2 * k + 4 ) );
        for( int i = 1 ; i < k + 1 ; i ++ )
            if( i != k ){
                v.PB( MP( k + 2 , i ) );
                v.PB( MP( 2 * k + 4 , i + k + 2 ) );
            }
        v.PB( MP( k , k + 1 ) );
        v.PB( MP( 2 * k + 2 , 2 * k + 3 ) );
        for( int i = 1 ; i <= k + 1 ; i ++ )
            for( int j = i + 1 + ( i & 1 ) ; j <= k + 1 ; j ++ ){
                v.PB( MP( i , j ) );
                v.PB( MP( i + k + 2 , j + k + 2 ) );
            }
        printf( "%d %d\n" , n , (int)v.size() );
        for( int i = 0 ; i < (int)v.size() ; i ++ )
            printf( "%d %d\n" , v[ i ].FI , v[ i ].SE );
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