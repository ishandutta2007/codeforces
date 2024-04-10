#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , sum , cnt[ 5 ] , ans , tmp;
void init(){
	n = getint();
	for( int i = 1 ; i <= n ; i ++ ){
		tmp = getint();
		cnt[ tmp ] ++; sum += tmp;
	}
}
void process(){
	if( sum == 5 || sum < 3 ){ puts( "-1" ); return; }
	ans = tmp = cnt[ 1 ] < cnt[ 2 ] ? cnt[ 1 ] : cnt[ 2 ];
	cnt[ 1 ] -= tmp; cnt[ 2 ] -= tmp; cnt[ 3 ] += tmp; 
	if( cnt[ 1 ] ){
		cnt[ 3 ] += tmp = cnt[ 1 ] / 3; cnt[ 1 ] %= 3;
		if( cnt[ 1 ] ){
			if( cnt[ 1 ] == 1 && cnt[ 3 ] ) ans += 2 * tmp + 1;
			else ans += 2 * tmp + 2;
		}else ans += 2 * tmp;
	}
	if( cnt[ 2 ] ){
		cnt[ 3 ] += 2 * ( tmp = cnt[ 2 ] / 3 ); cnt[ 2 ] %= 3;
		if( cnt[ 2 ] ){
			if( cnt[ 2 ] == 1 && cnt[ 4 ] ) ans += 2 * tmp + 1;
			else ans += 2 * tmp + 2;
		}else ans += 2 * tmp;
	}
	printf( "%d\n" , ans );
}
int main(){
	init();
	process();
}