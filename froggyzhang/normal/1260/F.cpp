#include<bits/stdc++.h>
using namespace std;
#define N 100020
const int mod=1e9+7;
typedef long long ll;
int n,L[N],R[N],siz[N],maxp[N],rt,ans,vis[N],inv[N];
vector<int> G[N];
void get_root(int u,int fa,int total){
	siz[u]=1;
	maxp[u]=0;
	for(auto v:G[u]){
		if(v==fa||vis[v])continue;
		get_root(v,u,total);
		siz[u]+=siz[v];
		maxp[u]=max(maxp[u],siz[v]);
	}
	maxp[u]=max(maxp[u],total-siz[u]);
	if(!rt||maxp[u]<maxp[rt]){
		rt=u;	
	}
}
struct Data{
	int dis,u,z,p;
	friend bool operator < (const Data &a,const Data &b){
		return a.z>b.z;	
	}
};
vector<Data> A;
void get_dis(int u,int fa,int dis){
	A.push_back({dis,u,R[u],inv[R[u]-L[u]+1]});
	if(L[u]>1)A.push_back({dis,u,L[u]-1,mod-inv[R[u]-L[u]+1]});
	for(auto v:G[u]){
		if(v==fa||vis[v])continue;
		get_dis(v,u,dis+1);
	}
}
void calc(int u,int W,int opt){
	A.clear();
	get_dis(u,0,W);
	sort(A.begin(),A.end());
	int tot=0,sw1=0,sw2=0;
	for(auto [d,u,z,w]:A){
		tot=(tot+(1LL*sw1*d+sw2)%mod*w%mod*z)%mod;
		sw1=(sw1+w)%mod;
		sw2=(sw2+1LL*w*d)%mod;
	}
	ans=(ans+(opt==1?tot:mod-tot))%mod;
}
void Solve(int u){
	vis[u]=1;
	calc(u,0,1);
	for(auto v:G[u]){
		if(vis[v])continue;
		calc(v,1,-1);	
	}
	for(auto v:G[u]){
		if(vis[v])continue;
		rt=0;
		get_root(v,u,siz[v]);
		Solve(rt);	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	inv[1]=1;
	for(int i=2;i<=100000;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	for(int i=1;i<=n;++i){
		cin>>L[i]>>R[i];
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	get_root(1,0,n);
	Solve(rt);
	for(int i=1;i<=n;++i){
		ans=1LL*ans*(R[i]-L[i]+1)%mod;
	}
	cout<<ans<<'\n';
	return 0;
}