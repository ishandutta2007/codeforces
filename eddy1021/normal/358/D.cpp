#include <stdio.h>
#define N 3010
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c == '-' ) c=getchar() , tmp = -1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
int n , jy[ N ][ 3 ] , dp[ N ][ 4 ];
bool got[ N ][ 4 ];
int DP( int r , int rr ){
	if( r == 1 ) return jy[ 1 ][ rr ];
	if( got[ r ][ rr ] ) return dp[ r ][ rr ];
	got[ r ][ rr ] = 1;
	int max = 0 , tmp;
	tmp = jy[ r ][ rr ] + DP( r - 1 , 1 ); if( tmp > max ) max = tmp;
	tmp = jy[ r ][ rr + 1 ] + DP( r - 1 , 0 ); if( tmp > max ) max = tmp;
	return dp[ r ][ rr ] = max;
}
int main(){
	n = getint();
	for( int i = 0 ; i < 3 ; i ++ )
		for( int j = 1 ; j <= n ; j ++ )
			jy[ j ][ i ] = getint();
	printf( "%d\n" , DP( n , 0 ) );
}