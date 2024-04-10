#include <stdio.h>
#define ll long long
ll x , y , m , cnt;
void swap(){ ll t = x; x = y; y = t; }
int main(){
	scanf( "%I64d%I64d%I64d" , &x , &y , &m );
	if( x > y ) swap();
	if( x < 0 && y > 0 && y < m ){
		cnt = ( y - x - 1 ) / y;
		x += cnt * y;
	}
	while( y < m ){
		x += y; cnt ++; swap();
		if( ( x <= 0 ) && ( y <= 0 ) ) break;
	}
	printf( "%I64d\n" , y >= m ? cnt : -1 );
}