#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
#define N 1000100
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,k,fac[N],inv[N],f[N],pre[N],suf[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		inv[i]=1LL*inv[i+1]*(i+1)%mod;
	}
}
int Lagrange(int n,int k,int *a){
	if(k<=n)return a[k];
	pre[0]=suf[n+1]=1;
	for(int i=1;i<=n;++i){
		pre[i]=1LL*pre[i-1]*(k-i)%mod;
	}
	for(int i=n;i>=0;--i){
		suf[i]=1LL*suf[i+1]*(k-i)%mod;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*inv[i-1]*inv[n-i]%mod*pre[i-1]%mod*suf[i+1]%mod*((n-i)&1?-1:1)*f[i]%mod)%mod;
	}
	return (ans%mod+mod)%mod;
}
int main(){
	n=read(),k=read();
	init(k+2);
	for(int i=1;i<=k+2;++i){
		f[i]=(f[i-1]+qpow(i,k))%mod;
	}
	printf("%d\n",Lagrange(k+2,n,f));
	return 0;
}