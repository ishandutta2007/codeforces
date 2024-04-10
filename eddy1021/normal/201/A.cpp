#include <stdio.h>
#define N 110
int x , a;
int main(){
    scanf( "%d" , &x );
    if( x == 1 ){ puts( "1" ); return 0; }
    if( x == 3 ){ puts( "5" ); return 0; }
    if( !( x % 2 ) ){
        int sum = 0;
        for( a = 1 ; ; a ++ ){
            sum += 4 * a;
            if( sum >= x ) break;
        }
    }else{
        int sum = 1;
        for( a = 1 ; ; a ++ ){
            sum += 4 * a;
            if( sum >= x ){
                sum -= 4 * a;
                break;
            }
        }
//        printf( "%d %d\n" , a , sum );
//       x -= sum;
//        if( a % 2 && x % 4 == 2 ) a ++;
    }
    printf( "%d\n" , 2 * a + 1 );
}