#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
const int mod=998244353;
int n,m,f[N],a[N],dep[N],top[N],son[N],siz[N],dfn[N],num,s[N],t[N];
vector<int> G[N],c[N];
vector<pair<int,int> > E;
struct Union_Set{
	int f[N];
public:
	void init(int n){for(int i=1;i<=n;++i)f[i]=i;}
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
	inline void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;
	}
}S;
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;	
		dep[v]=dep[u]+1;
		dfs1(v);
		if(siz[v]>siz[son[u]])son[u]=v;
		siz[u]+=siz[v];
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
inline int LCA(int u,int v){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=f[top[u]];		
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
void dfs3(int u){
	for(auto v:G[u]){
		if(v==f[u])continue;
		dfs3(v);
		s[u]+=s[v];	
		t[u]+=t[v];
	}
	if(t[u]>2){cout<<0<<'\n';exit(0);}
	if(s[u])S.Merge(f[u],u),a[f[u]]=a[u];
}
int dp[N][2];
void dfs4(int u,int fa){
	static int vis[N];
	int A=1,B=0;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs4(v,u);	
		B=(1LL*B*(dp[v][1]+dp[v][0])+1LL*A*dp[v][1])%mod;
		A=1LL*A*(dp[v][1]+dp[v][0])%mod;
	}
	vis[a[u]]=1;
	if(a[u])dp[u][1]=A;
	else dp[u][1]=B,dp[u][0]=A;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		c[a[i]].push_back(i);
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		E.emplace_back(u,v);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=m;++i){
		sort(c[i].begin(),c[i].end(),[&](int i,int j){return dfn[i]<dfn[j];});
		for(int j=0;j<(int)c[i].size();++j){
			int u=c[i][j],v=c[i][(j+1)%c[i].size()];
			++s[u],++s[v],++t[u],++t[v];
			int lca=LCA(u,v);
			s[lca]-=2;
			t[lca]-=2;
			if(j==(int)c[i].size()-1)t[lca]+=2,t[f[lca]]-=2;
		}
	}
	S.init(n);
	dfs3(1);
	for(int i=1;i<=n;++i)G[i].clear();
	for(auto [u,v]:E){
		if((u=S.getf(u))==(v=S.getf(v)))continue;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs4(1,0);
	cout<<dp[1][1]<<'\n';
	return 0;
}