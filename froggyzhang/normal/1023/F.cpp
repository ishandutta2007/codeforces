#include<bits/stdc++.h>
using namespace std;
#define N 500010
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> G[N];
ll ans;
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
int dep[N],n,m1,m2,f[N],ID[N],ff[N][20];
struct Link{
	int x,y,w,id,hav;
}E[N<<1];
inline int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;--i){
		if(dep[ff[u][i]]>=dep[v])u=ff[u][i];
	}
	if(u==v)return u;
	for(int i=19;i>=0;--i){
		if(ff[u][i]^ff[v][i])u=ff[u][i],v=ff[v][i];
	}
	return f[u];
}
void dfs(int u){
	ff[u][0]=f[u];
	for(int i=1;i<=19;++i){
		ff[u][i]=ff[ff[u][i-1]][i-1];
	}
	for(auto [v,id]:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		ID[v]=id;
		dep[v]=dep[u]+1;
		dfs(v);
	}
}
void Mer(int u,int lim,int w){
	while(dep[u]>dep[lim]){
		S.f[u]=f[u];
		if(ID[u]<=m1)ans+=w;
		u=S.getf(u);
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;++i){
		cin>>E[i].x>>E[i].y;
		E[i].id=i;	
	}
	for(int i=m1+1;i<=m1+m2;++i){
		cin>>E[i].x>>E[i].y>>E[i].w;
		E[i].id=i;
	}
	sort(E+1,E+m1+m2,[&](Link a,Link b){return a.w<b.w;});
	S.init(n);
	for(int i=1;i<=m1+m2;++i){
		int fx=S.getf(E[i].x),fy=S.getf(E[i].y);
		if(fx==fy)continue;
		E[i].hav=1;
		S.f[fy]=fx;
		G[E[i].y].emplace_back(E[i].x,E[i].id);
		G[E[i].x].emplace_back(E[i].y,E[i].id);
	}
	dfs(1);
	S.init(n);
	for(int i=1;i<=m1+m2;++i){
		if(E[i].hav)continue;
		int u=E[i].x,v=E[i].y;
		int lca=LCA(u,v);
		Mer(S.getf(u),lca,E[i].w);
		Mer(S.getf(v),lca,E[i].w);
	}
	for(int i=2;i<=n;++i){
		if(S.getf(i)==i&&ID[i]<=m1){
			cout<<-1<<'\n';
			return 0;
		}	
	}
	cout<<ans<<'\n';
	return 0;
}