#include <stdio.h>
#include <string.h>
#define N 1010
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c == '-' ) c=getchar() , tmp = -1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
int n , m , tag[ N ] , a , b;
void init(){
	n = getint(); m = getint();
	while( m -- ){
		a = getint(); b = getint();
		tag[ a ] = 1;
		tag[ b ] = 1;
	}
}
void print(){
	printf( "%d\n" , n - 1 );
	for( int i = 1 ; i <= n ; i ++ )
		if( !tag[ i ] ){
			for( int j = 1 ; j <= n ; j ++ )
				if( j != i )
					printf( "%d %d\n" , i , j );
			return ;
		}
}
int main(){
	init();
	print();
}