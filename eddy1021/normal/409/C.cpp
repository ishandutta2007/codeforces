#include <stdio.h>
int mn = -1 , a;
int b[]={1,1,2,7,4};
int main(){
    for( int i = 0 ; i < 5 ; i ++ ){
        scanf( "%d" , &a );
        if( mn == -1 || a / b[ i ] < mn )
            mn = a / b[ i ];
    }
    printf( "%d\n" , mn );
}