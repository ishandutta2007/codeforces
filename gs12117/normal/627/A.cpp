#include<stdio.h>
long long int a,b,c;
long long int ans;
int main(){
	int i;
	scanf("%I64d%I64d",&a,&b);
	c=a-b;
	if(c<0||c%2!=0){
		printf("0");
		return 0;
	}
	c/=2;
	if((b&c)!=0){
		printf("0");
		return 0;
	}
	ans=1;
	for(i=0;b>0;i--){
		if(b%2==1)ans*=2;
		b/=2;
	}
	if(c==0)ans-=2;
	printf("%I64d",ans);
	return 0;
}