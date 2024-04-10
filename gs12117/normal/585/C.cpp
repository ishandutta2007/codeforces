#include<stdio.h>
long long int mgcd(long long int x,long long int y){
	if(x==0)return y;
	return mgcd(y%x,x);
}
int main(){
	long long int a,b;
	scanf("%I64d%I64d",&a,&b);
	if(mgcd(a,b)!=1){
		printf("Impossible");
	}
	else{
		while(a+b!=1){
			if(a>b){
				printf("%I64dA",(a-1)/b);
				a%=b;
			}
			else{
				printf("%I64dB",(b-1)/a);
				b%=a;
			}
		}
	}
	return 0;
}