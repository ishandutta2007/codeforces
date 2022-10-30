#include <stdio.h>
#include <string.h>
#define N 110
char c[ N ];
bool check(){
    if( strlen( c ) < 5 ) return false;
    bool c1 = false , c2 = false , c3 = false;
    for( int i = 0 ; c[ i ] ; i ++ )
        if( c[ i ] >= 'A' && c[ i ] <= 'Z' ) c1 = true;
        else if( c[ i ] >= 'a' && c[ i ] <= 'z' ) c2 = true;
        else if( c[ i ] >= '0' && c[ i ] <= '9' ) c3 = true;
    return c1 && c2 && c3;
}
int main(){
    scanf( "%s" , c );
    puts( check() ? "Correct" : "Too weak" );
}