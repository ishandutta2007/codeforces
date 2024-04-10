#include <stdio.h>
#include <string.h>
char c[10]; int n,x;
int main(){
	scanf("%d",&n);
	while( n-- ){
		scanf("%s",c);
		if( !strcmp( c , "++X" ) ) x++;
		else if( !strcmp( c , "X++"  ) ) x++;
		else if( !strcmp( c , "--X" ) ) x--;
		else if( !strcmp( c , "X--" ) ) x--;
	}
	printf("%d\n",x);
}