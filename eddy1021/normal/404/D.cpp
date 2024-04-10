#include <stdio.h>
#include <string.h>
#define N 1000010
#define mod 1000000007
#define ll long long
char c[ N ]; int l;
ll pre[ 3 ]={ 1 , 1 , 0 };
void process(){
	for( int i = 1 ; i <= l ; i ++ ){
		ll now[ 3 ] = {};
		if( c[ i ] == '0' || c[ i ] == '?' )
			now[ 0 ] += pre[ 0 ];
		if( c[ i ] == '1' || c[ i ] == '?' ){
			now[ 0 ] += pre[ 2 ];
			now[ 1 ] += pre[ 0 ];
		}
		if( c[ i ] == '2' || c[ i ] == '?' )
			now[ 1 ] += pre[ 2 ];
		if( c[ i ] == '*' || c[ i ] == '?' )
			now[ 2 ] += pre[ 2 ] + pre[ 1 ];
		for( int j = 0 ; j < 3 ; j ++ )
			pre[ j ] = now[ j ] % mod;
	}
	printf( "%I64d\n" , ( pre[ 0 ] + pre[ 2 ] ) % mod );
}
int main(){
	scanf( "%s" , c + 1 );
	l = strlen( c + 1 );
	process();
}