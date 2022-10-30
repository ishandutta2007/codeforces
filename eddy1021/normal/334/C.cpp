#include <stdio.h>
#define ll long long
ll n , max , ans;
void find_max(){
	max = 1;
	while( !( n % max ) ) max *= 3;
}
int main(){
	scanf( "%I64d" , &n );
	find_max();
	printf( "%I64d\n" , n / max + 1 );
}