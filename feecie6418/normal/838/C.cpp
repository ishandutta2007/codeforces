#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[28][250005],jc[250005]={1},ny[250005]={1},n,K,ans=0,mod;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int main(){
	cin>>n>>K>>mod,f[0][0]=1;
	if(n&1)return cout<<Power(K,n),0;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[n]=Power(jc[n],mod-2);
	for(int i=n-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	for(int i=0;i<K;i++){
		for(int j=0;j<n;j++){
			if(!f[i][j])continue;
			int w=n-j,p=w&-w,S=w-p;
			for(int k=S;1;k=(k-1)&S){
				f[i+1][j+k+p]=(f[i+1][j+k+p]+1ll*ny[k+p]*f[i][j])%mod;
				if(!k)break;
			}
		}
	}
	for(int i=0;i<=K;i++)ans=(ans+1ll*f[i][n]*jc[n]%mod*jc[K]%mod*ny[K-i])%mod;
	cout<<(Power(K,n)-ans+mod)%mod;
}
//4 1 100000007