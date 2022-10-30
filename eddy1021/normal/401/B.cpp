#include <stdio.h>
#define N 4010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int tag[ N ] , x , k , t , a , b;
void init(){
	x = getint(); k = getint();
	while( k -- ){
		t = getint();
		if( t == 1 ){
			a = getint(); b = getint();
			tag[ a ] = tag[ b ] = 1;
		}else{
			a = getint();
			tag[ a ] = 1;
		}
	}
	tag[ x ] = 1;
}
void process(){
	int min = 0 , max = 0 , cnt = 0;
	for( int i = 1 ; i <= x ; i ++ )
		if( tag[ i ] ){
			max += cnt;
			min += ( cnt / 2 ) + ( cnt % 2 );
			cnt = 0;
		}else cnt ++;
	printf( "%d %d\n" , min , max );
}
int main(){
	init();
	process();
}