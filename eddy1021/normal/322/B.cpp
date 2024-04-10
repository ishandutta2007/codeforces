#include <stdio.h>
int r , g , b , ans , ans2;
int main(){
	scanf( "%d %d %d" , &r , &g , &b );
	ans = r;
	if( g < ans ) ans = g;
	if( b < ans ) ans = b;
	r -= ans; g -= ans; b -= ans;
	ans2 = r / 3 + g / 3 + b / 3;
	if( r % 3 + g % 3 + b % 3 == 4 && ans ) ans ++;
	printf( "%d\n" , ans + ans2 );
}