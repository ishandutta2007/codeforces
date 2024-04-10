#include<bits/stdc++.h>
using namespace std;
#define N 400040
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
int T,n,m,ins[N],dfn[N],low[N],num,tot,col[N],sz[N],p[N],ok[N],d[N],dp[N];
vector<int> G[N];
vector<pair<int,int> > E;
void Tarjan(int u){
	static int st[N],top;
	dfn[u]=low[u]=++num;
	st[++top]=u;
	ins[u]=1;
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]){
			low[u]=min(low[u],dfn[v]);
		}		
	}
	if(low[u]==dfn[u]){
		++tot;
		int t=0;
		while(t^u){
			t=st[top--];
			ins[t]=0;
			col[t]=tot;
			++sz[tot];
			if(p[t])++sz[tot];
		}
	}
}
void dfs(int u){
	ok[u]=1;
	for(auto v:G[u]){
		if(ok[v])continue;
		dfs(v);
	}
}
queue<int> q;
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		G[i].clear();
		dfn[i]=low[i]=col[i]=ins[i]=sz[i]=p[i]=ok[i]=d[i]=dp[i]=0;
	}
	E.clear();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		if(u==v)p[u]=1;
		E.emplace_back(u,v);
	}
	num=tot=0;
	for(int i=1;i<=n;++i){
		if(!dfn[i])Tarjan(i);
	}
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(auto [u,v]:E){
		if(col[u]^col[v])G[col[u]].push_back(col[v]);
	}
	dfs(col[1]);
	for(int u=1;u<=tot;++u){
		if(!ok[u])continue;
		for(auto v:G[u])++d[v];
	}
	q.push(col[1]);
	dp[col[1]]=1;
	while(!q.empty()){
		int u=q.front();
		if(sz[u]>=2)dp[u]=-1;
		q.pop();
		for(auto v:G[u]){
			if(!ok[v])continue;
			if(!--d[v])q.push(v);
			if(~dp[u]&&~dp[v])dp[v]=min(2,dp[v]+dp[u]);
			else dp[v]=-1;
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d ",dp[col[i]]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}