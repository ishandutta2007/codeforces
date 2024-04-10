#include <stdio.h>
#define L 99
char c[L]; int n;
int main(){
	scanf("%s%d",c,&n);
	for( int i=0;c[i];i++ ){
		if( c[i] < 'a' ) c[i] += 'a' - 'A';
		if( c[i] < 'a'+n ) c[i] += 'A' - 'a';
	}
	puts(c);
}