#include <stdio.h>
int n,m,max;
int main(){
	scanf("%d%d",&n,&m);
	max = n<m?n:m;
	printf("%d\n",max+1);
	for( int i=0;i<=max;i++ )
		printf("%d %d\n",i,m-i);
}