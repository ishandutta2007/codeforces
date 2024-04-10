#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
const int mod=1000000007;
int n,k,ny[1000005]={1},prime[1000005],pk[1000005],vst[1000005];
int pre[1000005],suc[1000005],ans=0;
int Power(int x,int y,int mod) {
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
void Sieve(int n){
	pk[1]=1;
	for(int i=2;i<=n;i++){
		if(!vst[i]){
			pk[i]=Power(i,n-1,mod);
			prime[++prime[0]]=i;
		}
		for(int j=1;j<=prime[0]&&i*prime[j]<=n;j++){
			pk[i*prime[j]]=1ll*pk[i]*pk[prime[j]]%mod;
			vst[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=2;i<=n;i++)pk[i]=(pk[i-1]+pk[i])%mod;
}
int main(){
	scanf("%d%d",&k,&n);
	++n;
	Sieve(n);
	for(int i=1;i<=n;i++)ny[i]=1ll*ny[i-1]*i%mod;
	ny[n]=Power(ny[n],mod-2,mod);
	for(int i=n-1;i>0;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	pre[0]=k;
	for(int i=1;i<=n;i++)pre[i]=1ll*pre[i-1]*(k-i)%mod;
	suc[n]=k-n;
	for(int i=n-1;i>=0;i--)suc[i]=1ll*suc[i+1]*(k-i)%mod;
	for(int i=0;i<=n;i++){
		int fz=1ll*(i==0?1:pre[i-1])*(i==n?1:suc[i+1])%mod*pk[i]%mod;
		int fm=1ll*((n-i)%2?-1:1)*ny[i]*ny[n-i]%mod;
		ans=(ans+1ll*(fz+mod)*(fm+mod)%mod)%mod;
	}
	printf("%d\n",ans);
}