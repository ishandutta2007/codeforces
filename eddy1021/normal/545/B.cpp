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
#define N 100010
char c1[ N ] , c2[ N ];
int n;
void build(){

}
void init(){
    scanf( "%s%s" , c1 , c2 );
    n = strlen( c1 );
}
void solve(){
    int cnt = 0;
    for( int i = 0 ; i < n ; i ++ )
        if( c1[ i ] != c2[ i ] ) cnt ++;
    if( cnt % 2 ){
        puts( "impossible" );
    }else{
        cnt /= 2;
        for( int i = 0 ; i < n ; i ++ )
            if( c1[ i ] != c2[ i ] ){
                if( cnt ) putchar( c1[ i ] ) , cnt --;
                else putchar( c2[ i ] );
            }else putchar( c1[ i ] );
        puts( "" );
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