#include <stdio.h>
#define N 100010
char c[ N ] , tag[ 100 ];
long long ans , base;
int main(){
	scanf( "%s" , c ); base = 10;
	if( c[ 0 ] == '?' ) ans = 9;
	else if( c[ 0 ] >= '0' && c[ 0 ] <= '9' ) ans = 1;
	else{ base = ans = 9; tag[ c[ 0 ] ] = 1; }
	for( int i = 1 ; c[ i ] ; i ++ )
		if( c[ i ] == '?' ) ans *= 10;
		else if( c[ i ] >= 'A' && c[ i ] <= 'J' )
			if( !tag[ c[ i ] ] ){
				ans *= base; tag[ c[ i ] ] = 1; base --;
			}
	printf( "%I64d\n" , ans );
}