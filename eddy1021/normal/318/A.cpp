#include <stdio.h>
#define ll long long
ll n , k;
int main(){
	scanf( "%I64d%I64d" , &n , &k );
	if( k > ( n + 1 ) >> 1 ){
		k -= ( n + 1 ) >> 1;
		printf( "%I64d\n" , k << 1 );
	}else
		printf( "%I64d\n" , ( k << 1 ) - 1 );
}