#include<bits/stdc++.h>
using namespace std;
#define N 300010
typedef long long ll;
int n,dep[N],son[N],siz[N],f[N],ans[N],top[N];
vector<int> G[N],c[N];
void dfs1(int u){
	siz[u]=1;
	ans[1]=max(ans[1],dep[u]);
	c[dep[u]].push_back(u);
	for(auto v:G[u]){
		if(f[u]==v)continue;
		dep[v]=dep[u]+1,f[v]=u;
		dfs1(v);
		siz[u]=siz[v]+1;
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
inline int LCA(int u,int v){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=f[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
inline int Dis(int u,int v){
	return dep[u]+dep[v]-(dep[LCA(u,v)]<<1);
}
int X,Y,D;
inline void Insert(int u){
	if(!X){X=u;return;}
	if(!Y){Y=u,D=Dis(X,Y);return;}
	int d1=Dis(u,X),d2=Dis(u,Y);
	if(d1>D&&d1>=d2){
		Y=u,D=d1;
	}
	if(d2>D&&d2>d1){
		X=u,D=d2;
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)dep[i]=son[i]=top[i]=f[i]=0,G[i].clear(),c[i].clear();
	ans[1]=0;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	X=Y=D=0;
	for(int i=2;i<=n;++i)ans[i]=ans[1];
	for(int i=n;i>=1;--i){
		for(auto u:c[i])Insert(u);
		int jb=i-1-(D+1)/2;
		if(jb>=1)ans[jb]=i-1;
	}
	for(int i=n-1;i>=1;--i)ans[i]=min(ans[i],ans[i+1]);
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}