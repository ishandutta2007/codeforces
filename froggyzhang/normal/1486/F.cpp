#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,x[N],y[N],tx[N],ty[N],lca[N];
vector<int> G[N];
int f[N],top[N],son[N],siz[N],dep[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
		siz[u]+=siz[v];	
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
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline int Get(int x,int y){
	if(x==y)return 0;
	while(top[x]^top[y]){
		if(f[top[x]]==y)return top[x];
		x=f[top[x]];
	}
	return son[y];	
}
vector<int> vec[N];
ll ans;
map<int,int> mp1;
map<pair<int,int>,int> mp2;
int s1[N],s2[N];
void dfs3(int u){
	ans+=1LL*vec[u].size()*((int)vec[u].size()-1)/2;
	mp1.clear();
	mp2.clear();
	for(auto z:vec[u]){
		if(tx[z])++mp1[tx[z]];
		if(ty[z])++mp1[ty[z]];
		if(tx[z]&&ty[z])++mp2[tx[z]<=ty[z]?make_pair(tx[z],ty[z]):make_pair(ty[z],tx[z])];
	}
	for(auto [gg,sz]:mp1){
		ans-=1LL*sz*(sz-1)/2;
	}
	for(auto [gg,sz]:mp2){
		ans+=1LL*sz*(sz-1)/2;
	}
	for(auto v:G[u]){
		if(v==f[u])continue;
		dfs3(v);
		s1[u]+=s1[v];
		s2[u]+=s2[v];
	}
	for(auto z:vec[u]){
		ans+=s1[u]-s2[tx[z]]-s2[ty[z]];
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	m=read();
	for(int i=1;i<=m;++i){
		x[i]=read(),y[i]=read();
		lca[i]=LCA(x[i],y[i]);
		vec[lca[i]].push_back(i);
		tx[i]=Get(x[i],lca[i]);
		ty[i]=Get(y[i],lca[i]);
		if(tx[i])++s1[x[i]],--s1[lca[i]],++s2[x[i]],--s2[tx[i]];
		if(ty[i])++s1[y[i]],--s1[lca[i]],++s2[y[i]],--s2[ty[i]];
	}
	dfs3(1);
	printf("%lld\n",ans);
	return 0;
}