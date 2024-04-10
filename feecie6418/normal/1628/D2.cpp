#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,jc[1000005],ny[1000005],pw2[1000005];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
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
	jc[0]=ny[0]=pw2[0]=1;
	for(int i=1;i<=1000000;i++)jc[i]=1ll*jc[i-1]*i%mod,pw2[i]=1ll*pw2[i-1]*(mod+1)/2%mod;
	ny[1000000]=Power(jc[1000000],mod-2);
	for(int i=999999;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	int t;
	scanf("%d",&t);
	while(t--){
		int K,ans=0;
		scanf("%d%d%d",&n,&m,&K);
		for(int i=1;i<n;i++){
			ans=(ans+1ll*C(n-i-1,m-i)*i%mod*pw2[n-i])%mod;
		}
		if(m==n)ans=n;
		cout<<1ll*ans*K%mod<<'\n';
	}
}