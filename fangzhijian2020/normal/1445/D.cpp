#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||'9'<c)opt|=c=='-',c=getchar();
	while('0'<=c&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int n,a[300005],fac[300005],ifac[300005],ans;
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
int C(int n,int m){
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	n=read();
	for(int i=1;i<=(n<<1);++i)a[i]=read();
	sort(a+1,a+(n<<1)+1);
	fac[0]=1;for(int i=1;i<=(n<<1);++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n<<1]=ksm(fac[n<<1],mod-2);for(int i=(n<<1);i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	for(int i=1;i<=n;++i)ans=(ans+mod-a[i])%mod;
	for(int i=n+1;i<=(n<<1);++i)ans=(ans+a[i])%mod;
	printf("%d\n",1ll*ans*C(n<<1,n)%mod);
	return 0;
}