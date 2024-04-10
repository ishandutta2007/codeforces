#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11,M=22;
vector<int> e[N];
int fa[N];
int n;
int dep[N];
int sz[N],tp[N],sc[N];
int id[N], rd[N], dfs_cnt;
void dfs(int x){
	sz[x]=1;
	int v=0;
	for(int y:e[x]){
		if(y==fa[x])continue;
		dep[y]=dep[x]+1;
		fa[y]=x;
		dfs(y);
		sz[x]+=sz[y];
		if(!v || sz[y]>sz[v]) v=y;
	}
	sc[x]=v;
}
void dfs2(int x,int t){
	id[x]=++dfs_cnt;
	rd[dfs_cnt]=x;
	tp[x]=t;
	if(sc[x]) dfs2(sc[x],t);
	for(int y:e[x]){
		if(y==fa[x]||y==sc[x]) continue;
		dfs2(y,y);
	}
}
template<class T>
struct BIT{
	T c[N];
	T operator[](int x){
		T r=0;
		for(;x;x-=x&-x) r+=c[x];
		return r;
	}
	void add(int x,T v){
		for(;x<=n;x+=x&-x) c[x]+=v;
	}
};
BIT<int> f[M];
int g[N][M];
int query(int v){
	int ret=0;
	for(int i=0;i<M&&v;++i,v=fa[v])
		ret+=f[i][id[v]]+g[v][i];
	return ret;
}
void update(int u,int v,int k,int d){
	/*int l=lca(u,v);
	for(;u!=l;u=fa[u]) f[u][d]+=k;
	for(;v!=l;v=fa[v]) f[v][d]+=k;*/
	for(;tp[u]!=tp[v];){
		if(dep[tp[u]]<dep[tp[v]])swap(u,v);
		int t=tp[u];
		f[d].add(id[t], k);
		f[d].add(id[u]+1, -k);
		u=fa[t];
	}
	if(dep[u]>dep[v])swap(u,v);
	f[d].add(id[u]+1,k);
	f[d].add(id[v]+1,-k);
	int l=u;
	for(;d&&l>1;--d,l=fa[l]){
		g[l][d]+=k;
		g[l][d-1]+=k;
	}
	for(int i=0;i<=d;++i) g[l][i]+=k;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	For(i,1,n){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1);
	dfs2(1,1);
	int Q;
	cin>>Q;
	while(Q--){
		int op;
		cin>>op;
		if(op==1){
			int v;
			cin>>v;
			cout<<query(v)<<"\n";
		}else{
			int u,v,k,d;
			cin>>u>>v>>k>>d;
			update(u,v,k,d);
		}
	}
}