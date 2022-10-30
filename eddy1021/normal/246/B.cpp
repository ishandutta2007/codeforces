#include <stdio.h>
int n,t,s;
int main(){
	scanf("%d",&n); for( int i=0;i<n;i++ ) scanf("%d",&t),s+=t;
	printf("%d\n",s%n?n-1:n);
}