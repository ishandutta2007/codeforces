// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009
#define mod7 1000000007
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
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 1020
bool clr[ N ][ N ];
int n , m , k;
void build(){
    
}
void init(){
    n = getint(); m = getint(); k = getint();
}
bool bad( int ti , int tj ){
    if( clr[ ti - 1 ][ tj ] && clr[ ti ][ tj - 1 ] && clr[ ti - 1 ][ tj - 1 ] ) return true;
    if( clr[ ti - 1 ][ tj ] && clr[ ti ][ tj + 1 ] && clr[ ti - 1 ][ tj + 1 ] ) return true;
    if( clr[ ti + 1 ][ tj ] && clr[ ti ][ tj - 1 ] && clr[ ti + 1 ][ tj - 1 ] ) return true;
    if( clr[ ti + 1 ][ tj ] && clr[ ti ][ tj + 1 ] && clr[ ti + 1 ][ tj + 1 ] ) return true;
    return false;
}
void solve(){
    for( int i = 1 ; i <= k ; i ++ ){
        int ti , tj;
        ti = getint(); tj = getint();
        clr[ ti ][ tj ] = true;
        if( bad( ti , tj ) ){
            printf( "%d\n" , i );
            return;
        }   
    }
    puts( "0" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}