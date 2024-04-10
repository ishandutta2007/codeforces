#include <stdio.h>
#include <stdlib.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int tmp;
int main(){
	for( int i=1;i<=5;i++ )
		for( int j=1;j<=5;j++ ){
			tmp = getint();
			if( tmp ) return printf("%d\n",abs(3-i)+abs(3-j)),0;
		}
}