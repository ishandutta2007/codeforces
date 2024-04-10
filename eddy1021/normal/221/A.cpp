#include <stdio.h>
int main(){
	int n,i; scanf("%d",&n); printf("%d ",n);
	if( n>1 ) for( i=1;i<n;printf("%d ",i),i++ ); puts("");
}