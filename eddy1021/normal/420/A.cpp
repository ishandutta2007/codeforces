#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int l;
char c[ N ];
void init(){
    scanf( "%s" , c );
}
bool is( char ctmp ){
    if( ctmp == 'A' ) return true;
    if( ctmp == 'H' ) return true;
    if( ctmp == 'I' ) return true;
    if( ctmp == 'M' ) return true;
    if( ctmp == 'O' ) return true;
    if( ctmp == 'T' ) return true;
    if( ctmp == 'U' ) return true;
    if( ctmp == 'V' ) return true;
    if( ctmp == 'W' ) return true;
    if( ctmp == 'X' ) return true;
    if( ctmp == 'Y' ) return true;
    return false;
}
bool check(){
    l = strlen( c );
    for( int i = 0 ; i < l ; i ++ )
        if( c[ i ] != c[ l - i - 1 ] )
            return false;
        else if( !is( c[ i ] ) )
            return false;
    return true;
}
void solve(){
    puts( check() ? "YES" : "NO" );
}
int main(){
    init();
    solve();
}