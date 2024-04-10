#include <stdio.h>
#include <string.h>
#define N 1000010
#define ll long long
ll gcd( ll x , ll y ){
	ll r;
	while( y ) r = x % y , x = y , y = r;
	return x;
}
char c1[ N ] , c2[ N ];
ll a , b , l1 , l2 , g , ans;
int cnt[ N ][ 26 ][ 2 ];
int main(){
	scanf( "%I64d%I64d" , &a , &b );
	scanf( "%s%s" , c1 , c2 );
	l1 = strlen( c1 ); l2 = strlen( c2 );
	g = gcd( l1 , l2 );
	for( int i = 0 ; i < l1 ; i ++ )
		cnt[ i % g ][ c1[ i ] - 'a' ][ 0 ] ++;
	for( int i = 0 ; i < l2 ; i ++ )
		cnt[ i % g ][ c2[ i ] - 'a' ][ 1 ] ++;
	ans = l1 * l2 / g;
	for( int i = 0 ; i < g ; i ++ )
		for( int j = 0 ; j < 26 ; j ++ )
			ans -= ( ll ) cnt[ i ][ j ][ 0 ] * cnt[ i ][ j ][ 1 ];
	ans *= a / ( l2 / g );
	printf( "%I64d\n" , ans );
}