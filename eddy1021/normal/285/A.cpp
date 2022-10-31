#include <stdio.h>
int n,k,l,r;
int main(){
	scanf("%d%d",&n,&k);
	for( r=n,l=1;l<=k;  ){
		printf("%d ",r); r-- , l++;
	}
	for( int i=1;i<=r;i++ ) printf("%d%c",i,i==r?'\n':' ');
}