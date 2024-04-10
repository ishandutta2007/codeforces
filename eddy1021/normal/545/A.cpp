// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
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
#define N 1010
int n , a[ N ][ N ];
bool live[ N ];
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= n ; j ++ )
            a[ i ][ j ] = getint();
}
vector<int> ans;
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= n ; j ++ )
            if( a[ i ][ j ] == 3 ) live[ i ] = live[ j ] = true;
            else if( a[ i ][ j ] == 1 ) live[ i ] = true;
            else if( a[ i ][ j ] == 2 ) live[ j ] = true;
    for( int i = 1 ; i <= n ; i ++ )
        if( !live[ i ] ) ans.PB( i );
    printf( "%d\n" , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d%c" , ans[ i ] , i == (int)ans.size() - 1 ? '\n' : ' ' );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}