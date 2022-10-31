#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int mod=1000000007;
	long long ret=1;
	if(c>a||c==1){
		for(int i=0;i<a;i++)ret=ret*b%mod;
	}else if(c==a){
		for(int i=0;i<(a+1)/2;i++)ret=ret*b%mod;
	}else if(c%2==1){
		ret=b*b;
	}else ret=b;
	printf("%d\n",ret);
}