#include<stdio.h>
long long mod=1000000007;
long long rev[1000002];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	rev[1]=1;
	for(int i=2;i<1000002;i++)rev[i]=mod-(mod/i)*rev[mod%i]%mod;
	long long ret=0;
	long long now=1;
	for(int i=0;i<=c;i++){
		int d=i*a+(c-i)*b;
		bool ok=true;
		while(d){
			if(d%10!=a&&d%10!=b)ok=false;
			d/=10;
		}
		if(ok)ret=(ret+now)%mod;
		now=now*(c-i)%mod*rev[i+1]%mod;
	}
	printf("%I64d\n",ret);
}