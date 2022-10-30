#include <stdio.h>
int t , n , p , x , y , e;
int main(){
	scanf( "%d" , &t ); while( t -- ){
		scanf( "%d%d" , &n , &p );
		x = 1; y = 2; e = 2 * n + p;
		while( e -- ){
			printf( "%d %d\n" , x , y ); y ++;
			if( y > n ) x ++ , y = x + 1;
		}
	}
}