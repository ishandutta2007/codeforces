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
int getint(){
    int x=0,tmp=1; char tc=getchar();
    while( (tc<'0'||tc>'9')&&tc!='-' ) tc=getchar();
    if( tc == '-' ) tc=getchar() , tmp = -1;
    while(tc>='0'&&tc<='9') x*=10,x+=(tc-'0'),tc=getchar();
    return x*tmp;
}
int __ = 1;
/*********default*********/
char c[ 4 ][ 4 ];
void build(){

}
void init(){
    for( int i = 1 ; i <= 3 ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
}
bool Xwin , Owin;
int cntx , cnto , bad;
void check(){
    int xwin1 = 0 , owin1 = 0 , xwin2 = 0 , owin2 = 0;
    for( int i = 1 ; i <= 3 ; i ++ ){
        if( c[ i ][ 1 ] == '0' && c[ i ][ 2 ] == '0' && c[ i ][ 3 ] == '0' )
            Owin = true , owin1 ++;
        if( c[ i ][ 1 ] == 'X' && c[ i ][ 2 ] == 'X' && c[ i ][ 3 ] == 'X' )
            Xwin = true , xwin1 ++;
        if( c[ 1 ][ i ] == '0' && c[ 2 ][ i ] == '0' && c[ 3 ][ i ] == '0' )
            Owin = true , owin2 ++;
        if( c[ 1 ][ i ] == 'X' && c[ 2 ][ i ] == 'X' && c[ 3 ][ i ] == 'X' )
            Xwin = true , xwin2 ++;
    }
    if( owin1 > 1 || xwin1 > 1 || owin2 > 1 || xwin2 > 1 ) Owin = Xwin = true;
    if( ( c[ 1 ][ 1 ] == '0' ) && ( c[ 2 ][ 2 ] == '0' ) && ( c[ 3 ][ 3 ] == '0' ) )
        Owin = true;
    if( ( c[ 1 ][ 1 ] == 'X' ) && ( c[ 2 ][ 2 ] == 'X' ) && ( c[ 3 ][ 3 ] == 'X' ) )
        Xwin = true;
    if( ( c[ 3 ][ 1 ] == '0' ) && ( c[ 2 ][ 2 ] == '0' ) && ( c[ 1 ][ 3 ] == '0' ) )
        Owin = true;
    if( ( c[ 3 ][ 1 ] == 'X' ) && ( c[ 2 ][ 2 ] == 'X' ) && ( c[ 1 ][ 3 ] == 'X' ) )
        Xwin = true;
    for( int i = 1 ; i <= 3 ; i ++ )
        for( int j = 1 ; j <= 3 ; j ++ )
            if( c[ i ][ j ] == '0' ) cnto ++;
            else if( c[ i ][ j ] == 'X' ) cntx ++;
}
bool invalid(){
    if( Xwin && Owin ) return true;
    if( cntx < cnto || cntx > cnto + 1 ) return true;
    if( Xwin && cntx == cnto ) return true;
    if( Owin && cntx == cnto + 1 ) return true;
    return false;
}
void solve(){
    check();
    if( invalid() ) puts( "illegal" );
    else if( Xwin ) puts( "the first player won" );
    else if( Owin ) puts( "the second player won" );
    else if( cntx + cnto == 9 ) puts( "draw" );
    else if( cntx == cnto ) puts( "first" );
    else puts( "second" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}