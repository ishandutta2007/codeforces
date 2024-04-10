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
#define N 110
void build(){

}
int n , m;
char c[ N ][ N ];
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
}
int vl[ N ][ N ] , ans;
void modify( int ti , int tj , int tdlt ){
    ans ++;
    for( int i = 1 ; i <= ti ; i ++ )
        for( int j = 1 ; j <= tj ; j ++ )
            vl[ i ][ j ] += tdlt;
}
void solve(){
    for( int i = n ; i >= 1 ; i -- )
        for( int j = m ; j >= 1 ; j -- )
            if( c[ i ][ j ] == 'W' && vl[ i ][ j ] != 1 ) modify( i , j , 1 - vl[ i ][ j ] );
            else if( c[ i ][ j ] == 'B' && vl[ i ][ j ] != -1 ) modify( i , j , -1 - vl[ i ][ j ] );
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