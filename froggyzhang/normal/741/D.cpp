#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,f[N],siz[N],son[N],c[N],dep[N];
vector<pair<int,int> > G[N];
void dfs1(int u){
	siz[u]=1;
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		c[v]=c[u]^(1<<w);
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
int mx[1<<23],ans[N];
void work(int &tp,int u){
	tp=max(tp,dep[u]+mx[c[u]]);
	for(int i=0;i<23;++i){
		tp=max(tp,dep[u]+mx[c[u]^(1<<i)]);
	}
}
void dfs3(int u,int &k){
	work(k,u);
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		dfs3(v,k);
	}
}
void dfs4(int u){
	mx[c[u]]=max(mx[c[u]],dep[u]);
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		dfs4(v);
	}
}
void dfs5(int u){
	mx[c[u]]=-inf;
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		dfs5(v);
	}
}
void dfs2(int u,bool keep){
	for(auto [v,w]:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,0);
	}
	if(son[u])dfs2(son[u],1);
	mx[c[u]]=max(mx[c[u]],dep[u]);
	for(auto [v,w]:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs3(v,ans[u]);
		dfs4(v);
	}
	work(ans[u],u);
	ans[u]-=2*dep[u];
	ans[u]=max(ans[u],0);
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		ans[u]=max(ans[u],ans[v]);
	}
	if(!keep){
		dfs5(u);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=2;i<=n;++i){
		int fa;
		char c;
		cin>>fa>>c;
		G[fa].emplace_back(i,c-'a');
		G[i].emplace_back(fa,c-'a');
	}
	memset(mx,~0x3f,sizeof(mx));
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}