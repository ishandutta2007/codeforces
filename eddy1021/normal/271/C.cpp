#include <stdio.h>
int n,k,i,no;
int main(){
	scanf("%d%d",&n,&k);
	if( n/k<3 ) return puts("-1"),0;
	for( i=0;i<k;no++,i++ ) printf("%d ",no%k+1);
	for( no++;i<n;no++,i++ ) printf("%d ",no%k+1);
}