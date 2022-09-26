#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int mod=1e9+7;
inline ll read(){
	ll x=0,f=1;
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
int fac[N],ifac[N],n,ans,ipw2[N],pw2[N];
ll m,a[N];
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
	fac[0]=pw2[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	ipw2[n]=qpow(pw2[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
		ipw2[i]=(ipw2[i+1]<<1)%mod;
	}
}
inline int C(int n,int m){
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;	
}
int main(){
	n=read(),m=read();
	init(n+1);
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	ll x=0;
	int z=-1;
	for(int i=1;i<=n;++i){
		x+=a[i];
		if(x>m)break;
		if(x+i<=m){ans=(ans+1)%mod;continue;}
		if(~z){
			z=((2*z-C(i-1,m-(x-a[i])))%mod+mod)%mod;
			for(int j=m-(x-a[i]);j>m-x;--j){
				z=(z-C(i,j)+mod)%mod;
			}
		}
		else{
			z=0;
			for(int j=0;j<=m-x;++j){
				z=(z+C(i,j))%mod;
			}	
		}
		ans=(ans+1LL*ipw2[i]*z)%mod;
	}
	printf("%d\n",ans);
	return 0;
}