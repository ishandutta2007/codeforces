#include <stdio.h>
int p,cnt,n,num;
int test( int a , int x ){
	int now = 1;
	while( --x ){
		now *= a; now %= p;
		if( now == 1 ) return 0;
	}
	now *= a; now %= p;
	if( now == 1 ) return 1;
	return 0;
}
int main(){
	scanf("%d",&p);
	for( int i=1;i<p;i++ ){
		cnt += test( i , p-1 );
	}
	printf("%d\n",cnt);
}