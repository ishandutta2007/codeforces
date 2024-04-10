#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
const ll inf=1e18;
int n,Q,leaf[N],dfn[N],id[N],siz[N],num,f[N];
ll dis[N],ans[N];
struct Query{
	int l,r,id;	
};
vector<Query> q[N];
vector<pair<int,int> > G[N];
class Segment_Tree{
	struct node{
		ll mn,add;
		inline void Add(ll d){
			mn+=d,add+=d;
		}	
	}tree[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void pushdown(int u){
		if(tree[u].add){
			tree[ls].Add(tree[u].add);
			tree[rs].Add(tree[u].add);
			tree[u].add=0;
		}
	}
	inline void update(int u){
		tree[u].mn=min(tree[ls].mn,tree[rs].mn);
	}
public:
	void build(int u,int L,int R){
		if(L==R){
			tree[u].mn=leaf[id[L]]?dis[id[L]]:inf;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void Plus(int u,int L,int R,int l,int r,ll d){
		if(L>=l&&R<=r)return tree[u].Add(d);
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Plus(ls,L,mid,l,r,d);
		if(r>mid)Plus(rs,mid+1,R,l,r,d);
		update(u);
	}
	ll Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return tree[u].mn;
		int mid=(L+R)>>1;
		pushdown(u);
		ll mn=inf;
		if(l<=mid)mn=min(mn,Query(ls,L,mid,l,r));
		if(r>mid)mn=min(mn,Query(rs,mid+1,R,l,r));
		return mn;
	}	
}T;
void dfs1(int u){
	dfn[u]=++num;
	siz[u]=1;
	id[num]=u;
	if(u^1&&G[u].empty()){
		leaf[u]=1;
	}
	for(auto [v,w]:G[u]){
		dis[v]=dis[u]+w;
		dfs1(v);
		siz[u]+=siz[v];
	}
}
void dfs2(int u){
	T.Plus(1,1,n,dfn[u],dfn[u]+siz[u]-1,-2*(dis[u]-dis[f[u]]));
	for(auto t:q[u]){
		ans[t.id]=T.Query(1,1,n,t.l,t.r)+dis[u];	
	}
	for(auto [v,w]:G[u]){
		dfs2(v);	
	}
	T.Plus(1,1,n,dfn[u],dfn[u]+siz[u]-1,2*(dis[u]-dis[f[u]]));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=2,w;i<=n;++i){
		cin>>f[i]>>w;
		G[f[i]].emplace_back(i,w);
	}
	for(int i=1;i<=n;++i){
		sort(G[i].begin(),G[i].end());	
	}
	dfs1(1);
	for(int i=1;i<=Q;++i){
		int v,l,r;
		cin>>v>>l>>r;
		q[v].push_back({l,r,i});	
	}
	T.build(1,1,n);
	dfs2(1);
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}