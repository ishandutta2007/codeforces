#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,h[N],rt,gmx[N],f[N];
vector<int> G[N],H[N];
int ban[N];
void dfs1(int u){
	gmx[u]=h[u];
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dfs1(v);
		gmx[u]=max(gmx[u],gmx[v]);
		if(gmx[v]>=h[u]){
			ban[u]=1;
		}
	}
}
ll ans=0;
void dfs2(int u,int zz){
	if(!ban[u]){
		H[zz].push_back(u);
		zz=u;
		ans+=h[u];
	}
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dfs2(v,zz);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>h[i];
	}
	rt=max_element(h+1,h+n+1)-h;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(rt);
	ban[rt]=1;
	dfs2(rt,rt);
	ans+=2*h[rt];
	vector<int> A;
	for(auto v:G[rt]){
		A.push_back(gmx[v]);
	}
	sort(A.begin(),A.end(),greater<int>());
	if(A.size()>=1)ans-=A[0];
	if(A.size()>=2)ans-=A[1];
	for(int i=1;i<=n;++i){
		sort(H[i].begin(),H[i].end(),[&](int i,int j){return h[i]>h[j];});
	}
	for(int u=1;u<=n;++u){
		if(!ban[u]&&u^rt){
			if(!H[u].empty())ans-=h[H[u][0]];
		}
	}
	cout<<ans<<'\n';
	return 0;
}