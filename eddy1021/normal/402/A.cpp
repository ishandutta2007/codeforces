#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int k , a , b , v;
void process(){
	int got = 0;
	for( int i = 1 ; ; i ++ ){
		got += v;
		for( int j = 1 ; j < k && b > 0 ; j ++ )
			b -- , got += v;
		if( got >= a ){
			printf( "%d\n" , i );
			return;
		}
	}
}
int main(){
	k = getint(); a = getint();
	b = getint(); v = getint();
	process();
}