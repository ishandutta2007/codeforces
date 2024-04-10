#include <stdio.h>
#include <string.h>
#define L 1000010
#define ll long long
char c[ L ];
char tmp[ 2 ][ 10 ] = { "heavy" , "metal" };
int cnt[ L ] , l;
ll ans;
bool check( int l , int no ){
	for( int i = 0 ; i < 5 ; i ++ )
		if( c[ l + i ] != tmp[ no ][ i ] )
			return false;
	return true;
}
void set(){
	for( int i = 5 ; i <= l ; i ++ ){
		cnt[ i ] += cnt[ i - 1 ];
		if( check( i - 4 , 0 ) )
			cnt[ i ] ++;
	}			
}
void count(){
	for( int i = 10 ; i <= l ; i ++ )
		if( check( i - 4 , 1 ) )
			ans += cnt[ i - 5 ];
}
int main(){
	scanf( "%s" , c + 1 ); l = strlen( c + 1 );
	set(); count();
	printf( "%I64d\n" , ans );
}