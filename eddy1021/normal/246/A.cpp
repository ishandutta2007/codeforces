#include<stdio.h>
int main(){
	int n; scanf("%d",&n);
	if( n<3 ) return puts("-1"),0;
	for( int i=n;i;i-- ) printf("%d%c",i,i==1?'\n':' ');
}