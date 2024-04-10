#include <stdio.h>
#define L 100010
char c[L]; bool flag;
int main(){
	scanf("%s",c);
	for( int i=0;c[i];i++ ) if( c[i]=='0' ) flag = true;
	if( !flag ) return puts(c+1),0;
	for( int i=0;c[i];i++ ){
		if( c[i]=='0' ) return puts(c+i+1),0;
		putchar(c[i]);
	}
}