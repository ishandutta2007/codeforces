#include<bits/stdc++.h>
using namespace std;
#define N 600030
typedef long long ll;
int n,Q,W[N];
struct Link{
	int x,y,w;
}E[N];
vector<int> G[N];
class Union_Set{
public:
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
}S;
int top[N],f[N],siz[N],dep[N],son[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u,dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
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
	if(!u||!v)return u|v;
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=f[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
class Segment_tree{
	int Len;
	struct node{
		int nd,cov,lca;
		inline void Cov(int w){
			if(w==1)lca=nd;
			else lca=0;
			cov=w;	
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].lca=LCA(t[ls].lca,t[rs].lca);
	}
	void build(int u,int L,int R){
		if(L==R){
			t[u].nd=L;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		t[u].nd=LCA(t[ls].nd,t[rs].nd);
	}
	inline void pushdown(int u){
		if(t[u].cov){
			t[ls].Cov(t[u].cov);
			t[rs].Cov(t[u].cov);
			t[u].cov=0;
		}
	}
	void _cover(int u,int L,int R,int l,int r,int opt){
		if(L>=l&&R<=r){
			t[u].Cov(opt);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)_cover(ls,L,mid,l,r,opt);
		if(r>mid)_cover(rs,mid+1,R,l,r,opt);
		update(u);
	}
public:
	void init(int n){
		Len=n;
		build(1,1,n);
	}
	void Change(int l,int r,int w){
		_cover(1,1,Len,l,r,w);
	}
	int Ask(){
		return t[1].lca;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<n;++i){
		cin>>E[i].x>>E[i].y>>E[i].w;
	}
	sort(E+1,E+n,[&](Link a,Link b){return a.w<b.w;});
	int tot=n;
	S.init(n<<1);
	for(int i=1;i<=n;++i)W[i]=-1;
	for(int i=1;i<n;++i){
		int fx=S.getf(E[i].x),fy=S.getf(E[i].y);
		if(fx==fy)continue;
		++tot;
		G[tot].push_back(fx),G[tot].push_back(fy);
		W[tot]=E[i].w;
		S.f[fx]=S.f[fy]=tot;
	}
	dfs1(tot);
	dfs2(tot,tot);
	T.init(n);
	while(Q--){
		int opt,l,r,x;
		cin>>opt;
		if(opt==1||opt==2){
			cin>>l>>r;
			T.Change(l,r,opt==1?1:-1);
		}
		else{
			cin>>x;
			cout<<W[LCA(T.Ask(),x)]<<'\n';
		}
	}
	return 0;
}