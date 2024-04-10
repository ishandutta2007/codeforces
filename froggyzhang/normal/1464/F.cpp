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
int n,Q,dfn[N],siz[N],top[N],son[N],dep[N],f[N],num,id[N];
vector<int> G[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int topf){
	dfn[u]=++num;
	id[num]=u;
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
inline int Dis(int x,int y){
	if(!x||!y)return 0;
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
class BIT{
private:
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
	inline int Query(int l,int r){
		return Ask(r)-Ask(l-1);
	}
}B;
struct Path{
	int x,y;
	Path(int _x=0,int _y=0){x=_x,y=_y;}
	friend bool operator < (const Path &a,const Path &b){
		return Dis(a.x,a.y)<Dis(b.x,b.y);
	}
	friend Path operator + (const Path &a,const Path &b){
		if(!a.x)return b;
		if(!b.x)return a;
		return max(max(max(a,b),max(Path(a.x,b.x),Path(a.y,b.x))),max(Path(a.x,b.y),Path(a.y,b.y)));
	}
};
class Segment_Tree{
private:
	struct node{
		Path p;
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
public:
	inline void update(int i){
		tree[i].p=tree[ls].p+tree[rs].p;
	}
	inline void Change(int i,int L,int R,int x){
		if(L==R){
			tree[i].p=tree[i].p.x?Path(0,0):Path(id[L],id[L]);
			return;
		}
		int mid=(L+R)>>1;
		x<=mid?Change(ls,L,mid,x):Change(rs,mid+1,R,x);
		update(i);
	}
	Path Query(int i,int L,int R,int l,int r){
		if(L>=l&&R<=r)return tree[i].p;
		int mid=(L+R)>>1;
		Path ans(0,0);
		if(l<=mid)ans=ans+Query(ls,L,mid,l,r);
		if(r>mid)ans=ans+Query(rs,mid+1,R,l,r);
		return ans;
	}
}T;
struct cmp{
	bool operator () (int x,int y)const{
		return dep[x]==dep[y]?x<y:dep[x]>dep[y];
	}	
};
multiset<int,cmp> s;
inline int Get(int u,int d){
	while(d>dep[u]-dep[top[u]]){
		assert(u);
		if(top[u]==1)return 1;
		d-=dep[u]-dep[f[top[u]]];
		u=f[top[u]];
	}
	return id[dfn[u]-d];
}
bool Solve(int d){
	int u=*s.begin();
	int v=Get(u,d);
	int w=Get(v,d);
	if(B.Query(dfn[w],dfn[w]+siz[w]-1)!=s.size())return false;
	Path t=T.Query(1,1,n,dfn[w],dfn[w]+siz[w]-1);
	return max(Dis(v,t.x),Dis(v,t.y))<=d;
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
	while(Q--){
		int opt=read();
		if(opt==1){
			int u=read(),v=read();
			int lca=LCA(u,v);
			if(s.find(lca)==s.end())T.Change(1,1,n,dfn[lca]);
			s.insert(lca);
			B.Add(dfn[u],1),B.Add(dfn[v],1),B.Add(dfn[lca],-1);
		}
		else if(opt==2){
			int u=read(),v=read();
			int lca=LCA(u,v);
			s.erase(s.find(lca));
			if(s.find(lca)==s.end())T.Change(1,1,n,dfn[lca]);
			B.Add(dfn[u],-1),B.Add(dfn[v],-1),B.Add(dfn[lca],1);
		}
		else{
			int d=read();
			printf(Solve(d)?"Yes\n":"No\n");
		}
	}
	return 0;
}