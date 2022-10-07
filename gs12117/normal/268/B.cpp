#include<stdio.h>
int n,ans;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		ans+=i*(n-i)+1;
	}
	printf("%d",ans);
}