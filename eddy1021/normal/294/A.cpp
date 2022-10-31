#include <stdio.h>
#define N 110
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , t , x , y;
int bx[ N ];
void init(){
	n = getint();
	for( int i = 1 ; i <= n ; i ++ )
		bx[ i ] = getint();
}
void modify(){
	bx[ x - 1 ] += y - 1;
	bx[ x + 1 ] += bx[ x ] - y;
	bx[ x ] = 0;
}
void process(){
	t = getint(); while( t -- ){
		x = getint(); y = getint();
		modify();
	}
}
void print(){
	for( int i = 1 ; i <= n ; i ++ )
		printf("%d\n",bx[ i ]);
}
int main(){
	init();
	process();
	print();
}