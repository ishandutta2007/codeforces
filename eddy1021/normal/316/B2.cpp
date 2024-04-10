#include <stdio.h>
#define N 1010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , x , settp , pos , tag;
int p[ N ] , son[ N ] , set[ N ] , dp[ N ];
void init(){
	n = getint(); x = getint(); dp[ 0 ] = 1;
	for( int i = 1 ; i <= n ; i ++ ){
		p[ i ] = getint();
		if( p[ i ] ) son[ p[ i ] ] = i;
	}
}
void run( int idx , int no ){
	if( idx == x ){
		tag = 1; pos = no;
	}
	if( tag ) return;
	if( son[ idx ] )
		run( son[ idx ] , no + 1 );
	else set[ settp ++ ] = no;
}
void process(){
	for( int i = 1 ; i <= n ; i ++ )
		if( !p[ i ] ){
			tag = 0; run( i , 1 );
		}
	for( int i = 0 ; i < settp ; i ++ )
		for( int j = n ; j >= set[ i ] ; j -- )
			if( dp[ j - set[ i ] ] ) dp[ j ] = 1;
	for( int i = 0 ; i + pos <= n ; i ++ )
		if( dp[ i ] ) printf( "%d\n" , i + pos );
}
int main(){
	init();
	process();
}