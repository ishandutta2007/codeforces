#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,f[5005][5005],jc[5005]={1},ny[5005]={1};
int Power(int x,int y) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int main(){
	cin>>n,f[1][0]=jc[1]=ny[1]=1;
	for(int i=2;i<=n;i++){
		f[i][0]=f[i-1][0],jc[i]=1ll*jc[i-1]*i%mod,ny[i]=Power(jc[i],mod-2);
		for(int j=1;j<i;j++)f[i][j]=(1ll*(j+1)*f[i-1][j]+1ll*(i-j)*f[i-1][j-1])%mod;
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i;j<=n;j++)ans=(ans+1ll*f[j][i-1]*jc[n]%mod*ny[j])%mod;
		cout<<ans<<' ';
	}
	return 0;
}