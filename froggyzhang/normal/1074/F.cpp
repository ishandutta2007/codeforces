#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,Q;
int son[N],siz[N],f[N],dep[N],top[N];
int dfn[N],id[N],num;
set<pair<int,int> > vis;
vector<int> G[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	dfn[u]=++num;
	id[num]=u;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
struct Segment_Tree{
	struct node{
		int l,r,cov,sum;
	}tree[N<<3];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		if(tree[i].cov){
			tree[i].sum=tree[i].r-tree[i].l+1;
		}	
		else{
			tree[i].sum=tree[ls].sum+tree[rs].sum;
		}
	}
	void build(int i,int l,int r){
		tree[i].l=l;
		tree[i].r=r;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	void Change(int i,int l,int r,int x){
		if(l>r)return;
		if(tree[i].l>=l&&tree[i].r<=r){
			tree[i].cov+=x;
			update(i);
			return;
		}
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid){
			Change(ls,l,r,x);
		}
		if(r>mid){
			Change(rs,l,r,x);
		}
		update(i);
	}
}T;
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];	
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline int get_son(int x,int y){
	while(top[x]^top[y]){
		if(f[top[x]]==y)return top[x];
		x=f[top[x]];			
	}	
	return son[y];
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	T.build(1,1,n);
	while(Q--){
		int u=read(),v=read();
		if(dfn[u]>dfn[v])swap(u,v);
		int lca=LCA(u,v);
		int w;
		if(vis.count(make_pair(u,v)))w=-1,vis.erase(make_pair(u,v));
		else w=1,vis.insert(make_pair(u,v));
		if(lca==u){
			int t=get_son(v,u);
			T.Change(1,dfn[t],dfn[v]-1,w);
			T.Change(1,dfn[v]+siz[v],dfn[t]+siz[t]-1,w);
		}
		else{
			T.Change(1,1,dfn[u]-1,w);
			T.Change(1,dfn[u]+siz[u],dfn[v]-1,w);
			T.Change(1,dfn[v]+siz[v],n,w);
		}
		printf("%d\n",n-T.tree[1].sum);
	}
	return 0;
}