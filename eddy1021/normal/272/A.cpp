#include <stdio.h>
int i,t,n,s,a;
int main(){
	scanf("%d",&n);
	for( i=0;i<n;i++ ) scanf("%d",&t),s+=t;
	for( i=1;i<6;i++ ) if( (s+i-1)%(n+1) ) a++;
	printf("%d\n",a);
}