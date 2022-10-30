#include <stdio.h>
#define N 3010
char c[ N ];
int l[ N ] , r[ N ] , n;
void process(){
    int idx = 0 , got = 0 , ans = 0;
    for( int i = 1 ; i <= n ; i ++ )
        if( c[ i ] == 'L' ) got = 0;
        else if( c[ i ] == 'R' ) got = 1 , idx = i;
        else if( got ) l[ i ] = i - idx;
    got = 0;
    for( int i = n ; i ; i -- )
        if( c[ i ] == 'R' ) got = 0;
        else if( c[ i ] == 'L' ) got = 1 , idx = i;
        else if( got ) r[ i ] = idx - i;
    for( int i = 1 ; i <= n ; i ++ )
        if( c[ i ] == '.' && l[ i ] == r[ i ] )
            ans ++;
    printf( "%d\n" , ans );
}
int main(){
    scanf( "%d" , &n );
    scanf( "%s" , c + 1 );
    process();
}