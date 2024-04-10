#include <stdio.h>
#include <string.h>
#define L 20
char c[ L ]; int lft , len;
void modify( int idx ){
    int mx = c[ idx ] , pos = idx;
    for( int i = idx + 1 , j = 1 ; i < len && j <= lft ; i ++ , j ++ )
        if( c[ i ] > mx ) mx = c[ i ] , pos = i;
    lft -= pos - idx;
    char ctmp = c[ pos ];
    for( int i = pos ; i > idx ; i -- )
        c[ i ] = c[ i - 1 ];
    c[ idx ] = ctmp;
}
int main(){
    scanf( "%s%d" , c , &lft );
    len = strlen( c );
    for( int i = 0 ; i < len && lft > 0 ; i ++ )
        modify( i );
    puts( c );
}