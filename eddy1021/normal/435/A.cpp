#include <stdio.h>
int n , m , a , ans = 1 , pre;
int main(){
    scanf( "%d%d" , &n , &m );
    for( int i = 1 ; i <= n ; i ++ ){
        scanf( "%d" , &a );
        if( a + pre > m ) pre = a , ans ++;
        else pre += a;
    }
    printf( "%d\n" , ans );
}