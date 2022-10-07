#include<stdio.h>
long long int ans;
void f(int n){
	if(n<0)return;
	if(n==0){
		printf("0 ");
		return;
	}
	int i,j;
	for(i=0;(1<<i)<=n;i++);
	i=1<<i;
	i--;
	f(i-1-n);
	for(j=i-n;j<=n;j++){
		ans+=(i-j)^j;
		printf("%d ",i-j);
	}
}
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=n;i>=0;){
		for(j=0;(1<<j)<=i;j++);
		j=(1<<j)-1;
		for(k=i^j;k<=i;k++)ans+=j;
		i=(i^j)-1;
	}
	printf("%I64d\n",ans);
	ans=0;
	f(n);
}