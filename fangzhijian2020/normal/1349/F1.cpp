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
int n,E[5005][5005],fac[5005],ifac[5005];
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
int main(){
	n=read();
	E[0][0]=1;
	for(int i=1;i<=n;++i){
		E[i][0]=1;
		for(int j=1;j<i;++j){
			E[i][j]=Mod(1ll*E[i-1][j]*(j+1)%mod+1ll*E[i-1][j-1]*(i-j)%mod);
		}
	}
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);for(int i=n;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	for(int i=1;i<=n;++i){
		int ans=0;
		for(int j=1;j<=n;++j){
			Add(ans,1ll*E[j][i-1]*fac[n]%mod*ifac[j]%mod);
		}
		cout<<ans<<" ";
	}
	return 0;
}