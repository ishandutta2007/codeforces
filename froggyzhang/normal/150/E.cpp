#include<bits/stdc++.h>
using namespace std;
#define N 100020
typedef long long ll;
const int inf=0x3f3f3f3f;
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
int n,L,R,dep[N],f[N],mxdep[N],son[N],len[N],dfn[N],num;
int pos[N];
struct Segment_Tree{
	struct node{
		pair<int,int> mx;
		int l,r;
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	inline void update(int i){
		tree[i].mx=max(tree[ls].mx,tree[rs].mx);
	}
	void build(int i,int l,int r){
		tree[i].l=l;
		tree[i].r=r;
		tree[i].mx=make_pair(-inf,r);
		if(l==r){
			return;	
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	void Change(int i,int p,pair<int,int> d){
		if(tree[i].l==tree[i].r){
			tree[i].mx=d;
			return;
		}
		int mid=(tree[i].l+tree[i].r)>>1;
		if(p<=mid)Change(ls,p,d);
		else Change(rs,p,d);
		update(i);
	}
	pair<int,int> Query(int i,int l,int r){
		if(l>r)return make_pair(-inf,1);
		if(tree[i].l>=l&&tree[i].r<=r){
			return tree[i].mx;
		}
		pair<int,int> mx=make_pair(-inf,1);
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid)mx=max(mx,Query(ls,l,r));
		if(r>mid)mx=max(mx,Query(rs,l,r));
		return mx;
	}
}T;
vector<pair<int,int> > G[N];
pair<int,int> _tmp[N<<1],*now=_tmp;
pair<int,int> *dp[N];
int mx,val[N];
inline void Assign(int u){
	dp[u]=now,now+=len[u];	
}
void init1(int u,int fa){
	f[u]=fa;
	dep[u]=dep[fa]+1;
	mxdep[u]=dep[u];
	for(auto [v,w]:G[u]){
		if(v==fa)continue;
		init1(v,u);
		if(mxdep[v]>mxdep[u]){
			mxdep[u]=mxdep[v];
			son[u]=v;
			val[u]=w;
		}
	}
	len[u]=mxdep[u]-dep[u]+1;
}
void init2(int u){
	dfn[u]=++num;
	pos[num]=u;
	if(son[u]){
		dp[son[u]]=dp[u]+1;
		init2(son[u]);
	}
	for(auto [v,w]:G[u]){
		if(v==f[u]||v==son[u])continue;
		Assign(v);
		init2(v);
	}
}
pair<int,int> A;
int g[N];
void dfs(int u,int x){
	if(son[u]){
		dfs(son[u],x);
		g[u]=g[son[u]]+(val[u]>=x?1:-1);
		dp[u][0]=make_pair(-g[u],u);
	} 
	else{
		dp[u][0].first=g[u]=0;
		dp[u][0].second=u;
	}
	T.Change(1,dfn[u],dp[u][0]);
	auto [nw,k]=T.Query(1,dfn[u]+L,dfn[u]+min(R,len[u]-1));
	nw+=g[u];
	if(nw>mx){
		mx=nw;
		A=make_pair(u,k);
	}
	for(auto [v,w]:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs(v,x);
		for(int i=0;i<len[v];++i){
			auto [nw,k]=T.Query(1,dfn[u]+max(0,L-i-1),dfn[u]+min(R-i-1,len[u]-1));
			nw+=(w>=x?1:-1)+g[u]+g[v]+dp[v][i].first;
			if(nw>mx){
				mx=nw;
				A=make_pair(k,dp[v][i].second);
			}
		}
		for(int i=1;i<=len[v];++i){
			pair<int,int> nw=make_pair(dp[v][i-1].first+(w>=x?1:-1)-g[u]+g[v],dp[v][i-1].second);
			if(nw>dp[u][i]){
				dp[u][i]=nw;
				T.Change(1,dfn[u]+i,nw);
			}
		}
	}
}
int check(int x){
	mx=-inf;
	T.build(1,1,n);
	dfs(1,x);
	return mx>=0;
}
int main(){
	n=read();
	L=read(),R=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	init1(1,0);
	Assign(1);
	init2(1);
	int l=0,r=1e9+1;
	pair<int,int> ans;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=A,l=mid+1;
		}
		else{
			r=mid;
		}
	}
	printf("%d %d\n",ans.first,ans.second);
	return 0;
}