#include <stdio.h>
int a , b , c , d , up , dn , g;
int gcd( int x , int y ){
	int r;
	while( y ) r = x % y , x = y , y = r;
	return x;
}
int main(){
	scanf( "%d%d%d%d" , &a , &b , &c , &d );
	if( a * d > b * c ){
		int t = a; a = b; b = t;
		t = c; c = d; d = t;
	}
	up = ( b * c - a * d ) * d;
	dn = b * c * d;
	g = gcd( up , dn );
	up /= g; dn /= g;
	printf( "%d/%d\n" , up , dn );
}