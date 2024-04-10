#include <stdio.h>
#include <string.h>
#define N 1000010
int num[N],n,now=1;
char c[N],l[N],r[N];
void print( int x ){
	if( l[x] ) print( x+1 );
	printf("%d\n",num[x]);
	if( r[x] ) print( x+1 );
}
int main(){
	scanf("%s",c); num[now] = 1;
	n = strlen(c);
	for( int i=0;i<n-1;i++ ){
		if( c[i]=='l' ) l[now] = 1;
		else r[now] = 1;
		num[++now] = i+2;
	}
	print(1);
}