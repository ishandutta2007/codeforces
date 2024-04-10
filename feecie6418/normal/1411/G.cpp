#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int Power(int x,int y){
	if(y<0)return 0;
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int f[525][525],ans[525],n,m,v[100005],sg[100005],cnt[525];
vector<int> g[100005];
void Gauss(){
	for(int i=0;i<512;i++){
		for(int j=i+1;j<512;j++){
			if(!f[j][i])continue;
			int t=1ll*f[j][i]*Power(f[i][i],mod-2)%mod;
			for(int k=i;k<=512;k++)f[j][k]=(f[j][k]-1ll*t*f[i][k]%mod+mod)%mod;
		}
	}
	for(int i=512-1;i>=0;i--){
		for(int j=i+1;j<512;j++)f[i][512]=(f[i][512]-1ll*ans[j]*f[i][j]%mod+mod)%mod;
		ans[i]=1ll*f[i][512]*Power(f[i][i],mod-2)%mod;
	}
}
void dfs(int x){
	if(v[x])return ;
	bool t[525]={0};
	for(int y:g[x])dfs(y),t[sg[y]]=1;
	while(t[sg[x]])sg[x]++;
	v[x]=1,cnt[sg[x]]++;
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,g[x].push_back(y);
	for(int i=1;i<=n;i++)dfs(i);
	for(int i=1,u=Power(n+1,mod-2);i<512;i++){
		f[i][i]=1;
		for(int j=0;j<512;j++)f[i][j]=(f[i][j]-1ll*u*cnt[i^j]%mod+mod)%mod;
	}
	for(int i=0;i<=512;i++)f[0][i]=1;
	Gauss(),printf("%d\n",(1-ans[0]+mod)%mod);
}