#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(b<=a-a/c){
		printf("%d\n",b);
		return 0;
	}
	int d=b-a+a/c+1;
	long long now=1;
	long long val=2;
	int mod=1000000009;
	while(d){
		if(d%2)now=now*val%mod;
		d/=2;
		val=val*val%mod;
	}
	now=(now+mod-2)%mod;
	now=now*c%mod;
	now=(now+b-c*(b-a+a/c))%mod;
	printf("%d\n",(int)now);
}