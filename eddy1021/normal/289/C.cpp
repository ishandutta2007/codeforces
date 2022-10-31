#include <stdio.h>
int n , k;
void process(){
	if( n == 1 && k == 1 ){
		puts("a"); return;
	}
	if( k == 1 || k > n ){
		puts("-1"); return;
	}
	int save = k - 2; n -= save;
	for( int i=0;i<n;i++ )
		if( i&1 ) putchar('b');
		else putchar('a');
	for( int i=0;i<save;i++ )
		putchar( 'a' + i + 2 );
	puts("");
}
int main(){
	scanf("%d%d",&n,&k);
	process();
}