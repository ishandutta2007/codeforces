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
int n,Q,rt,num;
int dfn[N],siz[N];
int top[N],f[N],son[N],dep[N],w[N];
vector<int> G[N];
void dfs1(int u){
	dep[u]=dep[f[u]]+1;
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	dfn[u]=++num;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
inline bool In(int x,int y){
	return dfn[y]>=dfn[x]&&dfn[y]<=dfn[x]+siz[x]-1;
}
inline int Find(int x,int y){
	while(top[x]^top[y]){
		if(f[top[x]]==y)return top[x];
		x=f[top[x]];
	}
	return son[y];	
}
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];	
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline int get_LCA(int x,int y){
	int z1=LCA(x,y),z2=LCA(rt,x),z3=LCA(rt,y);
	return dep[z1]>=dep[z2]?(dep[z1]>=dep[z3]?z1:z3):(dep[z2]>=dep[z3]?z2:z3);
}
struct Seg{
	struct BIT{
		ll b[N];
		inline int lowbit(int x){return x&(-x);}
		inline void Add(int x,ll d){
			while(x<=n)b[x]+=d,x+=lowbit(x);
		}
		inline ll Ask(int x){
			ll ans=0;
			while(x)ans+=b[x],x-=lowbit(x);
			return ans;
		}
	}B[2];
	void Add(int l,int r,ll w){
		B[0].Add(l,w),B[0].Add(r+1,-w);
		B[1].Add(l,w*l),B[1].Add(r+1,-w*(r+1));
	}
	ll Ask(int l,int r){
		ll ans=0;
		ans+=(r+1)*B[0].Ask(r)-l*B[0].Ask(l-1);
		ans-=B[1].Ask(r)-B[1].Ask(l-1);
		return ans;
	}
}D;
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		w[i]=read();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	rt=1;
	for(int i=1;i<=n;++i){
		D.Add(dfn[i],dfn[i],w[i]);
	}
	while(Q--){
		int opt=read();
		if(opt==1){
			rt=read();
		}
		else if(opt==2){	
			int x=read(),y=read(),w=read();
			int u=get_LCA(x,y);
			if(u==rt)D.Add(1,n,w);
			else if(In(u,rt)){
				u=Find(rt,u);
				D.Add(1,n,w);
				D.Add(dfn[u],dfn[u]+siz[u]-1,-w);
			}
			else{
				D.Add(dfn[u],dfn[u]+siz[u]-1,w);
			}
		}
		else{
			int u=read();
			if(u==rt){
				printf("%lld\n",D.Ask(1,n));
			}
			else if(In(u,rt)){
				u=Find(rt,u);
				printf("%lld\n",D.Ask(1,n)-D.Ask(dfn[u],dfn[u]+siz[u]-1));
			}
			else{
				printf("%lld\n",D.Ask(dfn[u],dfn[u]+siz[u]-1));
			}
		}
	}
	return 0;
}