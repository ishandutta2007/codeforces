#include <stdio.h>
int n , n2 , n3;
int max( int x , int y ){ return x>y?x:y; }
int main(){
	scanf( "%d" , &n );
	n2 = n / 10;
	n3 = ( n / 100 ) * 10 + n % 10;
 	printf( "%d\n" , max( n , max( n2 , n3 ) ) );
}