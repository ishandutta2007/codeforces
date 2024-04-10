#include <stdio.h>
#define L 10
char c[L];
int main(){
	for( int i=0;i<8;i++ ){
		scanf("%s",c);
		for( int j=1;j<8;j++ ) if( c[j]==c[j-1] ) return puts("NO"),0;
	}
	puts("YES");
}