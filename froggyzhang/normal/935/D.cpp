#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
const int mod=1e9+7;
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
int n,m,a[N],b[N],ans,p,inv,i2;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	p=1;
	inv=qpow(m,mod-2);
	i2=qpow(2,mod-2);
	for(int i=1;i<=n;++i){
		if(a[i]&&b[i]){
			if(a[i]==b[i])continue;
			if(a[i]>b[i])ans=(ans+p)%mod;
			break;
		}
		else if(a[i]){
			ans=(ans+1LL*p*(a[i]-1)%mod*inv)%mod;
			p=1LL*p*inv%mod;
		}
		else if(b[i]){
			ans=(ans+1LL*p*(m-b[i])%mod*inv)%mod;
			p=1LL*p*inv%mod;
		}
		else{
			ans=(ans+1LL*p*i2%mod*inv%mod*(m-1))%mod;
			p=1LL*p*inv%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}