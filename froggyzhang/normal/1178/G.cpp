#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,Q,f[N];
int dfn[N],siz[N],num,id[N];
ll a[N],b[N];
vector<int> G[N];
void dfs(int u){
	dfn[u]=++num;
	id[num]=u;
	siz[u]=1;
	for(auto v:G[u]){
		b[v]+=b[u];
		a[v]+=a[u];
		dfs(v);
		siz[u]+=siz[v];
	}
}
struct Line{
	ll k,b;
	Line(ll _k=0,ll _b=0){k=_k,b=_b;}
};
class Segment_Tree{
	struct node{
		Line p;
		ll t,add;
		node(){t=add=0;}
		inline void Add(int d){
			t-=d,add+=d;
			p.b+=p.k*d;
		}
	}tree[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		tree[u].t=min(tree[ls].t,tree[rs].t);
		Line x=tree[ls].p,y=tree[rs].p;
		if(x.b<y.b||(x.b==y.b&&x.k<y.k))swap(x,y);
		tree[u].p=x;
		if(x.k<y.k)tree[u].t=min(tree[u].t,(x.b-y.b+y.k-x.k-1)/(y.k-x.k));
	}
	inline void pushdown(int u){
		if(tree[u].add){
			tree[ls].Add(tree[u].add);
			tree[rs].Add(tree[u].add);
			tree[u].add=0;
		}
	}
public:
	void build(int u,int L,int R,int op){
		if(L==R){
			tree[u].p=Line(b[id[L]]*op,1LL*a[id[L]]*b[id[L]]*op);
			tree[u].t=inf;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid,op),build(rs,mid+1,R,op);
		update(u);
	}
	void Plus(int u,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r&&tree[u].t>d){
			tree[u].Add(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Plus(ls,L,mid,l,r,d);
		if(r>mid)Plus(rs,mid+1,R,l,r,d);
		update(u);
	}
	ll Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return tree[u].p.b;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		ll mx=-inf;
		if(l<=mid)mx=max(mx,Query(ls,L,mid,l,r));
		if(r>mid)mx=max(mx,Query(rs,mid+1,R,l,r));
		return mx;
	}
}T1,T2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=2;i<=n;++i){
		cin>>f[i];
		G[f[i]].push_back(i);
	}
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	dfs(1);
	T1.build(1,1,n,1);
	T2.build(1,1,n,-1);
	while(Q--){
		int opt,u,x;
		cin>>opt>>u;
		if(opt==1){
			cin>>x;
			T1.Plus(1,1,n,dfn[u],dfn[u]+siz[u]-1,x);
			T2.Plus(1,1,n,dfn[u],dfn[u]+siz[u]-1,x);
		}
		else{
			cout<<max(T1.Query(1,1,n,dfn[u],dfn[u]+siz[u]-1),T2.Query(1,1,n,dfn[u],dfn[u]+siz[u]-1))<<'\n';			
		}
	}
	return 0;
}