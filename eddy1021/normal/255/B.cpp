#include <stdio.h>
#define L 1000001
char c[L]; int cntx,cnty;
int main(){
	scanf("%s",c);
	for( int i=0;c[i];i++ )
		if( c[i]=='x' ) cntx++;
		else if( c[i]=='y' ) cnty++;
	if( cntx>cnty ){
		cntx-=cnty; while( cntx-- ) putchar('x');
	}
	else if( cnty>cntx ){
		cnty-=cntx; while( cnty-- ) putchar('y');
	}
	putchar('\n');
}