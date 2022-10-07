#include<stdio.h>
int n,ans;
int main(){
	int i;
	scanf("%d",&n);
	if(n%2==0){
		for(i=0;(1<<i)<=n;i++);
		ans=(n-(1<<(i-1)))/2;
	}
	else ans=(n-1)/2;
	printf("%d",ans);
	return 0;
}