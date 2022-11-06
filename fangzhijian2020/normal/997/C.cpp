#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,inv3,fac[1000005],ifac[1000005],ans;
int C(int n,int m){return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){
	n=read();inv3=ksm(3,mod-2);
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);for(int i=n;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	for(int i=1;i<=n;++i){
		Add(ans,!(i&1)?mod-2ll*C(n,i)*ksm(3,(i+1ll*n*(n-i))%(mod-1))%mod:2ll*C(n,i)*ksm(3,(i+1ll*n*(n-i))%(mod-1))%mod);
		Add(ans,!(i&1)?mod-1ll*ksm(3,(1ll*n*n+1)%(mod-1))*C(n,i)%mod*ksm(inv3,(1ll*i*n)%(mod-1))%mod*(ksm(mod+1-ksm(inv3,n-i),n)-1)%mod:1ll*ksm(3,(1ll*n*n+1)%(mod-1))*C(n,i)%mod*ksm(inv3,(1ll*i*n)%(mod-1))%mod*(ksm(mod+1-ksm(inv3,n-i),n)-1)%mod);
	}
	cout<<ans<<"\n";
	return 0;
}