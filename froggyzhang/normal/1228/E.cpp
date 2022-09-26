#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
#define N 555
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
int n,k;
int fac[N],inv[N],ans;
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
int C(int n,int m){
	return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod; 
}
int main(){
	n=read(),k=read();
	if(k==1)return !printf("1\n");
	init(n);
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			ans=(ans+1LL*C(n,i)*C(n,j)%mod*qpow(k,n*n-(i+j)*n+i*j)%mod*qpow(k-1,(i+j)*n-i*j)*((i+j)&1?-1:1))%mod;
		}
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}