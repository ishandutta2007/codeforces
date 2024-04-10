#include <stdio.h>
#include <string.h>
#define N 15
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c == '-' ) c=getchar() , tmp = -1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
int r , c , ans , lr[ N ] , ud[ N ];
char s[ N ][ N ];
void init(){
	r = getint(); c=getint();
	for( int i = 1 ; i <= r ; i ++ )
		scanf( "%s" , s[ i ] + 1 );			
}
void process(){
	for( int i = 1 ; i <= r ; i ++ )
		for( int j = 1 ; j <= c ; j ++ )
			if( s[ i ][ j ] == 'S' )
				lr[ i ] = 1 , ud[ j ] = 1;
	for( int i = 1 ; i <= r ; i ++ )
		for( int j = 1 ; j <= c ; j ++ )
			if( !lr[ i ] || !ud[ j ] )
				ans ++;
	printf( "%d\n" , ans );
}
int main(){
	init();
	process();
}