#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,a[20],f[40005],ans,s[105][105];
int P(int x,int y){
	int p=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(x&(1<<i-1))if(y&(1<<j-1))p=1ll*p*s[i][j]%mod;
	return p;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)s[i][j]=1ll*a[i]*Power(a[i]+a[j],mod-2)%mod;
	for(int i=1;i<(1<<n);i++){
		f[i]=1;
		for(int j=i&(i-1);j;j=(j-1)&i){
			f[i]=(f[i]-1ll*f[j]*P(j,i-j)%mod+mod)%mod;
		}
	}
	for(int i=1;i<(1<<n);i++)ans=(ans+1ll*f[i]*P(i,(1<<n)-1-i)%mod*__builtin_popcount(i))%mod;
	cout<<ans;
}