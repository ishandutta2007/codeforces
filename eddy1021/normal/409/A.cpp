#include <stdio.h>
#include <string.h>
#define L 30
char c1[ L ] , c2[ L ];
int n1 , n2 , l;
int trans( char ctmp ){
    if( ctmp == '8' ) return 1;
    if( ctmp == '[' ) return 2;
    if( ctmp == '(' ) return 3;
}
void compare( int idx ){
    if( trans( c1[ idx ] ) == trans( c2[ idx ] ) )
        return ;
    if( trans( c1[ idx ] ) == 1 && trans( c2[ idx ] ) == 2 )
        n1 ++;
    else if( trans( c1[ idx ] ) == 2 && trans( c2[ idx ] ) == 3 )
        n1 ++;
    else if( trans( c1[ idx ] ) == 3 && trans( c2[ idx ] ) == 1 )
        n1 ++;
    else n2 ++;
}
void check(){
    l = strlen( c1 );
    for( int i = 0 ; i < l ; i += 2 )
        compare( i );
    if( n1 == n2 ) puts( "TIE" );
    else if( n1 > n2 ) puts( "TEAM 1 WINS" );
    else puts( "TEAM 2 WINS" );
}
int main(){
    scanf( "%s%s" , c1 , c2 );
    check();
}