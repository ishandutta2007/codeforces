#include<bits/stdc++.h>
using namespace std;
#define N 400040
typedef long long ll;
typedef pair<int,int> pii;
int n,Q,a[N],w[N],rt;
vector<int> G[N];
struct Edge{
	int x,y,c,t;	
}E[N];
pii ans[N];
struct Query{
	int z,u,id;	
}q[N];
int f[N],top[N],son[N],dep[N],siz[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
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
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==son[u])continue;
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
struct Union_Set{
public:
	int f[N];
	pii g[N];
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
			g[i]=make_pair(a[i],i);
		}
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(g[fx].first<g[fy].first)swap(fx,fy);
		f[fy]=fx;
		if(g[fx].first==g[fy].first){
			g[fx].second=LCA(g[fx].second,g[fy].second);
		}	
	}
}S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	for(int i=1;i<n;++i){
		cin>>E[i].x>>E[i].y>>E[i].c>>E[i].t;
	}
	sort(E+1,E+n,[&](Edge a,Edge b){return a.t<b.t;});
	rt=n;
	S.init(2*n);
	for(int i=1;i<n;++i){
		int fx=S.getf(E[i].x),fy=S.getf(E[i].y);
		++rt;
		w[rt]=E[i].t;
		S.f[fx]=S.f[fy]=rt;
		G[rt].push_back(fx),G[rt].push_back(fy);
	}
	dfs1(rt);
	dfs2(rt,rt);
	S.init(n);
	for(int i=1;i<=Q;++i){
		cin>>q[i].z>>q[i].u;
		q[i].id=i;
	}
	sort(q+1,q+Q+1,[&](Query a,Query b){return a.z>b.z;});
	sort(E+1,E+n,[&](Edge a,Edge b){return a.c>b.c;});
	for(int i=1,j=1;i<=Q;++i){
		while(j<n&&E[j].c>=q[i].z){
			S.Merge(E[j].x,E[j].y);
			++j;
		}
		auto [val,u]=S.g[S.getf(q[i].u)];
		ans[q[i].id]=make_pair(val,w[LCA(u,q[i].u)]);
	}
	for(int i=1;i<=Q;++i){
		cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}
	return 0;
}