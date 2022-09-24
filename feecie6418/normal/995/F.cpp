#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,K,f[3005][3005];
vector<int> g[3005];
int Power(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int Interpolation(int n,int K,vector<int> x,vector<int> y){
	int ans=0;
	for(int i=0;i<n;i++){
		int fz=y[i],fm=1;
		for(int j=0;j<n;j++){
			if(i==j)continue;
			fz=1ll*fz*((K-x[j]+mod)%mod)%mod,fm=1ll*fm*((x[i]-x[j]+mod)%mod)%mod;
		}
		ans=(ans+1ll*fz*Power(fm,mod-2)%mod)%mod;
	}
	return ans;
}
void dfs(int x){
	for(int i=1;i<=n+1;i++)f[x][i]=1;
	for(int y:g[x]){
		dfs(y);
		for(int i=1;i<=n+1;i++)f[x][i]=1ll*f[x][i]*f[y][i]%mod;
	}
	for(int i=1;i<=n+1;i++)f[x][i]=(f[x][i-1]+f[x][i])%mod;
}
int main(){
	cin>>n>>K;
	for(int i=2,x;i<=n;i++)cin>>x,g[x].push_back(i);
	dfs(1);
	vector<int> x,y;
	for(int i=1;i<=n+1;i++)x.push_back(i),y.push_back(f[1][i]);
	cout<<Interpolation(n+1,K,x,y);
}