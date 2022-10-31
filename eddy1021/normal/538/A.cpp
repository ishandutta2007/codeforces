// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009int
#define mod7 1000000007int 
#define INF 1023456789int
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
    if( _x == 0 ) return 1;
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
char c[ N ];
char c2[ N ] = "0CODEFORCES";
int len;
void init(){
    scanf( "%s" , c + 1 );
    len = strlen( c + 1 );
}
void solve(){
    if( len < 10 ){
        puts( "NO" );
    }else if( len == 10 ){
        for( int i = 1 ; i <= len ; i ++ )
            if( c[ i ] != c2[ i ] ){
                puts( "NO" );
                return;
            }
        puts( "YES" );
        return;
    }else{
        int cut = len - 10;
        for( int i = 1 ; i <= len - cut + 1 ; i ++ ){
            int now = 1; bool flag = true;
            for( int j = 1 ; j < i ; j ++ )
                if( c[ j ] != c2[ now ] ) flag = false;
                else now ++;
            for( int j = i + cut ; j <= len ; j ++ )
                if( c[ j ] != c2[ now ] ) flag = false;
                else now ++;
            if( flag ){
                puts( "YES" );
                return;
            }
        }
        puts( "NO" );
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