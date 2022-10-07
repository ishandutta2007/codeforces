#include<stdio.h>
long long int n,m,p;
long long int mod=1000000009;
long long int unum;
long long int ans;
long long int tpow(long long int x){
	if(x==0)return 1;
	long long int r=tpow(x/2);
	if(x%2==0)return r*r%mod;
	return r*r*2%mod;
}
int main(){
	int i;
	scanf("%I64d%I64d%I64d",&n,&m,&p);
	if(n-(n-m)*p<p){
		printf("%I64d",m);
		return 0;
	}
	unum=(n-(n-m)*p)/p;
	ans=tpow(unum);
	ans+=mod-1;
	ans%=mod;
	ans*=2*p;
	ans%=mod;
	ans+=m-p*unum;
	ans%=mod;
	printf("%I64d",ans);
	return 0;
}